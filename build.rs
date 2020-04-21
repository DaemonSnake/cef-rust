use std::env::var as env_var;
use std::fs::create_dir_all;
use std::path::PathBuf;

use reqwest::blocking::get as reqwest_get;
use scraper;

use bzip2::read::BzDecoder;
use tar::Archive;

fn get_os() -> &'static str {
   if cfg!(target_os = "linux") {
      "linux"
   } else if cfg!(target_os = "windows") {
      "windows"
   } else if cfg!(target_os = "macos") {
      "macosx"
   } else {
      panic!("Unsupported OS");
   }
}

fn get_proc() -> &'static str {
   if cfg!(target_arch = "x86") {
      "32"
   } else if cfg!(target_arch = "x86_64") {
      "64"
   } else if cfg!(target_arch = "arm") {
      "arm"
   } else if cfg!(target_arch = "aarch64") {
      "arm64"
   } else {
      panic!("Unsupported Architecture");
   }
}

fn cef_folder(platform: &String) -> PathBuf {
   let folder = env_var("OUT_DIR").unwrap();
   let s = format!("{}/cef_builds/{}/", folder, &platform);
   PathBuf::from(s)
}

fn latest_cef_build_download_link(platform: &String) -> String {
   let cef_url = "http://opensource.spotify.com/cefbuilds";
   let cef_build_urls = format!("{}/{}", cef_url, "index.html");
   let begin_pattern = "cef_binary_";
   let tar_ball_pattern = format!("_{}_minimal.tar.bz2", &platform);

   let body = reqwest_get(&cef_build_urls)
      .expect("Failed to query list of cef builds page")
      .text()
      .expect("Couldn't retrieve text");

   let doc = scraper::Html::parse_document(&body);
   let selector = scraper::Selector::parse("a").unwrap();

   let archive_name = doc
      .select(&selector)
      .map(|x| x.value().attr("href"))
      .filter(|x| !x.is_none())
      .map(|x| x.unwrap())
      .filter(|x| x.starts_with(&begin_pattern) && x.ends_with(&tar_ball_pattern))
      .nth(0);

   assert!(
      archive_name.is_some(),
      "Counldn't find the download link for the {} platform",
      &platform
   );
   format!("{}/{}", cef_url, archive_name.unwrap())
}

fn download_cef(platform: &String) {
   let download_link = latest_cef_build_download_link(&platform);
   let resp = reqwest_get(&download_link).expect("failled to download tarball");
   let tar_stream = BzDecoder::new(resp);
   let folder_path = cef_folder(&platform);
   create_dir_all(&folder_path).expect("Couldn't create cef folder");

   for item in Archive::new(tar_stream).entries().unwrap() {
      let mut item = item.unwrap();
      let path = item.path().unwrap();
      let mut components = path.components();
      components.next();
      let path = folder_path.join(components.as_path());
      item.unpack(path).expect("Failed to extract file!");
   }
}

fn main() {
   let platform = format!("{}{}", get_os(), get_proc());
   let cef_folder = cef_folder(&platform);
   let cef_folder_str = cef_folder.to_str().expect("bad conversion");

   if !cef_folder.exists() {
      println!("Downloading cef folder for {} target", &platform);
      download_cef(&platform);
   }

   println!(
      "cargo:rustc-link-search=native={}{}/",
      &cef_folder_str, "Release"
   );
   println!("cargo:rustc-link-lib=cef");
   println!("cargo:include={}", &cef_folder_str);

   let include_path = format!("-I{}", &cef_folder_str);
   println!("{}", include_path);
   let header_file = format!("{}{}", &cef_folder_str, "include/capi/cef_app_capi.h");
   println!("{}", header_file);

   let bindings = bindgen::Builder::default()
      // The input header we would like to generate
      // bindings for.
      .clang_arg(include_path)
      .header(header_file)
      // Tell cargo to invalidate the built crate whenever any of the
      // included header files changed.
      .parse_callbacks(Box::new(bindgen::CargoCallbacks))
      // Finish the builder and generate the bindings.
      .generate()
      // Unwrap the Result and panic on failure.
      .expect("Unable to generate bindings");

   // Write the bindings to the $OUT_DIR/bindings.rs file.

   let out_path = PathBuf::from(env_var("OUT_DIR").unwrap());

   bindings
      .write_to_file(out_path.join("bindings.rs"))
      .expect("Couldn't write bindings!");
}

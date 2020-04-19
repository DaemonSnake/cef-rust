fn get_os() -> &'static str {
   if cfg!(target_os = "linux") {
      "linux"
   } else if cfg!(target_os = "windows") {
      "windows"
   } else if cfg!(target_os = "mac") {
      "macosx"
   } else {
      panic!("");
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
      panic!("");
   }
}

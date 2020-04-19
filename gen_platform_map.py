from html.parser import HTMLParser
from urllib import request
from json import dump

CEF_URL = "http://opensource.spotify.com/cefbuilds"
CEF_BUILDS_URLS = f"{CEF_URL}/index.html"

class Parser(HTMLParser):
    platform_urls = dict()

    def handle_starttag(self, tag, attrs):
        if tag == "a":
            for k, v in attrs:
                if k == "href" and v.endswith("_minimal.tar.bz2"):
                    platform = v.split("_")[-2]
                    if platform not in self.platform_urls:
                        self.platform_urls[platform] = f"{CEF_URL}/{v}"


def main():
    with request.urlopen(CEF_BUILDS_URLS) as stream:
        html_page = stream.read().decode("utf-8")
    p = Parser()
    p.feed(html_page)
    p.close()
    with open('platform_map.json', 'w') as fp:
        dump(p.platform_urls, fp)

if __name__ == "__main__":
    main()
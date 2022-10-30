/*

Recreational languages win at code golf too much. This challenge is simple, when using higher level functions.

The task is as follows:

Given any valid url, which is guaranteed to result in a valid HTML document (for example https://en.wikipedia.org/wiki/Ruby_on_Rails, which has 9 images), count the number of images displayed from the resultant webpage.

Only images visible in the HTML code are counted, marked by the HTML <img> tag.

Websites that can continually load images (Google Images) are not valid tests.

*/

package main

import (
	"bytes"
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"

	"golang.org/x/net/html"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("get-number-of-images: ")
	parseflags()

	url := flag.Arg(0)
	data, err := get(url)
	ck(err)

	images, err := count(data)
	ck(err)

	fmt.Println(images)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] url")
	flag.PrintDefaults()
	os.Exit(2)
}

func get(url string) (b []byte, err error) {
	r, err := http.Get(url)
	if err != nil {
		return
	}
	return io.ReadAll(r.Body)
}

func count(b []byte) (x int, err error) {
	r := bytes.NewReader(b)
	d, err := html.Parse(r)
	if err != nil {
		return
	}
	walk(d, &x)
	return
}

func walk(n *html.Node, x *int) {
	if n.Type == html.ElementNode && n.Data == "img" {
		*x += 1
	}

	for c := n.FirstChild; c != nil; c = c.NextSibling {
		walk(c, x)
	}
}

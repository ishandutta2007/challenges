/*

xkcd is everyone's favorite webcomic, and you will be writing a program that will bring a little bit more humor to us all.
Your objective in this challenge is to write a program which will take a number as input and display that xkcd and its title-text (mousover text).

Input

Your program will take a positive integer as input (not necessarily one for which there exists a valid comic) and display that xkcd: for example, an input of 1500 should display the comic "Upside-Down Map" at xkcd.com/1500,
and then either print its title-text to the console or display it with the image.

Due to their proximity across the channel, there's long been tension between North Korea and the United Kingdom of Great Britain and Southern Ireland.
Due to their proximity across the channel, there's long been tension between North Korea and the United Kingdom of Great Britain and Southern Ireland.

Test case 2, for n=859:

Brains aside, I wonder how many poorly-written xkcd.com-parsing scripts will break on this title (or ;;"''{<<[' this mouseover text."

Brains aside, I wonder how many poorly-written xkcd.com-parsing scripts will break on this title (or ;;"''{<<[' this mouseover text."

Your program should also be able to function without any input, and perform the same task for the most recent xkcd found at xkcd.com, and it should always display the most recent one even when a new one goes up.

You do not have to get the image directly from xkcd.com, you can use another database as long as it is up-to-date and already existed before this challenge went up.
URL shortners, that is, urls with no purpose other than redirecting to somewhere else, are not allowed.

You may display the image in any way you chose, including in a browser. You may not, however, directly display part of another page in an iframe or similar.
CLARIFICATION: you cannot open a preexisting webpage, if you wish to use the browser you have to create a new page. You must also actually display an image - outputting an image file is not allowed.

You can handle the case that there isn't an image for a particular comic (e.g. it is interactive or the program was passed a number greater than the amount of comics that have been released) in any reasonable way you wish, including throwing an exception,
or printing out an at least single-character string, as long as it somehow signifies to the user that there isn't an image for that input.

You can only display an image and output its title-text, or output an error message for an invalid comic. Other output is not allowed.

This is a code-golf challenge, so the fewest bytes wins.

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
	log.SetPrefix("get-xkcd-title: ")
	parseflags()

	url := fmt.Sprintf("https://xkcd.com/%v", flag.Arg(0))
	data, err := get(url)
	ck(err)

	text, err := extract(data)
	ck(err)

	fmt.Println(text)
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
	fmt.Fprintln(os.Stderr, "usage: [options] comic")
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

func extract(b []byte) (s string, err error) {
	r := bytes.NewReader(b)
	d, err := html.Parse(r)
	if err != nil {
		return
	}
	s = walk(d)
	return
}

func walk(n *html.Node) (s string) {
	if n.Type == html.ElementNode && n.Data == "img" {
		for _, a := range n.Attr {
			if a.Key == "title" {
				return a.Val
			}
		}
	}

	for c := n.FirstChild; c != nil; c = c.NextSibling {
		if s = walk(c); s != "" {
			return
		}
	}
	return
}

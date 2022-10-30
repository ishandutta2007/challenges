/*

Challenge
Given a valid goo.gl shortened link, output the original URL.

Example
goo.gl/qIwi3N would give something like https://codegolf.stackexchange.com/.
For input, you can choose to have the https?:// at the beginning, you can choose to have www. before the goo.gl, and you can also choose to get rid of the goo.gl if you only want the end of the URL.
A slash at the end is optional for input and output. So, your input will end up matching the regex (https?://)?(www\.)?(goo\.gl/)?[A-Za-z0-9]+/?.
For the output, you can choose whether or not to output https?://, whether or not to output www., and whether or not to output a trailing slash. However, you must be consistent with your I/O formatting.

I will say that you do not have to be consistent with https vs. http for output (but you must be consistent for input), as long as you are consistent with whether or not you include the whole https?:// part.

Test Cases
These are written with no https://, no www., no trailing slash in the input; yes https://, no www., and yes trailing slash in the output.

input -> output
goo.gl/HaE8Au -> https://codegolf.stackexchange.com/
goo.gl/IfZMwe -> https://stackoverflow.com/
goo.gl/JUdmxL -> https://chat.stackexchange.com/rooms/240/the-nineteenth-byte
Assumptions
You may assume that the shortened link will not point to another shortened link and that the destination site will return a status code of 2xx or 4xx (no redirections).
You can go here and enter a URL to apply the inverse operation of this: https://goo.gl/

*/

package main

import (
	"flag"
	"fmt"
	"net/http"
	"os"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	for _, url := range flag.Args() {
		resp, err := http.Get(url)
		if err != nil {
			fmt.Fprintf(os.Stderr, "Failed to lookup %q: %v\n", url, err)
			continue
		}
		fmt.Printf("%s -> %s\n", url, resp.Request.URL)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] url ...")
	flag.PrintDefaults()
	os.Exit(2)
}

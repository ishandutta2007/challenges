/*

Your challenge is to write a code-golf HTTP server that accepts GET requests. It obviously doesn't have to be fully featured, but it must serve files from a directory.

Rules:

The HTTP server must listen on TCP port 36895 (0x901F)
It must serve files from /var/www on *NIX systems (e.g. Linux), or C:\hgolf on Windows.
You may ignore all incoming HTTP headers except the GET itself.
If the HTTP method is not GET, you must send back a status code of "405 Not Supported" and a body of "405 Not Supported".
If the file does not exist, you must send back a status code of "404 File Not Found" and a body of "404 File Not Found".
If the file exists but could not be read for some reason, you must send back a status code of "500 Server Error" and a body of "500 Server Error".
If the user requests / or any other existing directory root (e.g. /foo/ where a directory foo exists in /var/www/), respond with a blank page.
Your response must contain at least the minimum headers to allow the content to be displayed on Firefox 8.0 and Internet Explorer 8.0
You must respond with the Content-Type header set, but you only have to support extensions html => text/html and txt => text/plain. For any other file extension, Send application/octet-stream as the content type.
Your code must be able to transfer both ASCII and binary data, though you do not explicitly have to distinguish between the two.
You may not use 3rd party libraries.
You may not use in-built classes or features designed to process HTTP requests (e.g. HttpListener in C#)
If your code will only work on a specific OS due to the socket APIs you've used, please state this.
Solutions must include an image showing it serving a HTML page to a browser.

If you've got any questions, please feel free to ask! :)

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"net/http"
	"os"
)

var (
	addr = flag.String("addr", ":8080", "bind address")
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	dir := flag.Arg(0)
	log.Printf("Serving %q at %q\n", dir, *addr)

	err := http.ListenAndServe(*addr, http.FileServer(http.Dir(dir)))
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <directory>")
	flag.PrintDefaults()
	os.Exit(2)
}

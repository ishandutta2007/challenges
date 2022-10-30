/*

Make the shortest proxy server.
Input/Output Specifications

Client:

    Input: a port number (32-bit integer) (,) or (space) a url (see test cases)
    Output: html source of the url

Server:

    Input: port to listen to (32-bit integer)
    Output: REC when input is received from the client, OK when finished sending the html source to the client.

Rules

    You may make either a complete program or functions in an interpreted language.
    Input is taken through stdin or given as a arguments.
    Your code has to work for the given test cases only (more is optional, less is invalid).
    The client output has to be the same as with what you get when you "view source" from a browser.
    The server may exit after each handled request (i.e does not have to be persistent/daemon)
    (edit) Any other input/output than what specified, is forbidden.

Test cases (client inputs)

    N1 https://stackoverflow.com/
    N2 http://en.wikipedia.org/wiki/Proxy_server
    N3 http://stackexchange.com/search?q=code+golf

where Ni are random integers between 1 and 2048.

*/

package main

import (
	"bytes"
	"flag"
	"fmt"
	"io"
	"log"
	"net"
	"net/http"
	"os"
	"strconv"
)

func main() {
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	port, _ := strconv.Atoi(flag.Arg(0))
	url := flag.Arg(1)

	err := proxy(port, url)
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <port> <url>")
	flag.PrintDefaults()
	os.Exit(2)
}

func proxy(port int, url string) error {
	addr := fmt.Sprintf(":%d", port)
	ln, err := net.Listen("tcp", addr)
	if err != nil {
		return err
	}
	defer ln.Close()

	log.Println("Listening on", addr)
	log.Println("Serving", url)
	for {
		conn, err := ln.Accept()
		if err != nil {
			log.Println(err)
			continue
		}

		log.Println("Connection", conn.LocalAddr(), conn.RemoteAddr())
		go serve(conn, url)
	}

	return nil
}

func serve(conn net.Conn, url string) {
	data := get(url)
	conn.Write([]byte("REC"))
	conn.Write(data)
	conn.Write([]byte("OK"))
	conn.Close()
}

func get(url string) []byte {
	resp, err := http.Get(url)
	if err != nil {
		return []byte(err.Error())
	}

	w := new(bytes.Buffer)
	io.Copy(w, resp.Body)
	return w.Bytes()
}

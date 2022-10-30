/*

As we all should know, there's a HTTP status code 418: I'm a teapot.

Your mission, should you choose to accept it, is to use your creativitea and write the smallest possible server that responds with the above status code to any and every HTTP request made to it.

Standard loopholes apply, including

    Fetching the desired output from an external source

    This includes doing an HTTP request to fetch the page with the question and extracting a solution from that page. This was mildly amusing back in 2011, but now is derivative and uninteresting.

Meaning you cannot simply redirect the request to another server to have it return the response.

Your server can do anything (or nothing) while no HTTP request is made to it as long as it replies with the correct response once a HTTP request is made.

*/

package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/", handler)
	http.ListenAndServe(":8080", nil)
}

func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Println(r)
	w.WriteHeader(418)
	fmt.Fprintf(w, "%d: %s", 418, http.StatusText(418))
}

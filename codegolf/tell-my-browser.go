/*

Background

Many people visit webpages, which require special browsers because of lack of compatibility.
So you have to write a script (client sided or server sided), which just prints the name of the browser.
Because not everyone has fast internet, the script has to be as short as possible. (This is a joke xD)

Rules
You have to print the name of the browser loading the page without any version number etc. to STDOUT or equivalent. Leading or trailing spaces are allowed.
You can assume the browser is Firefox, Chrome, Edge, Safari or Opera, so only those browsers will be tested. Don't print "Chromium", this does NOT count.
The script may be server sided with CGI (in any language), ruby on rails, jsp and similar. (Given server will be apache 2 on debian)
Client sided scripts may be written in JavaScript, TypeScript, and any other versions of ECMAScript, it just has to run in all five browsers.

If your language has no offline interpreter for CGI, assume it's saved in /usr/bin/i, the shebang at the beginning does not add bytes to the count.
This is a code-golf, so the shortest answer wins!
Http requests are put through stdin.

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
	fmt.Println(r.Header.Get("User-Agent"))
	fmt.Fprintf(w, "\n")
}

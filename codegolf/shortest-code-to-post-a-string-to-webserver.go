/*

In bash, this code posts String to post to http://www.example.com/target:

curl -d "String to post" "http://www.example.com/target"
NOTE: You should use http://www.example.com/target as the URL to POST to, without any change.

I think all other languages that I have knowledge in need a lot more code than this. I'm not blaming other languages. Let's see the interesting answers that reduce the effort.

Your task is to write the shortest code possible to send a POST request to a sample server, http://www.example.com/target, and the request data should be the string String to post.

*/

package main

import (
	"io"
	"log"
	"net/http"
	"os"
	"strings"
)

func main() {
	resp, err := http.Post("http://www.example.com/target", "application/x-www-form-urlencoded", strings.NewReader("String to post"))
	if err != nil {
		log.Fatal(err)
	}
	io.Copy(os.Stdout, resp.Body)
}

/*

Write a program/function/script that takes a natural number i from 1 to 10 as input and outputs the URL of the Question with the i th hottest question on the Code Golf Portal

The ordering should be like in https://codegolf.stackexchange.com/?tab=hot. For example:
input 1
output https://codegolf.stackexchange.com/questions/127047/the-spain-license-plates-game
(at the point of this edit)

There are no strong restrictions to the output, as long as the url can be reasonably retrieved. Valid outputs include strings, console printing etc.

It's Code Golf, so shortest code in Bytes wins.

Notes
If your program automatically opens a browser with the webpage, it counts as valid output and is totally cool.

If your program does not retrieve the ranking from current information (i.e. hardcoding the links), it is not valid.

The contest ends with the end of June.

As questioned: The indexing must be 1 based, ie: the input 1 must return the the first site of the hottest questions.

Comment
I hope this question is not too clickbaity, as the stack exchange editor program was mocking me for the title. Originally I planned this challenge with Youtube trends, where it would haven been more fitting.

*/

package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"strconv"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("clickbaits: ")

	flag.Usage = usage
	flag.Parse()

	index := 1
	if flag.NArg() >= 1 {
		index, _ = strconv.Atoi(flag.Arg(0))
	}
	link, err := clickbait(index)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(link)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <index>")
	flag.PrintDefaults()
	os.Exit(2)
}

func clickbait(index int) (link string, err error) {
	resp, err := http.Get("http://api.stackexchange.com/questions?sort=hot&site=codegolf")
	if err != nil {
		return
	}

	buf, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return
	}

	var doc struct {
		Items []struct {
			Link string
		}
	}

	err = json.Unmarshal(buf, &doc)
	if err != nil {
		return
	}

	if index -= 1; 0 <= index && index < len(doc.Items) {
		link = doc.Items[index].Link
	}

	return
}

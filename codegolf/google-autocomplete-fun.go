/*

Your task is to create a program which, given an input string, will output the first Google autocomplete result for that search. The format of input/output is up to you.

Rules
Your program must take 1 input, a string, and output the top Google autocomplete/auto-fill suggestions result. The format of input/output is up to you. Just be sure to mention what your I/O format is.
Obviously, accessing the Internet is allowed.
URL shorteners (like bit.ly, TinyURL, etc.) are strictly disallowed.
You should fetch your autocomplete results from this URL: http://suggestqueries.google.com/complete/search?client=your_browser&q=your_query or http://google.com/complete/search?client=your_browser&q=your_query.
You are allowed to assume any browser name (or string, for that matter) for client. In the program I wrote, I assume Chrome. Any browser name or string should work.
You are allowed to pass any options to the webpage as long as you are using some variant of http://suggestqueries.google.com/complete/search.
Please provide an explanation of how your program works. It is not mandatory, but I strongly advise it.
All standard loopholes are strictly forbidden.

Test Cases

These are constantly changing, so edit this post if these become out-of-date.

'how to'
  => 'how to make slime'
'code golf'
  => 'code golf languages'
'you'
  => 'youtube'
'g'
  => 'google' (why would you google 'google'?)
This is code-golf, so may the shortest code win and the best programmer prosper...

*/

package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"net/url"
	"os"
	"strings"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	keyword := strings.Join(flag.Args(), " ")
	str, err := query(keyword)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%s\n", str)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] keyword")
	flag.PrintDefaults()
	os.Exit(2)
}

func query(keyword string) (suggestion string, err error) {
	keyword = url.QueryEscape(keyword)
	link := fmt.Sprintf("http://suggestqueries.google.com/complete/search?client=chrome&q=%s", keyword)
	resp, err := http.Get(link)
	if err != nil {
		return
	}
	buf, err := io.ReadAll(resp.Body)
	if err != nil {
		return
	}

	var res Result
	err = json.Unmarshal(buf, &res)
	if err != nil {
		return
	}

	suggestion = res.Suggestions[0]
	return
}

type Result struct {
	Keyword     string
	Suggestions []string
}

func (r *Result) UnmarshalJSON(buf []byte) error {
	val := []any{&r.Keyword, &r.Suggestions}
	err := json.Unmarshal(buf, &val)
	if err != nil {
		return err
	}
	if len(r.Suggestions) == 0 {
		r.Suggestions = []string{r.Keyword}
	}
	return nil
}

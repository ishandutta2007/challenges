/*

Introduction

Wardialing was a very interesting way to try to hack people back in the '80s and '90s.
When everyone used dial-up, people would dial huge amounts of numbers to search for BBS's, computers, or fax machines.
If it was answered by a human or answering machine, it hung up and forgot the number. If it was answered by a modem or a fax machine, it would make note of the number.

"Of course, you realize this means War...dialing?" <--- Pun made by @Shaggy

Challenge

Your job is to make a URL wardialer. Something that tests and checks if it's a valid website from one letter of the alphabet.

Constraints

Program must take user input. This input has to be a letter of the alphabet, no numbers. Just one letter of the alphabet and form multiple URLs that start with the letter. Input letter will be lowercase, not uppercase.
Standard loopholes apply.
You must make 8 URLs from 1 letter, and test to see if it is a valid site.
If you hit an error (not a response code), instead of leaving it blank, go ahead and return a 404
If you hit a redirect (3xx), return a 200 instead.
You may output the results in any reasonable format, as long as it includes the website name, status codes for all the websites and the redirects.
This is code-golf, so shortest amount of bytes wins.
What counts as a URL for this challenge?
http://{domain-name}.{com or net or org}

For this challenge, the domain name should only be 4 letters long, no more, no less.

What should I test?

For each 4 letter domain name, test it against three top-level domains (.com, .net, .org).
Record all the response codes from each URL, remember from the constraints that any (3xx) should return 200 and be recorded as a redirect in the output and any error getting to the website should result in a 404.

Input
a

Output
+---------+------+------+------+------------+
| Website | .com | .net | .org | Redirects? |
+---------+------+------+------+------------+
| ajoe    | 200  | 200  | 200  | .com, .net |
+---------+------+------+------+------------+
| aqiz    | 200  | 404  | 404  | no         |
+---------+------+------+------+------------+
| amnx    | 200  | 503  | 404  | .com       |
+---------+------+------+------+------------+
| abcd    | 200  | 404  | 200  | .com       |
+---------+------+------+------+------------+
| ajmx    | 200  | 503  | 404  | no         |
+---------+------+------+------+------------+
| aole    | 200  | 200  | 200  | .com       |
+---------+------+------+------+------------+
| apop    | 404  | 200  | 200  | .net       |
+---------+------+------+------+------------+
| akkk    | 200  | 200  | 200  | .com       |
+---------+------+------+------+------------+

*/

package main

import (
	"flag"
	"fmt"
	"net/http"
	"os"
	"strings"
	"time"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	c0 := flag.Arg(0)[0]
	wardial(rune(c0))
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: letter")
	flag.PrintDefaults()
	os.Exit(2)
}

func wardial(c0 rune) {
	tlds := []string{"com", "net", "org"}
	client := &http.Client{
		CheckRedirect: func(req *http.Request, via []*http.Request) error {
			return http.ErrUseLastResponse
		},
		Timeout: 1 * time.Second,
	}

	fmt.Printf("%-7s | %-4s | %-4s | %-4s | %-12s\n", "Website", ".com", ".net", ".org", "Redirects?")
	for c1 := 'a'; c1 <= 'z'; c1++ {
		for c2 := 'a'; c2 <= 'z'; c2++ {
			for c3 := 'a'; c3 <= 'z'; c3++ {
				codes := [3]int{404, 404, 404}
				redir := ""

				site := fmt.Sprintf("%c%c%c%c", c0, c1, c2, c3)
				for i := range codes {
					url := fmt.Sprintf("http://%s.%s", site, tlds[i])
					resp, _ := client.Head(url)
					if resp != nil {
						codes[i] = resp.StatusCode
					}

					switch codes[i] {
					case 301, 302, 303, 307, 308:
						codes[i] = 200
						redir += fmt.Sprintf(".%s, ", tlds[i])
					}
				}
				redir = strings.TrimSuffix(redir, ", ")

				fmt.Printf("%-7s | %-4d | %-4d | %-4d | %-12s\n", site, codes[0], codes[1], codes[2], redir)
			}
		}
	}
}

/*

Use wikipedia API to find random words and make a chain of them

*/

package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"log"
	"math/rand"
	"net/http"
	"os"
	"strconv"
	"strings"
	"time"
	"unicode"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("wikipedia-api: ")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	rand.Seed(time.Now().UnixNano())
	word := flag.Arg(0)
	count, _ := strconv.Atoi(flag.Arg(1))
	err := walk(word, count)
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <word> <count>")
	flag.PrintDefaults()
	os.Exit(2)
}

func walk(word string, count int) error {
	const searchurl = "https://en.wikipedia.org/w/api.php?action=opensearch&format=json&search="

	db := make(map[string]bool)
	for i := 0; i < count; i++ {
		fmt.Printf("#%d %s\n", i+1, word)

		url := fmt.Sprint(searchurl, word)
		desc, err := getword(url)
		if err != nil {
			return err
		}

		word, err = randword(&desc, 10, db)
		if err != nil {
			return err
		}

		if word == "" {
			break
		}

		db[strings.ToLower(word)] = true
	}

	return nil
}

func getpage(url string) (data []byte, err error) {
	resp, err := http.Get(url)
	if err != nil {
		return
	}

	return io.ReadAll(resp.Body)
}

func getword(url string) (desc Description, err error) {
	data, err := getpage(url)
	if err != nil {
		return
	}
	err = json.Unmarshal(data, &desc)
	return
}

func randword(desc *Description, tries int, db map[string]bool) (string, error) {
	nl := len(desc.Link)
	if nl == 0 {
		return "", nil
	}

	for i := 0; i < tries; i++ {
		choice := rand.Intn(nl)
		page, err := getpage(desc.Link[choice])
		if err != nil {
			return "", err
		}

		word := findword(page, tries*5)
		if db[strings.ToLower(word)] {
			continue
		}

		if word != "" {
			return word, nil
		}
	}
	return "", nil
}

func findword(page []byte, tries int) string {
	word := ""

	toks := strings.Split(string(page), " ")
	if len(toks) == 0 {
		return word
	}

	for i := 0; i < tries; i++ {
		choice := rand.Intn(len(toks))
		xword := toks[choice]
		if !haspunct(xword) {
			word = xword
			break
		}
	}
	return word
}

func haspunct(word string) bool {
	for _, r := range word {
		switch {
		case unicode.IsPunct(r):
			return true
		case !unicode.IsGraphic(r):
			return true
		case strings.IndexRune("<>+-*/=[].`\"|()!@#$%^&⋅", r) >= 0:
			return true
		}
	}
	return false
}

type Description struct {
	Key  string
	Word []string
	Meta []string
	Link []string
}

func (d *Description) UnmarshalJSON(buf []byte) error {
	fields := []interface{}{&d.Key, &d.Word, &d.Meta, &d.Link}
	return json.Unmarshal(buf, &fields)
}

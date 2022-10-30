/*

http://en.wikipedia.org/wiki/Dissociated_press

Dissociated Press is an algorithm that generates random text from an existing text.

    The algorithm starts by printing any N consecutive words (or letters) in the text.
    Then at every step it searches for any random occurrence in the original text of the last N words (or letters) already printed and then prints the next word or letter.

Implement Dissociated Press, either as a function or as a whole program.
Shortest code wins. Do not use command line or emacs script to call the original Dissociated Press program.
Do not use any external libraries.

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"math/rand"
	"os"
	"regexp"
	"strconv"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	log.SetPrefix("disassociated-press: ")
	log.SetFlags(0)

	parseflags()

	buf, err := os.ReadFile(flag.Arg(0))
	ck(err)

	nwords, err := strconv.Atoi(flag.Arg(1))
	ck(err)

	gen(string(buf), nwords)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <file> <numwords>")
	flag.PrintDefaults()
	os.Exit(2)
}

func gen(str string, nwords int) {
	re := regexp.MustCompile("([\\w']+[\\.?!,]?)+")
	txt := re.FindAllString(str, -1)
	ntxt := len(txt)

	db := make(map[string][]string)

	// for all words, append the word following it and add it to the database
	for i := 0; i < ntxt; i++ {
		var words []string
		for j := 0; j < ntxt-1; j++ {
			if txt[i] == txt[j] {
				words = append(words, txt[j+1])
			}
		}
		db[txt[i]] = words
	}

	// pick a random word and choose randomly one of the suffix words
	// then select that suffix word to be the new random word and repeat
	// until we run out of suffixes or the max number of words is reached.
	p := db[string(txt[rand.Intn(ntxt)])]
	for i := 0; i < nwords; i++ {
		if len(p) == 0 {
			break
		}
		j := rand.Intn(len(p))

		fmt.Printf("%s ", p[j])
		if i > 0 && i%32 == 0 {
			fmt.Println()
		}

		p = db[p[j]]
	}
	fmt.Println()
}

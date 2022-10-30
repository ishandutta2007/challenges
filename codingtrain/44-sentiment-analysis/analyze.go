package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"log"
	"os"
	"strings"
)

var flags struct {
	corpus string
}

func main() {
	log.SetFlags(0)
	log.SetPrefix("sentiment-analyze: ")
	parseflags()

	db, err := readcorpus(flags.corpus)
	ck(err)

	analyze(os.Stdin, db)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	flag.Usage = usage
	flag.StringVar(&flags.corpus, "corpus", "AFINN-111.txt", "corpus file")
	flag.Parse()
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <stdin>")
	flag.PrintDefaults()
	os.Exit(2)
}

func readcorpus(name string) (map[string]int, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	db := make(map[string]int)
	sc := bufio.NewScanner(f)
	for sc.Scan() {
		var (
			word  string
			score int
		)

		line := sc.Text()
		_, err = fmt.Sscanf(line, "%s %d", &word, &score)
		if err != nil {
			continue
		}

		db[word] = score
	}
	return db, nil
}

func analyze(r io.Reader, db map[string]int) {
	var (
		positive  int
		neutral   int
		negative  int
		words     int
		sentiment int
	)

	b := bufio.NewReader(r)
	for {
		var word string
		_, err := fmt.Fscan(b, &word)
		if err != nil {
			break
		}
		word = strings.ToLower(word)

		score := db[word]
		if score > 0 {
			positive++
		} else if score == 0 {
			neutral++
		} else {
			negative++
		}
		sentiment += score
		words++
	}

	fmt.Printf("Number of Words %d\n", words)
	fmt.Printf("Sentiment Score %d\n", sentiment)
	if words == 0 {
		words = 1
	}
	fmt.Printf("Positive Ratio  %d (%f)\n", positive, float64(positive)/float64(words))
	fmt.Printf("Neutral Ratio   %d (%f)\n", neutral, float64(neutral)/float64(words))
	fmt.Printf("Negative Ratio  %d (%f)\n", negative, float64(negative)/float64(words))
}

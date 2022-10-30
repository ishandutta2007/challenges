// https://en.wikipedia.org/wiki/Tf%E2%80%93idf
// Statistical measure of how relevant a word in a text document is in a collection

package main

import (
	"flag"
	"fmt"
	"log"
	"math"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strings"
)

var flags struct {
	corpus string
	tdf    string
	idf    string
}

func main() {
	log.SetFlags(0)
	log.SetPrefix("tf-idf: ")
	parseflags()

	words, err := analyze(flags.corpus, flag.Arg(0), flags.tdf, flags.idf)
	check(err)

	for _, p := range words {
		fmt.Printf("%-32s: %.6f\n", p.name, p.tfidf)
	}
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	flag.StringVar(&flags.corpus, "corpus", "corpus", "corpus directory")
	flag.StringVar(&flags.tdf, "tdf", "raw", "tdf weighting function")
	flag.StringVar(&flags.idf, "idf", "idf", "idf weighting function")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] document")
	flag.PrintDefaults()
	fmt.Fprintln(os.Stderr)
	fmt.Fprintln(os.Stderr, "tdf: binary raw tf lognorm")
	fmt.Fprintln(os.Stderr, "idf: unary idf idfsmooth idfprob")
	os.Exit(2)
}

type Word struct {
	name string

	tf    float64
	df    float64
	idf   float64
	tfidf float64

	nt float64
	nd float64
}

func analyze(corpus, document, tdf, idf string) (result []*Word, err error) {
	glob := filepath.Join(corpus, "*.txt")
	texts, err := filepath.Glob(glob)
	if err != nil {
		return
	}

	document = filepath.Clean(document)
	words, err := wordcount(document)
	if err != nil {
		return
	}

	var (
		otherwords []map[string]*Word
		otherword  map[string]*Word
		numdocs    = 1
	)
	for _, text := range texts {
		text = filepath.Clean(text)
		if text == document {
			continue
		}

		otherword, err = wordcount(text)
		if err != nil {
			return
		}
		otherwords = append(otherwords, otherword)

		numdocs++
	}

	for key, word := range words {
		for _, otherword := range otherwords {
			if otherword[key] != nil {
				word.df++
			}
		}
	}

	for _, word := range words {
		word.nd = float64(numdocs)
		word.tf = tdfweight(tdf, word)
		word.idf = idfweight(idf, word)
		word.tfidf = word.tf * word.idf
		result = append(result, word)
	}
	sort.Slice(result, func(i, j int) bool {
		if result[i].tfidf == result[j].tfidf {
			return result[i].name < result[j].name
		}
		return result[i].tfidf > result[j].tfidf
	})

	return
}

func wordcount(name string) (words map[string]*Word, err error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return
	}

	words = make(map[string]*Word)
	total := 0.0

	re := regexp.MustCompile("\\w+")
	matches := re.FindAll(data, -1)
	for _, str := range matches {
		key := strings.ToLower(string(str))
		if words[key] == nil {
			words[key] = new(Word)
		}
		words[key].name = key
		words[key].df = 1
		words[key].tf++
		total++
	}

	for _, word := range words {
		word.nt = total
	}

	return
}

func tdfweight(typ string, word *Word) float64 {
	switch typ {
	case "binary":
		return 1
	case "raw":
		return word.tf
	case "tf":
		return word.tf / word.nt
	case "lognorm":
		return math.Log(1 + word.tf)
	}

	log.Fatalf("unknown tdf function %q", typ)
	panic("unreachable")
}

func idfweight(typ string, word *Word) float64 {
	switch typ {
	case "unary":
		return 1
	case "idf":
		return math.Log(word.nd / word.df)
	case "idfsmooth":
		return math.Log(word.nd/(1+word.df)) + 1
	case "idfprob":
		return math.Log((word.nd - word.df) / word.df)
	}

	log.Fatalf("unknown idf function %q", typ)
	panic("unreachable")
}

// Use a context free grammar production rules to generate a random sentence
package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"log"
	"math/rand"
	"os"
	"strings"
	"time"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("context-free-grammar: ")

	rand.Seed(time.Now().UnixNano())
	parseflags()

	rules, err := readrules(flag.Arg(0))
	if err != nil {
		log.Fatal(err)
	}

	result := expand(flag.Arg(1), rules)
	sentence := strings.Join(result, " ")
	fmt.Println(sentence)
}

func parseflags() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <rulefile> <start>")
	flag.PrintDefaults()
	os.Exit(2)
}

func readrules(name string) (map[string][][]string, error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return nil, err
	}

	rules := make(map[string][][]string)
	err = json.Unmarshal(data, &rules)
	if err != nil {
		return nil, err
	}
	return rules, nil
}

func expand(start string, rules map[string][][]string) []string {
	var result []string
	if choices := rules[start]; len(choices) > 0 {
		choices := rules[start]
		index := rand.Intn(len(choices))
		for _, str := range choices[index] {
			result = append(result, expand(str, rules)...)
		}
	} else {
		result = append(result, start)
	}
	return result
}

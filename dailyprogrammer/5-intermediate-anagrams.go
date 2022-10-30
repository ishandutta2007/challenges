/*

Your challenge today is to write a program that can find the amount of anagrams within a .txt file. For example, "snap" would be an anagram of "pans", and "skate" would be an anagram of "stake".

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"regexp"
	"sort"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("anagrams: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	b, err := os.ReadFile(flag.Arg(0))
	if err != nil {
		log.Fatal(err)
	}

	find(b)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: file")
	flag.PrintDefaults()
	os.Exit(2)
}

func find(b []byte) {
	re := regexp.MustCompile("\\w+")
	l := re.FindAll(b, -1)

	m := make(map[string][]string)
	u := make(map[string]bool)
	for _, p := range l {
		v := string(p)
		if u[v] {
			continue
		}

		k := sortword(p)
		m[k] = append(m[k], v)
		u[v] = true
	}

	var r [][2]string
	for _, s := range m {
		n := len(s)
		for i := 0; i < n; i++ {
			for j := i + 1; j < n; j++ {
				r = append(r, [2]string{s[i], s[j]})
			}
		}
	}
	sort.Slice(r, func(i, j int) bool {
		if r[i][0] == r[j][0] {
			return r[i][1] < r[j][1]
		}
		return r[i][0] < r[j][0]
	})

	for _, s := range r {
		fmt.Printf("%s <-> %s\n", s[0], s[1])
	}
}

func sortword(w []byte) string {
	p := append([]byte{}, w...)
	sort.Slice(p, func(i, j int) bool {
		return p[i] < p[j]
	})
	return string(p)
}

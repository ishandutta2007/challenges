package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() {
	wordcount(os.Stdin)
}

func wordcount(r io.Reader) {
	m := make(map[string]int)
	b := bufio.NewReader(r)
	for {
		var s string
		_, err := fmt.Fscan(b, &s)
		if err != nil {
			break
		}

		m[s]++
	}

	var (
		p []word
		l int
	)
	for k, v := range m {
		p = append(p, word{k, v})
		if n := len(k); l < n {
			l = n
		}
	}

	sort.Slice(p, func(i, j int) bool {
		return p[i].count > p[j].count
	})

	for _, w := range p {
		fmt.Printf("%-*s %d\n", l, w.ident, w.count)
	}
}

type word struct {
	ident string
	count int
}

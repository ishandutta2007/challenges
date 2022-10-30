/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	fmt.Println(lcb("23"))
	fmt.Println(lcb("111-5555"))
	fmt.Println(len(lcb("111-5555")))
	fmt.Println(len(lcb("111-2424")))
	fmt.Println(len(lcb(" 123456789 ")))
	fmt.Println(len(lcb("abc")))
	fmt.Println(lcb(""))
}

func lcb(d string) []string {
	p := &phonemap{}
	p.init()
	p.gen(d, "")
	sort.Strings(p.list)
	return p.list
}

type phonemap struct {
	tab  []string
	list []string
}

func (p *phonemap) init() {
	p.tab = []string{
		"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
	}
	p.list = p.list[:0]
}

func (p *phonemap) gen(d, c string) {
	i := strings.IndexAny(d, "23456789")
	if i < 0 {
		if c != "" {
			p.list = append(p.list, c)
		}
		return
	}

	l := p.tab[d[i]-'2']
	for _, r := range l {
		p.gen(d[i+1:], c+string(r))
	}
}

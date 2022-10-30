/*

5 Friends (let's call them a, b, c, d and e) are playing a game and need to keep track of the scores. Each time someone scores a point, the letter of his name is typed in lowercase. If someone loses a point, the letter of his name is typed in uppercase. Give the resulting score from highest to lowest.

Input Description
A series of characters indicating who scored a point. Examples:

abcde
dbbaCEDbdAacCEAadcB

Output Description
The score of every player, sorted from highest to lowest. Examples:

a:1, b:1, c:1, d:1, e:1
b:2, d:2, a:1, c:0, e:-2

Challenge Input
EbAAdbBEaBaaBBdAccbeebaec

*/

package main

import (
	"fmt"
	"sort"
	"unicode"
)

func main() {
	tally("abcde")
	tally("dbbaCEDbdAacCEAadcB")
	tally("EbAAdbBEaBaaBBdAccbeebaec")
}

type char struct {
	c rune
	n int
}

func tally(s string) {
	m := make(map[rune]int)
	for _, ch := range s {
		cl := unicode.ToLower(ch)
		if unicode.IsUpper(ch) {
			m[cl]--
		} else {
			m[cl]++
		}
	}

	var c []char
	for k, v := range m {
		c = append(c, char{k, v})
	}
	sort.SliceStable(c, func(i, j int) bool {
		if c[i].n == c[j].n {
			return c[i].c < c[j].c
		}
		return c[i].n > c[j].n
	})

	for _, c := range c {
		fmt.Printf("%c:%d ", c.c, c.n)
	}
	fmt.Println()
}

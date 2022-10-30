/*

Create a function that takes in an array of full names and returns the initials.
Examples

initialize(["Stephen Hawking"]) ➞ ["S. H."]

initialize(["Harry Potter", "Ron Weasley"]) ➞ ["H. P.", "R. W."]

initialize(["Sherlock Holmes", "John Watson", "Irene Adler"]) ➞ ["S. H.", "J. W.", "I. A."]

Notes

    Each initial is followed by a dot.
    Names will always be made of two words, separated by a space.

*/

package main

import (
	"fmt"
	"strings"
	"unicode"
	"unicode/utf8"
)

func main() {
	cmp(initialize([]string{"Sherlock Holmes", "John Watson", "Irene Adler"}), []string{"S. H.", "J. W.", "I. A."})
	cmp(initialize([]string{"Harry Potter", "Ronald Weasley"}), []string{"H. P.", "R. W."})
	cmp(initialize([]string{"Stephen Hawking"}), []string{"S. H."})
	cmp(initialize([]string{"Attic Finch"}), []string{"A. F."})
	cmp(initialize([]string{"Leonardo Dicaprio"}), []string{"L. D."})
}

func initialize(s []string) []string {
	var p []string
	for i := range s {
		t := strings.Split(s[i], " ")
		if len(t) != 2 {
			return nil
		}

		a, _ := utf8.DecodeRuneInString(t[0])
		b, _ := utf8.DecodeRuneInString(t[1])
		a = unicode.ToUpper(a)
		b = unicode.ToUpper(b)
		p = append(p, fmt.Sprintf("%c. %c.", a, b))
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cmp(s, t []string) {
	assert(len(s) == len(t))
	for i := range s {
		assert(s[i] == t[i])
	}
}

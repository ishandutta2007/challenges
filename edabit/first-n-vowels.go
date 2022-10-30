/*

Write a function that returns the first n vowels of a string.

Examples

firstNVowels("sharpening skills", 3) ➞ "aei"

firstNVowels("major league", 5) ➞ "aoeau"

firstNVowels("hostess", 5) ➞ "invalid"

Notes

    Return "invalid" if the n exceeds the number of vowels in a string.
    Vowels are: a, e, i, o, u

*/

package main

import (
	"bytes"
	"strings"
	"unicode"
)

func main() {
	assert(fnv("sharpening skills", 3) == "aei")
	assert(fnv("major league", 5) == "aoeau")
	assert(fnv("crabby patty", 2) == "aa")
	assert(fnv("shrimp", 1) == "i")
	assert(fnv("shrimp", 2) == "invalid")
	assert(fnv("hostess", 5) == "invalid")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fnv(s string, n int) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		r = unicode.ToLower(r)
		if strings.IndexRune("aeiou", r) >= 0 {
			w.WriteRune(r)
		}
	}

	p := w.String()
	if n > len(p) {
		return "invalid"
	}
	return p[:n]
}

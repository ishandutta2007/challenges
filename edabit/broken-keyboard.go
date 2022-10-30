/*

Given what is supposed to be typed and what is actually typed, write a function that returns the broken key(s). The function looks like:

findBrokenKeys(correct phrase, what you actually typed)

Examples

findBrokenKeys("happy birthday", "hawwy birthday") ➞ ["p"]

findBrokenKeys("starry night", "starrq light") ➞ ["y", "n"]

findBrokenKeys("beethoven", "affthoif5") ➞ ["b", "e", "v", "n"]

Notes

    Broken keys should be ordered by when they first appear in the sentence.
    Only one broken key per letter should be listed.
    Letters will all be in lower case.

*/

package main

import (
	"unicode/utf8"
)

func main() {
	eq(brokenkeys("happy birthday", "hawwy birthday"), []rune{'p'})
	eq(brokenkeys("starry night", "starrq light"), []rune{'y', 'n'})
	eq(brokenkeys("beethoven", "affthoif5"), []rune{'b', 'e', 'v', 'n'})
	eq(brokenkeys("mozart", "aiwgvx"), []rune{'m', 'o', 'z', 'a', 'r', 't'})
	eq(brokenkeys("5678", "4678"), []rune{'5'})
	eq(brokenkeys("!!??$$", "$$!!??"), []rune{'!', '?', '$'})
}

func brokenkeys(s, t string) []rune {
	var p []rune
	m := make(map[rune]bool)
	for s != "" {
		a, x := utf8.DecodeRuneInString(s)
		b, y := utf8.DecodeRuneInString(t)
		if a != b && !m[a] {
			m[a] = true
			p = append(p, a)
		}
		s = s[x:]
		t = t[y:]
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(a, b []rune) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

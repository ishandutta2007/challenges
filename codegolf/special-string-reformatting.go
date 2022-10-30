/*

This challenge is to take an alphabetical string as input and to apply the following conversion:

The first of each type of character of the string must stay, and must be immediately followed by an integer representing how many of these characters were in the original string. Any repeating characters must be omitted.

All inputs will be entirely lower-case letters (no spaces). Outputs must be ordered in the same way as the inputs (input hi must give output of h1i1, not i1h1)

Examples

Input: potato Output: p1o2t2a1

Input: pqwertyuiop Output: p2q1w1e1r1t1y1u1i1o1

Input: thisisanexample Output: t1h1i2s2a2n1e2x1m1p1l1

Input: oreganoesque Output: o2r1e3g1a1n1s1q1u1

Input: aaaaaaabaaaaaa Output: a13b1

Scoring

This is code-golf. Shortest answer wins!

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(compress("potato") == "p1o2t2a1")
	assert(compress("pqwertyuiop") == "p2q1w1e1r1t1y1u1i1o1")
	assert(compress("thisisanexample") == "t1h1i2s2a2n1e2x1m1p1l1")
	assert(compress("oreganoesque") == "o2r1e3g1a1n1s1q1u1")
	assert(compress("aaaaaaabaaaaaa") == "a13b1")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func compress(s string) string {
	m := make(map[rune]int)
	p := []rune{}
	for _, r := range s {
		if m[r]++; m[r] == 1 {
			p = append(p, r)
		}
	}

	w := new(bytes.Buffer)
	for _, r := range p {
		fmt.Fprintf(w, "%c%d", r, m[r])
	}

	return w.String()
}

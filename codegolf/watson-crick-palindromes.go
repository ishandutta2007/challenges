/*

Problem

Create a function that can determine whether or not an arbitrary DNA string is a Watson-Crick palindrome. The function will take a DNA string and output a true value if the string is a Watson-Crick palindrome and a false value if it is not.
(True and False can also be represented as 1 and 0, respectively.)

The DNA string may either be in all uppercase or all lowercase depending on your preference.

Also, the DNA string will not be empty.
Explanation

A DNA string is a Watson-Crick palindrome when the complement of its reverse is equal to itself.

Given a DNA string, first reverse it, and then complement each character according to the DNA bases (A ↔ T and C ↔ G). If the original string is equal to the complemented-reverse string, it is a Watson-Crick palindrome.

For more, see this question. It is a different challenge where you must find the longest substring of a DNA string where that substring is a Watson-Crick palindrome.
Goal

This is code-golf and the shortest code wins.
Test Cases

The format is <input> = <output>.

ATCGCGAT = true
AGT = false
GTGACGTCAC = true
GCAGTGA = false
GCGC = true
AACTGCGTTTAC = false
ACTG = false

*/

package main

import "bytes"

func main() {
	assert(wcp("ATCGCGAT") == true)
	assert(wcp("AGT") == false)
	assert(wcp("GTGACGTCAC") == true)
	assert(wcp("GCAGTGA") == false)
	assert(wcp("GCGC") == true)
	assert(wcp("AACTGCGTTTAC") == false)
	assert(wcp("ACTG") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func wcp(s string) bool {
	return s == reverse(complement(s))
}

func reverse(s string) string {
	w := new(bytes.Buffer)
	for i := len(s) - 1; i >= 0; i-- {
		w.WriteByte(s[i])
	}
	return w.String()
}

func complement(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		switch r {
		case 'A':
			r = 'T'
		case 'T':
			r = 'A'
		case 'C':
			r = 'G'
		case 'G':
			r = 'C'
		}
		w.WriteRune(r)
	}
	return w.String()
}

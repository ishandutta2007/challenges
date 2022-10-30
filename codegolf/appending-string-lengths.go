/*

Challenge:

Given a string s on the characters a-z, A-Z, 0-9, append the length of s to itself, counting the additional character(s) in the length as part of the total length of s.

Input:

Just a string of arbitrary length (can be empty).
Output:

The same string, but with its length appended to the end. The characters that represent the length should also be counted as part of the length. In cases where there are multiple valid lengths to append, choose the smallest one possible (see test cases for examples).
Test Cases:

INPUT     -> OUTPUT       // Comment
aaa       -> aaa4
          -> 1            // Empty string
aaaaaaaa  -> aaaaaaaa9    // aaaaaaaa10 would also normally be valid, but violates using the smallest number rule mentioned above
aaaaaaaaa -> aaaaaaaaa11
a1        -> a13          // Input can contain numbers at the end of the string, you do not have to handle the fact that it looks like 13 rather than 3.

Longer test case(s):

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa -> aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa101
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa -> aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa102

Rules:

This is code-golf, so shortest code in bytes wins. Standard loopholes are forbidden. Submissions may be an entire program or a function, and you may either print the result to stdout or return it as a variable from a function.

*/

package main

import (
	"fmt"
	"unicode/utf8"
)

func main() {
	assert(strlen("aaa") == "aaa4")
	assert(strlen("") == "1")
	assert(strlen("aaaaaaaa") == "aaaaaaaa9")
	assert(strlen("aaaaaaaaa") == "aaaaaaaaa11")
	assert(strlen("a1") == "a13")
	assert(strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa101")
	assert(strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa102")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func strlen(s string) string {
	r := ""
	n := utf8.RuneCountInString(s)
	m := 0
	for {
		u := fmt.Sprintf("%d", n+m)
		m = n + len(u)

		t := fmt.Sprintf("%d", m)
		r = s + t

		if len(r) == m {
			break
		}
		m = len(r) - n
	}
	return r
}

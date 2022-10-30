/*

Write a function that groups a string into parentheses cluster. Each cluster should be balanced.
Examples

split("()()()") ➞ ["()", "()", "()"]

split("((()))") ➞ ["((()))"]

split("((()))(())()()(()())") ➞ ["((()))", "(())", "()", "()", "(()())"]

split("((())())(()(()()))") ➞ ["((())())", "(()(()()))"]

Notes

    All input strings will only contain parentheses.
	Balanced: Every opening parens ( must exist with its matching closing parens ) in the same cluster.

*/

package main

import (
	"strings"
)

func main() {
	cmp(split("()()()"), []string{"()", "()", "()"})
	cmp(split("((()))"), []string{"((()))"})
	cmp(split("((()))(())()()(()())"), []string{"((()))", "(())", "()", "()", "(()())"})
	cmp(split("((())())(()(()()))"), []string{"((())())", "(()(()()))"})
	cmp(split(""), []string{})
	cmp(split("()()(())"), []string{"()", "()", "(())"})
	cmp(split("(())(())"), []string{"(())", "(())"})
	cmp(split("((()))"), []string{"((()))"})
	cmp(split("()(((((((((())))))))))"), []string{"()", "(((((((((())))))))))"})
	cmp(split("((())()(()))(()(())())(()())"), []string{"((())()(()))", "(()(())())", "(()())"})
	cmp(split("((()))(())()()(()())"), []string{"((()))", "(())", "()", "()", "(()())"})
	cmp(split("((())())(()(()()))"), []string{"((())())", "(()(()()))"})
	cmp(split("(()(()()))()(((()))()(()))(()((()))(())())"), []string{"(()(()()))", "()", "(((()))()(()))", "(()((()))(())())"})
}

func split(s string) []string {
	var (
		t strings.Builder
		l []string
		p int
	)
	for _, r := range s {
		switch r {
		case '(':
			p++
		case ')':
			p--
		default:
			return nil
		}
		if p < 0 {
			return nil
		}

		t.WriteRune(r)
		if p == 0 {
			l = append(l, t.String())
			t.Reset()
		}
	}
	return l
}

func cmp(s, t []string) {
	assert(len(s) == len(t))
	for i := range s {
		assert(s[i] == t[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

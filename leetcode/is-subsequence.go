/*

Given a string s and a string t, check if s is subsequence of t.

 You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

 A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

*/

package main

import (
	"fmt"
	"unicode/utf8"
)

func main() {
	test("ace", "abcde")
	test("aec", "abcde")
	test("abc", "ahbgdc")
	test("axc", "ahbgdc")
	test("ahbgd", "ahbgdc")
	test("ahbgdc", "ahbgdc")
}

func test(s, t string) {
	var c csq
	c.build(t)
	fmt.Println(subseq(s, t), c.subseq(s))
}

func subseq(s, t string) bool {
	i, j := 0, 0
	for i < len(s) && j < len(t) {
		a, n := utf8.DecodeRuneInString(s[i:])
		b, m := utf8.DecodeRuneInString(t[j:])
		if a == b {
			i += n
		}
		j += m
	}
	return i == len(s)
}

type csq struct {
	m map[rune][]int
}

func (c *csq) build(t string) {
	c.m = make(map[rune][]int)
	for i, r := range t {
		c.m[r] = append(c.m[r], i)
	}
}

func (c *csq) find(i int, r rune) int {
	l := c.m[r]
	if len(l) == 0 {
		return -1
	}

	lo := 0
	hi := len(l) - 1
	if i <= l[lo] {
		return l[lo]
	}
	if i > l[hi] {
		return -1
	}

	for hi-lo != 1 {
		mid := lo + (hi-lo)/2
		if l[mid] < i {
			lo = mid
		} else {
			hi = mid
		}
	}
	return l[hi]
}

func (c *csq) subseq(s string) bool {
	i := 0
	for _, r := range s {
		i = c.find(i, r) + 1
		if i <= 0 {
			return false
		}
	}
	return true
}

/*

Create a function that takes two times of day (hours, minutes, seconds) and returns the amount of occurences of palendrome timestamps.

A palendrome timestamp should be read the same hours : minutes : seconds as seconds : minutes : hours, keeping in mind the second's and hour's digits will reverse. For example, 02 : 11 : 20 is a palendrome timestamp.

Examples

palendromeTimestamps(2, 12, 22, 4, 35, 10) ➞ 14

palendromeTimestamps(12, 12, 12, 13, 13, 13) ➞ 6

palendromeTimestamps(6, 33, 15, 9, 55, 10) ➞ 0

Notes

    Expect military time.
    Include the given time parameters if they happen to be palendromes.
    The parameter timestamps are chronological.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(palindromes(2, 12, 22, 4, 35, 10) == 14)
	assert(palindromes(12, 12, 12, 13, 13, 13) == 6)
	assert(palindromes(6, 33, 15, 9, 55, 10) == 0)
	assert(palindromes(11, 00, 11, 11, 00, 11) == 1)
	assert(palindromes(10, 22, 01, 12, 22, 21) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func palindromes(h1, m1, s1, h2, m2, s2 int) int {
	a := time.Date(0, time.January, 0, h1, m1, s1, 0, time.UTC)
	b := time.Date(0, time.January, 0, h2, m2, s2, 0, time.UTC)
	r := 0
	for {
		s := fmt.Sprintf("%02d%02d%02d", a.Hour(), a.Minute(), a.Second())
		if ispalindrome(s) {
			r++
		}
		a = a.Add(1 * time.Second)
		if a.After(b) {
			break
		}
	}
	return r
}

func ispalindrome(s string) bool {
	for i, n := 0, len(s); i < n/2; i++ {
		if s[i] != s[n-i-1] {
			return false
		}
	}
	return true
}

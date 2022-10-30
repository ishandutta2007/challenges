/*

Create a function that takes a string as an argument. The function must return a string containing 1s and 0s based on the string argument's words.
If any word in the argument is not equal to "zero" or "one" (case insensitive), you should ignore it.
The returned string's length should be a multiple of 8, if the string is not a multiple of 8 you should remove the numbers in excess.

Examples

textToNumberBinary("zero one zero one zero one zero one") ➞ "01010101"

textToNumberBinary("Zero one zero ONE zero one zero one") ➞ "01010101"

textToNumberBinary("zero one zero one zero one zero one one two") ➞ "01010101"

textToNumberBinary("zero one zero one zero one zero three") ➞ ""

textToNumberBinary("one one") ➞ ""

Notes

You must return the result as a string.

*/

package main

import (
	"strings"
)

func main() {
	assert(txt2bin("one one one one zero zero zero zero") == "11110000")
	assert(txt2bin("one Zero zero one zero zero one one one one one zero oNe one one zero one zerO") == "1001001111101110")
	assert(txt2bin("one zero one") == "")
	assert(txt2bin("one zero zero one zero ten one one one one two") == "10010111")
	assert(txt2bin("One zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero one one one zero one one zero zero zero zero one zero") == "1001011101100001011101100001011101100001011101100001011101100001")
	assert(txt2bin("TWO one zero one one zero one zero") == "")
	assert(txt2bin("TWO one zero one one zero one zero one") == "10110101")
}

func txt2bin(s string) string {
	p := new(strings.Builder)
	t := strings.Split(s, " ")
	for _, t := range t {
		switch strings.ToLower(t) {
		case "zero":
			p.WriteRune('0')
		case "one":
			p.WriteRune('1')
		}
	}
	r := p.String()
	r = r[:len(r)&^7]
	return r
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

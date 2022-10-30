/*

Create a function that takes a single character as an argument and returns the char code of its lowercased / uppercased counterpart.
Examples

Given that:
  - "A" char code is: 65
  - "a" char code is: 97

counterpartCharCode("A") ➞ 97

counterpartCharCode("a") ➞ 65

Notes

    The argument will always be a single character.
    Not all inputs will have a counterpart (e.g. numbers), in which case return the inputs char code.

*/

package main

import (
	"unicode"
)

func main() {
	assert(cpc('a') == 65)
	assert(cpc('A') == 97)
	assert(cpc('l') == 76)
	assert(cpc('L') == 108)
	assert(cpc('z') == 90)
	assert(cpc('Z') == 122)
	assert(cpc('è') == 200)
	assert(cpc('È') == 232)
	assert(cpc('Œ') == 339)
	assert(cpc('œ') == 338)
	assert(cpc('Ⱥ') == 11365)
	assert(cpc('ⱥ') == 570)
	assert(cpc('5') == 53)
	assert(cpc('$') == 36)
}

func cpc(r rune) rune {
	if unicode.IsLower(r) {
		return unicode.ToUpper(r)
	}
	return unicode.ToLower(r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

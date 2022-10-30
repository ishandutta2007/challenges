/*

Create a function that takes a string road and returns the car that's in first place. The road will be made of "=", and cars will be represented by letters in the alphabet.

Examples
firstPlace("====b===O===e===U=A==") ➞ "A"

firstPlace("e==B=Fe") ➞ "e"

firstPlace("proeNeoOJGnfl") ➞ "l"

Notes
Return "No car available" if there is no car on the road and "No road available" if there is no road.

*/

package main

import (
	"fmt"
	"unicode"
)

func main() {
	assert(firstplace("====b===O===e===U=A==") == "A")
	assert(firstplace("e==B=Fe") == "e")
	assert(firstplace("proeNeoOJGnfl") == "l")
	assert(firstplace("F=============") == "F")
	assert(firstplace("C===A===R") == "R")
	assert(firstplace("p") == "p")
	assert(firstplace("==========================") == "No car available")
	assert(firstplace("") == "No road available")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func firstplace(s string) string {
	n := 0
	m := 0
	p := rune(0)
	for _, r := range s {
		switch {
		case r == '=':
			n += 1
		case isalpha(r):
			m += 1
			p = r
		default:
			return "Invalid"
		}
	}
	if s == "" || (n == 0 && m != len(s)) {
		return "No road available"
	}
	if p == 0 {
		return "No car available"
	}
	return fmt.Sprintf("%c", p)
}

func isalpha(r rune) bool {
	r = unicode.ToLower(r)
	return 'a' <= r && r <= 'z'
}

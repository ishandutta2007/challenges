/*

Given a number between 1-26, return what letter is at that position in the alphabet. Return "invalid" if the number given is not within that range, or isn't an integer.
Examples

letterAtPosition(1) ➞ "a"

letterAtPosition(26.0) ➞ "z"

letterAtPosition(0) ➞ "invalid"

letterAtPosition(4.5) ➞ "invalid"

Notes

    Return a lowercase letter.
    Numbers that end with ".0" are valid.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	assert(letterpos(1) == "a")
	assert(letterpos(2) == "b")
	assert(letterpos(3) == "c")
	assert(letterpos(4) == "d")
	assert(letterpos(5) == "e")
	assert(letterpos(6) == "f")
	assert(letterpos(7) == "g")
	assert(letterpos(8) == "h")
	assert(letterpos(9) == "i")
	assert(letterpos(10) == "j")
	assert(letterpos(11) == "k")
	assert(letterpos(12) == "l")
	assert(letterpos(13) == "m")
	assert(letterpos(14) == "n")
	assert(letterpos(15) == "o")
	assert(letterpos(16) == "p")
	assert(letterpos(17) == "q")
	assert(letterpos(18) == "r")
	assert(letterpos(19) == "s")
	assert(letterpos(20) == "t")
	assert(letterpos(21) == "u")
	assert(letterpos(22) == "v")
	assert(letterpos(23) == "w")
	assert(letterpos(24) == "x")
	assert(letterpos(25) == "y")
	assert(letterpos(26) == "z")
	assert(letterpos(0) == "invalid")
	assert(letterpos(4.5) == "invalid")
	assert(letterpos(4.0) == "d")
	assert(letterpos(1.0) == "a")
	assert(letterpos(26.0) == "z")
}

func letterpos(p float64) string {
	i, f := math.Modf(p)
	if f != 0 || !(1 <= i && i <= 26) {
		return "invalid"
	}
	return fmt.Sprintf("%c", 'a'+int(i)-1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

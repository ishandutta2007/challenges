/*

Create a regular expression to check whether the given string is a valid floating numeric character or not.

Examples

isFloatingCharacter("12.12") ➞ true

isFloatingCharacter("12.") ➞ false

isFloatingCharacter(".1") ➞ true

isFloatingCharacter("-.1") ➞ true

isFloatingCharacter("abc") ➞ false

Notes

    All inputs are strings.
    Think about RegExp.prototype.test().

*/

package main

import (
	"math/big"
	"strconv"
)

func main() {
	assert(isfloatchar("-12.12") == true)
	assert(isfloatchar("-.12") == true)
	assert(isfloatchar("0.12") == true)
	assert(isfloatchar(".122332") == true)
	assert(isfloatchar("av0.12") == false)
	assert(isfloatchar("-.") == false)
	assert(isfloatchar("+") == false)
	assert(isfloatchar("12") == false)
	assert(isfloatchar(".1") == true)
	assert(isfloatchar("-.1") == true)
	assert(isfloatchar("abc") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func isfloatchar(s string) bool {
	x, err := strconv.ParseFloat(s, 64)
	if err != nil {
		return false
	}

	f := big.NewFloat(x)
	return !f.IsInt()
}

/*

Create a function that takes a fractional number as a string for its argument and returns its half.

Examples

fractionHalf("1/2") ➞ "1/4"

fractionHalf("6/8") ➞ "3/8"

fractionHalf("3/8") ➞ "3/16"

Notes

Always return the simplified fraction (reduced to its lowest terms).

*/

package main

import (
	"math/big"
)

func main() {
	assert(half("1/2") == "1/4")
	assert(half("2/3") == "1/3")
	assert(half("3/8") == "3/16")
	assert(half("39/46") == "39/92")
	assert(half("52/97") == "26/97")
	assert(half("6/8") == "3/8")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func half(s string) string {
	x := new(big.Rat)
	x.SetString(s)
	x.Quo(x, big.NewRat(2, 1))
	return x.String()
}

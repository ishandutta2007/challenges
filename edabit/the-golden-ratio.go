/*

The golden ratio is ubiquitous in math, science, art, and nature.
This challenge is concerned with the number itself, which is 1.618033988 to 10 significant digits.
Implement a function that calculates the golden ratio to 100 significant digits using only integers, strings and basic arithmetic operations: +, -, *, //

Examples

golden_ratio() ➞ 1.618033988+90 more decimal places

Notes

This function has no argument so naturally there is only one test case.

*/

package main

import (
	"math/big"
)

func main() {
	assert(goldenratio() == "1.618033988749894848204586834365638117720309179805762862135448622705260462818902449707207204189391137")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://nrich.maths.org/2737
// phi[n+1] = 1 + 1/phi[n]
// phi[0] = 1
func goldenratio() string {
	p := big.NewRat(1, 1)
	for i := 0; i < 256; i++ {
		r := big.NewRat(1, 1)
		r.Add(r, p.Inv(p))
		p = r
	}
	return p.FloatString(99)
}

/*

A Harshad number is a number which is divisible by the sum of its digits. For example, 132 is divisible by 6 (1+3+2).

A subset of the Harshad numbers are the Moran numbers. Moran numbers yield a prime when divided by the sum of their digits. For example, 133 divided by 7 (1+3+3) yields 19, a prime.

Create a function that takes a number and returns "M" if the number is a Moran number, "H" if it is a (non-Moran) Harshad number, or "Neither".
Examples

moran(132) ➞ "H"

moran(133) ➞ "M"

moran(134) ➞ "Neither"

Notes

N/A

*/

package main

import (
	"math"
)

func main() {
	assert(moran(132) == "H")
	assert(moran(133) == "M")
	assert(moran(134) == "Neither")
	assert(moran(3033) == "M")
	assert(moran(3030) == "H")
	assert(moran(491423) == "Neither")
	assert(moran(20937) == "M")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func moran(n uint) string {
	v := sum(n)
	if n%v != 0 {
		return "Neither"
	}
	if n /= v; isprime(n) {
		return "M"
	}
	return "H"
}

func sum(n uint) uint {
	r := uint(0)
	for {
		r += n % 10
		if n /= 10; n == 0 {
			break
		}
	}
	return r
}

func isprime(n uint) bool {
	if n < 2 {
		return false
	}

	l := math.Sqrt(float64(n))
	for i := uint(2); i <= uint(l); i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

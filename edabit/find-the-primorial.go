/*

A Primorial is a product of the first n prime numbers (e.g. 2 x 3 x 5 = 30). 2, 3, 5, 7, 11, 13 are prime numbers.
If n was 3, you'd multiply 2 x 3 x 5 = 30 or Primorial = 30.

Create a function that returns the Primorial of a number.

Examples

primorial(1) ➞ 2

primorial(2) ➞ 6

primorial(8) ➞ 9699690

Notes

N/A

*/

package main

import (
	"math"
)

func main() {
	assert(primorial(0) == 1)
	assert(primorial(1) == 2)
	assert(primorial(2) == 6)
	assert(primorial(3) == 30)
	assert(primorial(8) == 9699690)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A002110
func primorial(n uint) uint {
	p := eratosthenes((n + 1) * (n + 1))
	r := uint(1)
	for i := uint(0); i < n; i++ {
		r *= p[i]
	}
	return r
}

func eratosthenes(n uint) []uint {
	l := uint(math.Sqrt(float64(n)))
	p := make([]bool, n)
	for i := uint(2); i <= l; i++ {
		for j := i + i; j < n; j += i {
			p[j] = true
		}
	}

	var r []uint
	for i := uint(2); i < n; i++ {
		if !p[i] {
			r = append(r, i)
		}
	}
	return r
}

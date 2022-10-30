/*

A positive number's population is the number of 1s in its binary representation. An evil number has an even numbered population, whereas an odious number has an odd numbered population.
Moreover, a number is pernicious if its population is a prime number.

Create a function that takes a number as an argument and returns a sorted array of all its descriptors ("Evil", "Odious", or "Pernicious").
Examples

howBad(7) ➞ ["Odious", "Pernicious"]
// binary = 111

howBad(17) ➞ ["Evil", "Pernicious"]
// binary = 10001

howBad(23) ➞ ["Evil"]
// binary = 10111

Notes

Notice how the example "111" is shown as a prime but in base-10, "111" isn't prime (37 * 3). Convert it back to a "7", and it is.

*/

package main

import (
	"math"
	"math/bits"
)

func main() {
	eq(howbad(7), []string{"Odious", "Pernicious"})
	eq(howbad(17), []string{"Evil", "Pernicious"})
	eq(howbad(23), []string{"Evil"})
	eq(howbad(97), []string{"Odious", "Pernicious"})
	eq(howbad(66), []string{"Evil", "Pernicious"})
	eq(howbad(77), []string{"Evil"})
	eq(howbad(128), []string{"Odious"})
	eq(howbad(666), []string{"Odious", "Pernicious"})
	eq(howbad(987654321), []string{"Odious", "Pernicious"})
	eq(howbad(98765), []string{"Evil"})
}

func howbad(n uint) []string {
	var p []string

	b := bits.OnesCount(n)
	if b&1 != 0 {
		p = append(p, "Odious")
	} else {
		p = append(p, "Evil")
	}

	if isprime(uint(b)) {
		p = append(p, "Pernicious")
	}

	return p
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

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(a, b []string) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

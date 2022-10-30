/*

Write a function that takes a number and returns True if it's a prime; False otherwise.
The number can be 2^64-1 (2 to the power of 63, not XOR). With the standard technique it would be O(2^64-1),
which is much too large for the 10 second time limit imposed by Edabit.

Sieve of Eratosthenes

Examples

prime(7) ➞ True

prime(56963) ➞ True

prime(5151512515524) ➞ False

Notes

A "prime" number is a number that can only be divided by itself and 1 (upon division the result is a whole number).

*/

package main

import (
	"math"
	"math/big"
)

func main() {
	assert(prime(7) == true)
	assert(prime(5) == true)
	assert(prime(12) == false)
	assert(prime(777771) == false)
	assert(prime(207971) == true)
	assert(prime(100000074281) == true)
	assert(prime(100000074282) == false)
	assert(prime(777777777777777) == false)
	assert(prime(math.MaxUint64) == false)
	assert(prime(math.MaxUint32) == false)
	assert(prime((1<<31)-1) == true)
	assert(prime((1<<19)-1) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func prime(n uint64) bool {
	x := new(big.Int)
	x.SetUint64(n)
	return x.ProbablyPrime(100)
}

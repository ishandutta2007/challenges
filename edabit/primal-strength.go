/*

In number theory, a prime number is balanced if it is equidistant from the prime before it and the prime after it.
It is therefore the arithmetic mean of those primes. For example, 5 is a balanced prime, two units away from 3, and two from 7.
211 is 12 units away from the previous prime, 199, and 12 away from the next, 223.

A prime that is greater than the arithmetic mean of the primes before and after it is called a strong prime.
It is closer to the prime after it than the one before it. For example, the strong prime 17 is closer to 19 than it is to 13 (see note at bottom).

A prime that is lesser than the arithmetic mean of the primes before and after it is called weak prime. For example, 19.

Create a function that takes a prime number as input and returns "Strong" if it is a strong prime, "Weak" if it is a weak prime, or "Balanced".
Examples

primalStrength(211) ➞ "Balanced"

primalStrength(17) ➞ "Strong"

primalStrength(19) ➞ "Weak"

Notes

This definition of strong primes is not to be confused with strong primes as defined in cryptography, which are much more complicated than this. You are all welcome to make a challenge based on cryptographically strong primes.

*/

package main

import (
	"math"
	"sort"
)

func main() {
	assert(primal(2) == "Strong")
	assert(primal(3) == "Weak")
	assert(primal(5) == "Balanced")
	assert(primal(211) == "Balanced")
	assert(primal(593) == "Balanced")
	assert(primal(1693) == "Strong")
	assert(primal(599) == "Strong")
	assert(primal(2203) == "Strong")
	assert(primal(19) == "Weak")
	assert(primal(2971) == "Weak")
	assert(primal(1493) == "Weak")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func primal(n uint) string {
	if n < 2 {
		return "Invalid"
	}
	if n == 2 {
		return "Strong"
	}

	l := float64(2*n) * math.Log(float64(n))
	p := sieve(uint(l), n)
	i := sort.Search(len(p), func(i int) bool { return p[i] >= n })
	if i >= len(p) {
		return "Invalid"
	}

	a := p[i+1] - p[i]
	b := p[i] - p[i-1]
	if a < b {
		return "Strong"
	}
	if a == b {
		return "Balanced"
	}
	return "Weak"
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

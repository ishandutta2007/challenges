/*

A semiprime is a composite number that is the product of two primes. Apart from these two primes, its only other proper (non-self) divisor is 1.

The two prime factors of a semiprime can be the same number (e.g. the semiprime 49 is the product of 7x7). A semiprime that has two distinct prime factors is called a squarefree semiprime.

Create a function that takes a number and returns "Squarefree Semiprime", "Semiprime", or "Neither".

Examples

semiprime(49) ➞ "Semiprime"

semiprime(15) ➞ "Squarefree Semiprime"

semiprime(97) ➞ "Neither"

Notes

N/A

*/

package main

func main() {
	assert(semiprimes(49) == "Semiprime")
	assert(semiprimes(15) == "Squarefree Semiprime")
	assert(semiprimes(97) == "Neither")
	assert(semiprimes(19) == "Neither")
	assert(semiprimes(75) == "Neither")
	assert(semiprimes(169) == "Semiprime")
	assert(semiprimes(203) == "Squarefree Semiprime")
	assert(semiprimes(177) == "Squarefree Semiprime")
	assert(semiprimes(125) == "Neither")
	assert(semiprimes(70) == "Neither")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func semiprimes(n uint64) string {
	p := factor(n)
	if len(p) != 2 {
		return "Neither"
	}
	if p[0] != p[1] {
		return "Squarefree Semiprime"
	}
	return "Semiprime"
}

func factor(n uint64) (f []uint64) {
	if n == 1 {
		return []uint64{1}
	}
	for i := uint64(2); i <= n; i++ {
		for n%i == 0 {
			n /= i
			f = append(f, i)
		}
	}
	return
}

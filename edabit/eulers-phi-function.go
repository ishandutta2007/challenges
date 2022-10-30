/*

The Euler's phi function (from the Greek letter φ, also called Euler's totient function) counts the positive integers that are coprime of a given number n, from 1 to n - 1.
Two numbers are coprime when their greater common divisor is equal to 1. Look at the example below.

divisors of 6 ➞ [1, 2, 3, 6]

divisors of 5 ➞ [1, 5] ➞ g.c.d. = 1
divisors of 4 ➞ [1, 2, 4] ➞ g.c.d. = 2
divisors of 3 ➞ [1, 3] ➞ g.c.d. = 3
divisors of 2 ➞ [1, 2] ➞ g.c.d. = 2
divisors of 1 ➞ [1] ➞ g.c.d. = 1

1 and 5 are coprime of 6 ➞ phi(6) = 2

Implement a phi function that returns the count of coprime integers of a given positive integer n.
Examples

phi(1) ➞ 1

phi(3) ➞ 2

phi(8) ➞ 4

Notes

    1 is trivially coprime of every number.
    You can also proceed to obtain prime factors of an integer instead of all its positive divisors, just remember that 1 is present in any case despite is not prime.

*/

package main

func main() {
	assert(phi(1) == 1)
	assert(phi(3) == 2)
	assert(phi(9) == 6)
	assert(phi(19) == 18)
	assert(phi(33) == 20)
	assert(phi(51) == 32)
	assert(phi(54) == 18)
	assert(phi(86) == 42)
	assert(phi(144) == 48)
	assert(phi(209) == 180)
	assert(phi(666) == 216)
	assert(phi(1000) == 400)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Euler%27s_totient_function
func phi(n uint64) uint64 {
	if n <= 1 {
		return 1
	}

	r := uint64(1)
	p := factor(n)
	for i := 0; i < len(p); {
		j := i + 1
		u := p[i]
		for ; j < len(p) && p[i] == p[j]; j++ {
			u *= p[i]
		}

		r *= (u / p[i]) * (p[i] - 1)
		i = j
	}
	return r
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

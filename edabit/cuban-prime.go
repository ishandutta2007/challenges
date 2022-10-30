/*

Create a function to check whether a given number is Cuban Prime. A cuban prime is a prime number that is a solution to one of two different specific equations involving third powers of x and y.
For this challenge we are only concerned with the cuban numbers from the first equation. We ignore the cuban numbers from the second equation.

Equation Form

p = (x^3 - y^3)/(x - y), x  = y + 1, y > 0

... and the first few cuban primes from this equation are 7, 19, 37, 61, 127, 271.
Examples

cuban_prime(7) ➞ "7 is cuban prime"

cuban_prime(9) ➞ "9 is not cuban prime"

cuban_prime(331) ➞ "331 is cuban prime"

cuban_prime(40) ➞ "40 is not cuban prime"

Notes

    The inputs are positive integers only.
    Check the Resources for help.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	assert(cubanprime(7) == "7 is cuban prime")
	assert(cubanprime(11) == "11 is not cuban prime")
	assert(cubanprime(40) == "40 is not cuban prime")
	assert(cubanprime(15) == "15 is not cuban prime")
	assert(cubanprime(271) == "271 is cuban prime")
	assert(cubanprime(919) == "919 is cuban prime")
	assert(cubanprime(1801) == "1801 is cuban prime")
	assert(cubanprime(30) == "30 is not cuban prime")
	assert(cubanprime(721) == "721 is not cuban prime")
	assert(cubanprime(217) == "217 is not cuban prime")
	assert(cubanprime(4447) == "4447 is cuban prime")
	assert(cubanprime(8269) == "8269 is cuban prime")
	assert(cubanprime(9241) == "9241 is cuban prime")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://planetmath.org/cubanprime
// https://oeis.org/A002407
func cubanprime(n int) string {
	i := binsearch(n, seq)
	if p := seq(i); p == n && isprime(p) {
		return fmt.Sprintf("%d is cuban prime", n)
	}
	return fmt.Sprintf("%d is not cuban prime", n)
}

func seq(n int) int {
	return 3*n*n + 3*n + 1
}

func binsearch(n int, f func(n int) int) int {
	if n <= 0 {
		return 0
	}

	lo := 0
	hi := n
	for hi-lo != 1 {
		mid := lo + (hi-lo)/2
		if f(mid) < n {
			lo = mid
		} else {
			hi = mid
		}
	}
	return hi
}

func isprime(n int) bool {
	if n < 2 {
		return false
	}

	l := int(math.Sqrt(float64(n)))
	for i := 2; i <= int(l); i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

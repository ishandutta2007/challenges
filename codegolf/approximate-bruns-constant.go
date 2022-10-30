/*

Brun's constant is the value to which the sum of the reciprocals of twin prime pairs (1/p and 1/(p+2) where p and p+2 are both prime) converges. It is approximately 1.902160583104.

Given a positive integer N, approximate Brun's constant by summing the reciprocals of the twin prime pairs where both primes in the pair are less than N, and output the approximation.

Rules
N will be a positive integer within the representable range for your language.
The output must be as accurate as possible to the true value, within the limits of your language's floating-point implementation, ignoring any potential issues due to floating-point arithmetic inaccuracies.
If your language is capable of arbitrary-precision arithmetic, it must be at least as precise as IEEE 754 double-precision arithmetic.
Alternatively, an exact fraction may be output in any consistent, unambiguous format.
If a prime appears in multiple twin prime pairs (e.g. 5, part of both (3, 5) and (5, 7)), its reciprocal contributes to the sum each time.
Test Cases
2 -> 0
6 -> 0.5333333333333333
10 -> 0.8761904761904762
13 -> 0.8761904761904762
100 -> 1.3309903657190867
620 -> 1.4999706034568274
100000 -> 1.67279958482774

*/

package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	test(2, 0)
	test(6, 0.5333333333333333)
	test(10, 0.8761904761904762)
	test(13, 0.8761904761904762)
	test(100, 1.3309903657190867)
	test(620, 1.4999706034568274)
	test(100000, 1.67279958482774)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int64, r float64) {
	v := bruns(n)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-12)
}

// https://en.wikipedia.org/wiki/Brun%27s_theorem
func bruns(n int64) float64 {
	r := new(big.Rat)
	for i := int64(2); i+2 < n; i++ {
		if isprime(i) && isprime(i+2) {
			x := big.NewRat(1, i)
			y := big.NewRat(1, i+2)
			r.Add(r, x)
			r.Add(r, y)
		}
	}
	v, _ := r.Float64()
	return v
}

func isprime(n int64) bool {
	x := big.NewInt(n)
	return x.ProbablyPrime(2)
}

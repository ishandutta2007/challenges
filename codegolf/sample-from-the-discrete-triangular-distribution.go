/*

Given an integer n >= 1 as input, output a sample from the discrete triangular distribution over the integers k, for 1 <= k <= n (1 <= k < n is also acceptable), defined by p(k) ∝ k.
Your code should take constant expected time, but you are allowed to ignore overflow, to treat floating point operations as exact, and to use a PRNG.

This is code golf, so the shortest answer wins.

*/

package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 100; i++ {
		fmt.Println(sample(i))
	}
}

/*

@Arnauld:
How?
We essentially pick a random integer in [1..Sum[k=1 to n]] and then return the corresponding term in the sequence 1,2,2,3,3,3,4,4,4,4,… (this is A002024).

A more readable form of the formula is:

floor(sqrt(2 * floor(rand()*n*(n+1)/2 + 1)) + 1/2)

where rand() is assumed to return a random value drawn from the uniform distribution in the interval [0, 1]

*/

func sample(n int) int {
	N := float64(n)
	x := rand.Float64()*N*((N+1)/2) + 1
	r := math.Sqrt(2*math.Floor(x)) + 0.5
	return int(r)
}

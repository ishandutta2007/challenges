/*

Imagine you are given a function flip() that returns a random bit (0 or 1 with equal probability).
Write a program that uses flip to generate a random number in the range 0...N-1 such that each of the N numbers is generated with equal probability.
For instance, if your program is run with N = 6, then it will generate the number 0, 1, 2, 3, 4, or 5 with equal probability.

N can be any integer >= 2.

Pseudocode is okay.

You're not allowed to use rand or anything that maintains state other than flip.

Thanks to Cosmologicon for posting this challenge to r/dailyprogrammer_ideas!

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
	test(6, 1e6)
	test(10, 1e4)
	test(50, 1e6)
	test(100, 1e6)
}

func test(n, t int) {
	h := make([]float64, n)
	for i := 0; i < t; i++ {
		h[random(n)]++
	}
	for i := range h {
		h[i] /= float64(t)
	}

	fmt.Println(n, 1/float64(n))
	fmt.Println(h)
	fmt.Println()
}

func random(n int) int {
	r := n
	for r >= n {
		r = 0
		j := int(math.Ceil(math.Log2(float64(n))))
		for i := 0; i < j; i++ {
			r = (r << 1) + flip()
		}
	}
	return r
}

func flip() int {
	return rand.Intn(2)
}

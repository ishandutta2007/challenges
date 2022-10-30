/*

Left in sandbox for at least 3 days.

I want to verify if this inequality is true:

for n≥4, if a1,a2,a3,…,an∈R+∪{0} and ∑ni=1ai=1, then a1a2+a2a3+a3a4+⋯+an−1an+ana1≤1/4.
Challenge

Write a piece of program which takes an integer n as input. It does the following:

    Generate a random array a which consists of n non-negative reals. The sum of all elements should be 1.

    By saying random, I mean, every array satisfiying the requirements in 2 should have a non-zero probability of occurrence. It don't need to be uniform. See this related post.

    Calculate a[0]a[1]+a[1]a[2]+a[2]a[3]+...+a[n-2]a[n-1]+a[n-1]a[0].

    Output the sum and the array a.

    For I/O forms see this post.

Rules

(Sorry for the late edit...) All numbers should be rounded to at least 10−4.

Standard loopholes should be forbidden.
Example

The following code is an ungolfed Python code for this challenge, using library numpy. (For discussion about using libraries, see This Link.)

import numpy as np


def inequality(n):
    if n < 4:
       raise Exception
    a = np.random.rand(n)
    sum_a = 0
    for i in range(n):
        sum_a += a[i]
    for i in range(n):
        a[i] /= sum_a
    sum_prod = 0
    for i in range(n):
       sum_prod += a[i % n] * a[(i + 1) % n]
    print(a)
    return sum_prod, a

Tip

You could assume that input n is a positive integer greater than 3.

Your score is the bytes in your code. The one with the least score wins.

*/

package main

import (
	"math"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for n := 4; n < 10000; n++ {
		for i := 0; i < 10; i++ {
			p, a := inequality(n)
			assert(p < 0.25)
			assert(math.Abs(1-sum(a)) < 1e-8)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func inequality(n int) (float64, []float64) {
	a := random(n)
	p := 0.0
	for i := 0; i < n; i++ {
		p += a[i%n] * a[(i+1)%n]
	}
	return p, a
}

func random(n int) []float64 {
	r := make([]float64, n)
	t := 0.0
	for i := 0; i < n; i++ {
		r[i] = rand.Float64()
		t += r[i]
	}
	for i := range r {
		r[i] /= t
	}
	return r
}

func sum(a []float64) float64 {
	r := 0.0
	for i := range a {
		r += a[i]
	}
	return r
}

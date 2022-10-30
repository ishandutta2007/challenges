/*

Given a positive integer n, randomly output n non negative integers that sum to one hundred. n will be at most 200. The output should be present as a list of integers (not sorted).

Your random sample should be uniformly sampled from all lists of n non negative integers that sum to one hundred.

Your code should run in a reasonable amount of time (e.g. should terminate on TIO) for n less than a 200. This is just to prevent brute force solutions.

Examples
If n=1 the code should always output 100

If n=2 the code should output 100,0 or 99,1 or 98,2 or 97,3 ... or 2,98 or 1,99 or 0,100 with equal probability. There are 101 different possible outputs in this case.

If n>100 then some of the values in the output will necessarily be 0.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 1; i <= 15; i++ {
		test(i)
	}
	test(100)
	test(200)
}

func test(n int) {
	p := sample(n)
	fmt.Println(n, p)
	assert(len(p) == n)
	assert(sum(p) == 100)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sum(a []int) int {
	r := 0
	for _, v := range a {
		r += v
	}
	return r
}

func sample(n int) []int {
	if n <= 0 {
		return nil
	}

	r := [][]int{}
	m := n
	if n >= 14 {
		m = 1 + rand.Intn(13)
	}

	gen(m, 1, 0, 100, []int{}, &r)

	i := rand.Intn(len(r))
	p := r[i]
	rand.Shuffle(len(p), func(i, j int) {
		p[i], p[j] = p[j], p[i]
	})

	p = append(p, make([]int, n-m)...)

	return p
}

func gen(n, s, v, t int, l []int, r *[][]int) {
	if v > t || len(l) > n {
		return
	}

	if v == t && len(l) == n {
		*r = append(*r, append([]int{}, l...))
		return
	}

	for i := s; i <= t; i++ {
		gen(n, i+1, v+i, t, append(l, i), r)
	}
}

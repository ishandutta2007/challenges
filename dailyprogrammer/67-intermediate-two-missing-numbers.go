/*

You are given a list of 999,998 integers, which include all the integers between 1 and 1,000,000 (inclusive on both ends) in some unknown order, with the exception of two numbers which have been removed.
By making only one pass through the data and using only a constant amount of memory (i.e. O(1) memory usage), can you figure out what two numbers have been excluded?

Note that since you are only allowed one pass through the data, you are not allowed to sort the list!

EDIT: clarified problem

Thanks to Cosmologicon for suggesting this problem at r/dailyprogrammer_ideas? Do you have a problem you think would be good for us? Why not head over there and suggest it?

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
	test(1e6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int) {
	if n < 3 {
		return
	}

	v := perm(n)
	x, y := missing(v[:n-2])
	fmt.Println(x, y)
	assert(max(x, y) == max(v[n-1], v[n-2]))
	assert(min(x, y) == min(v[n-1], v[n-2]))
}

/*

The idea is to use the sum of natural numbers and sum of squares formula to calculate the total number.
If we subtract all the numbers in the list out from the total number, the remaining values represents the constraints that the two missing number have to add up to.
This leads to a quadratic equation where the roots are the missing numbers.

*/
func missing(v []int64) (x, y int64) {
	n := int64(len(v)) + 2
	if n < 3 {
		return
	}

	a := n * (n + 1) / 2
	b := n * (n + 1) * (2*n + 1) / 6
	for i := range v {
		a -= v[i]
		b -= v[i] * v[i]
	}

	s := isqrt(2*b - a*a)
	x = (a + s) / 2
	y = (a - s) / 2
	return
}

func perm(n int) []int64 {
	p := rand.Perm(n)
	r := make([]int64, n)
	for i := range r {
		r[i] = int64(p[i]) + 1
	}
	return r
}

func isqrt(x int64) int64 {
	return int64(math.Sqrt(float64(x)))
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

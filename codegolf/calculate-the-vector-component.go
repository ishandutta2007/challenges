/*

Challenge

Assume two vectors a=(a1,a2,⋯,an) and b=(b1,b2,⋯,bn) are given in an n-dimensional space, where at least one of b1,⋯,bn is nonzero.
Then a can be uniquely decomposed into two vectors, one being a scalar multiple of b and one perpendicular to b

a=bx+b⊥, where b⊥⋅b=0.

Given a
and b as input, find the value of x.

This can be also thought of as the following: Imagine a line passing through the origin and the point b.
Then draw a perpendicular line on it that passes through the point a, and denote the intersection c.
Finally, find the value of x that satisfies c=bx.

You can use an explicit formula too (thanks to @xnor), which arises when calculating the projection:

x=a⋅bb⋅b

Standard code-golf rules apply. The shortest code in bytes wins.

Example

Here is an example in 2D space, where a=(2,7) and b=(3,1). Observe that (2,7) = (3.9,1.3) + (-1.9,5.7) where (3.9,1.3) is equal to 1.3b and (-1.9,5.7) is perpendicular to b. Therefore, the expected answer is 1.3.

enter image description here
Test cases

a         b          answer
(2,7)     (3,1)      1.3
(2,7)     (-1,3)     1.9
(3,4,5)   (0,0,1)    5
(3,4,5)   (1,1,1)    4
(3,4,5)   (1,-1,-1)  -2
(3,4,5,6) (1,-2,1,2) 1.2

*/

package main

import "math"

func main() {
	test([]int{2, 7}, []int{3, 1}, 1.3)
	test([]int{2, 7}, []int{-1, 3}, 1.9)
	test([]int{3, 4, 5}, []int{0, 0, 1}, 5)
	test([]int{3, 4, 5}, []int{1, 1, 1}, 4)
	test([]int{3, 4, 5}, []int{1, -1, -1}, -2)
	test([]int{3, 4, 5, 6}, []int{1, -2, 1, 2}, 1.2)
}

func test(a, b []int, r float64) {
	p := projection(a, b)
	assert(math.Abs(p-r) < 1e-6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func projection(a, b []int) float64 {
	return dot(a, b) / dot(b, b)
}

func dot(a, b []int) float64 {
	r := 0.0
	for i := range a {
		r += float64(a[i] * b[i])
	}
	return r
}

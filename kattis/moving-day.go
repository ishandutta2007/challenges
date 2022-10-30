/*

It’s that time of the year when students head back to school, which will usually involve moving lots of stuff, and packing lots of that stuff into boxes.
However, before we go through that effort, it would be nice to know whether the boxes we have are the right size!

A box has three dimensions, l, w, and h, and a box’s volume v is simply l⋅w⋅h.
We have many small items to pack, and we don’t care about their exact geometry: we know that, as long as a box has a volume of, at least, V,
we will be able to pack all those items into that single box.
So, given a box i, and its volume vi, then the difference di=vi−V can tell us whether the box is big enough or not to pack all the items.
If di is greater than or equal to zero, the box is big enough; otherwise, the box is too small.

So, we want to answer a simple question: given multiple boxes, is the largest box (by volume) large enough to store all our items?
For example, suppose V=10 and we have three boxes, A, B, and C, with dimensions (1,1,2), (2,2,2), and (3,2,1), respectively.
Their volumes will be vA=2, vB=8, and vC=6, which means the largest box is B. Unfortunately, dB=vB−V=8−10=−2, which means our largest box is not large enough.

On the other hand, suppose V=980, and we had four boxes, W, X, Y, and Z with dimensions (10,10,10), (10,5,2), (5,3,2), and (90,5,2), respectively.
Their volumes will be vW=1000, vX=100, vY=30 and vZ=900, making W the largest box and, since dW=vW−V=1000−980=20, that means W is big enough for all our items.

Input

The input specifies a set of boxes. It begins with a line containing two integers: n (1≤n≤100), specifying the number of boxes, and V, as defined above.
The remaining input is composed of n lines, each specifying one box.
Each line contains the dimensions l, w, and h for the box.
You may assume that 1⩽l,w,h,V<232.
You may also assume that, for any given box i, its volume vi will always be less than 232

Output

The output is a single integer: the value of di for the largest box by volume.

*/

package main

import (
	"math"
)

func main() {
	assert(largest(10, [][3]int{
		{1, 1, 2},
		{2, 2, 2},
		{3, 2, 1},
	}) == -2)

	assert(largest(30, [][3]int{
		{1, 1, 1},
		{5, 2, 3},
		{5, 2, 1},
	}) == 0)

	assert(largest(980, [][3]int{
		{10, 10, 10},
		{10, 5, 2},
		{5, 3, 2},
		{90, 5, 2},
	}) == 20)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func largest(v int, a [][3]int) int {
	m := math.MinInt
	for _, u := range a {
		x := u[0]*u[1]*u[2] - v
		if x > m {
			m = x
		}
	}
	return m
}

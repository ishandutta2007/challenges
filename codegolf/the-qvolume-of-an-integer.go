/*

It is ancient knowledge that every non-negative integer can be rewritten as the sum of four squared integers. For example the number 1 can be expressed as 02+02+02+12.
Or, in general, for any non-negative integer n, there exist integers a,b,c,d such that

n=a2+b2+c2+d2

Joseph-Louis Lagrange proved this in the 1700s and so it is often called Lagrange's Theorem.

This is sometimes discussed in relation to quaternions – a type of number discovered by William Hamilton in the 1800s, represented as
w+xi+yj+zk
where w,x,y,z are real numbers, and i,j and k are distinct imaginary units that don't multiply commutatively. Specifically, it is discussed in relation to squaring each component of the quaternion
w2+x2+y2+z2

This quantity is sometimes called the norm, or squared norm, or also quadrance. Some modern proofs of Lagrange's Theorem use quaternions.

Rudolf Lipschitz studied quaternions with only integer components, called Lipschitz quaternions. Using quadrance, we can imagine that every Lipschitz quaternion can be thought of having a friend in the integers. For example quaternion 0+0i+0j+1k
can be thought of as associated with the integer 1=02+02+02+12. Also, if we go backwards, then every integer can be thought of as having a friend in the Lipschitz quaternions.

But there is an interesting detail of Lagrange's theorem – the summation is not unique. Each integer may have several different sets of four squares that can be summed to create it.
For example, the number 1 can be expressed in 4 ways using non-negative integers (let us only consider non-negatives for this challenge):

1=02+02+02+12
1=02+02+12+02
1=02+12+02+02
1=12+02+02+02

The summands are always squares of 0, or 1, but they can be in different positions in the expression.

For this challenge, let us also "sort" our summands lowest to highest, to eliminate duplicates, so that we could consider, for this exercise, that 1 only has one way of being represented as the sum of four squares:

1=02+02+02+12

Another example is the number 42, which can be expressed in four ways (again, only considering non-negative a,b,c,d, and eliminating duplicate component arrangements)

42=02+12+42+52
42=12+12+22+62
42=12+32+42+42
42=22+22+32+52

What if we imagine each of these different ways of expressing an integer as being associated to a specific quaternion? Then we could say the number 42 is associated with these four quaternions:

0+1i+4j+5k
1+1i+2j+6k
1+3i+4j+4k
2+2i+3j+5k

If we imagine the standard computer graphics interpretation of a quaternion, where i, j and k are vectors in three dimensional Euclidean space, and so the x, y and z components of the quaternion are 3 dimensional Cartesian coordinates,
then we can imagine that each integer, through this thought process, can be associated with a set of 3 dimensional coordinates in space. For example, the number 42 is associated with the following four (x,y,z) coordinates:
(1,4,5),(1,2,6),(3,4,4),(2,3,5)

This can be thought of as a point cloud, or a set of points in space. Now, one interesting thing about a set of finite points in space is that you can always draw a minimal bounding box around them – a box that is big enough to fit all the points, but no bigger.
If you imagine the box as being an ordinary box aligned with the x,y,z

axes, it is called an axis-aligned bounding box. The bounding box also has a volume, calculable by determining its width, length, and height, and multiplying them together.

We can then imagine the volume of a bounding box for the points formed by our quaternions. For the integer 1, we have, using the criteria of this exercise, one quaternion whose quadrance is 1, 0+0i+0j+1k.
This is a very simple point cloud, it only has one point, so it's bounding box has volume 0.
For the integer 42, however, we have four quaternions, and so four points, around which we can draw a bounding box.
The minimum point of the box is (1,2,4) and the maximum is (3,4,6) resulting in a width, length, and height of 2, 2, and 2, giving a volume of 8.

Let's say that for an integer n, the qvolume is the volume of the axis-aligned bounding box of all the 3D points formed by quaternions that have a quadrance equal to n, where the components of the quaternion w+xi+yj+zk are non-negative and w<=x<=y<=z.

Create a program or function that, given a single non-negative integer n, will output n's qvolume.

Examples:

input -> output
0 -> 0
1 -> 0
31 -> 4
32 -> 0
42 -> 8
137 -> 96
1729 -> 10032

This is code-golf, smallest number of bytes wins.

*/

package main

import (
	"math"
	"sort"
)

func main() {
	assert(qvolume(0) == 0)
	assert(qvolume(1) == 0)
	assert(qvolume(31) == 4)
	assert(qvolume(32) == 0)
	assert(qvolume(42) == 8)
	assert(qvolume(137) == 96)
	assert(qvolume(1729) == 10032)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func qvolume(n int) int {
	a := [3]int{math.MaxInt, math.MaxInt, math.MaxInt}
	b := [3]int{math.MinInt, math.MinInt, math.MinInt}

	m := make(map[[4]int]bool)
	for z := 0; z <= n; z++ {
		for y := 0; y <= z; y++ {
			for x := 0; x <= y; x++ {
				t := n - (x*x + y*y + z*z)
				if t < 0 {
					continue
				}
				w := int(math.Sqrt(float64(t)))
				if x*x+y*y+z*z+w*w != n {
					continue
				}

				p := [4]int{x, y, z, w}
				sort.Ints(p[:])
				if m[p] {
					continue
				}
				m[p] = true

				for i := 0; i < 3; i++ {
					a[i] = min(a[i], p[i+1])
					b[i] = max(b[i], p[i+1])
				}
			}
		}
	}
	return volume(a, b)
}

func volume(a, b [3]int) int {
	x := b[0] - a[0]
	y := b[1] - a[1]
	z := b[2] - a[2]
	return x * y * z
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

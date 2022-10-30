/*

Given a list of four points in the plane, determine if they are the vertices of a parallelogram.

Examples

is_parallelogram([(0, 0), (1, 0), (1, 1), (0, 1)]) ➞ True

is_parallelogram([(0, 0), (2, 0), (1, 1), (0, 1)]) ➞ False

is_parallelogram([(0, 0), (1, 1), (1, 4), (0, 3)]) ➞ True

is_parallelogram([(0, 0), (1, 2), (2, 1), (3, 3)]) ➞ True

is_parallelogram([(0, 0), (1, 0), (0, 1), (1, 1)]) ➞ True

Notes

The points may be given in any order (compare examples #1 and #5).

*/

package main

import (
	"image"
)

func main() {
	v1 := [4]image.Point{{0, 0}, {1, 0}, {1, 1}, {0, 1}}
	v2 := [4]image.Point{{0, 0}, {2, 0}, {1, 1}, {0, 1}}
	v3 := [4]image.Point{{0, 0}, {1, 1}, {1, 4}, {0, 3}}
	v4 := [4]image.Point{{0, 0}, {1, 2}, {2, 1}, {3, 3}}
	v5 := [4]image.Point{{0, 0}, {1, 1}, {1, 4}, {6, 3}}
	v6 := [4]image.Point{{2, 0}, {-2, 0}, {0, 1}, {0, -1}}
	v7 := [4]image.Point{{2, 0}, {-2, 0}, {0, 2}, {0, -1}}
	v8 := [4]image.Point{{1, -1}, {-1, 1}, {2, 3}, {-3, -2}}
	v9 := [4]image.Point{{1, -1}, {-1, 1}, {2, 3}, {-2, -3}}
	v10 := [4]image.Point{{1, -1}, {2, 3}, {-1, 1}, {-3, -2}}
	v11 := [4]image.Point{{0, 0}, {1, 1}, {2, 0}, {0, 1}}
	v12 := [4]image.Point{{-1, -1}, {3, 3}, {1, 0}, {1, 2}}
	v13 := [4]image.Point{{-1, -1}, {1, 0}, {3, 4}, {1, 2}}
	v14 := [4]image.Point{{-1, -1}, {1, 0}, {3, 3}, {1, 2}}
	v15 := [4]image.Point{{-1, 0}, {1, 0}, {3, 3}, {1, 2}}

	assert(parallelogram(v1) == true)
	assert(parallelogram(v2) == false)
	assert(parallelogram(v3) == true)
	assert(parallelogram(v4) == true)
	assert(parallelogram(v5) == false)
	assert(parallelogram(v6) == true)
	assert(parallelogram(v7) == false)
	assert(parallelogram(v8) == false)
	assert(parallelogram(v9) == true)
	assert(parallelogram(v10) == false)
	assert(parallelogram(v11) == false)
	assert(parallelogram(v12) == true)
	assert(parallelogram(v13) == false)
	assert(parallelogram(v14) == true)
	assert(parallelogram(v15) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://www.geeksforgeeks.org/check-whether-four-points-make-parallelogram/
// the main properties of the parallelogram are that opposite sides of parallelogram are parallel and of equal length and diagonals of parallelogram bisect each other.
// use second property, find all midpoints of every pair and verify that there should be 2 midpoints that are the same and rest are different
func parallelogram(p [4]image.Point) bool {
	m := make(map[image.Point]int)
	for i := 0; i < 4; i++ {
		for j := i + 1; j < 4; j++ {
			q := p[i].Add(p[j])
			m[q]++
		}
	}

	x, y := 0, 0
	for _, v := range m {
		switch v {
		case 1:
			x++
		case 2:
			y++
		default:
			return false
		}
	}
	return x == 4 && y == 1
}

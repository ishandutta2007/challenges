/*

Images can be described as 3D arrays.

// This image has only one white pixel:

[
  [[255, 255, 255]]
]

// This one is a 2 by 2 black image:

[
  [[0, 0, 0], [0, 0, 0]],
  [[0, 0, 0], [0, 0, 0]]
]

Your task is to create a function that takes a 3D array representation of an image and returns the grayscale version of that.
Examples

grayscale([
  [[0, 0, 0], [0, 0, 157]],
  [[1, 100, 0], [0, 10, 0]]
]) ➞ [
  [[0, 0, 0], [52, 52, 52]],
  [[34, 34, 34], [3, 3, 3]]
]

Notes

    A valid RGB value ranges from 0 to 255 (inclusive).
    If the given array contains out of bound values, convert them to the nearest valid one.
    Previous challenge in this series: Image Manipulation: Invert (Part 1)
    Grayscaling an image is adjusting to have the same amount of (Red, Green, Blue) from their combined average to produce different shades of gray.

*/

package main

import (
	"reflect"
)

func main() {
	m1 := [][][3]int{
		{{0, 0, 0}, {0, 0, 157}},
		{{1, 100, 0}, {0, 10, 0}},
	}
	r1 := [][][3]int{
		{{0, 0, 0}, {52, 52, 52}},
		{{34, 34, 34}, {3, 3, 3}},
	}

	m2 := [][][3]int{
		{{0, 0, 0}, {0, 0, 157}, {100, 229, 4}},
		{{1, 100, 0}, {0, 10, 0}, {0, 168, 0}},
		{{0, 125, 0}, {15, 0, 9}, {0, 139, 0}},
		{{0, 125, 0}, {0, 0, 9}, {0, 200, 0}},
	}
	r2 := [][][3]int{
		{{0, 0, 0}, {52, 52, 52}, {111, 111, 111}},
		{{34, 34, 34}, {3, 3, 3}, {56, 56, 56}},
		{{42, 42, 42}, {8, 8, 8}, {46, 46, 46}},
		{{42, 42, 42}, {3, 3, 3}, {67, 67, 67}},
	}

	m3 := [][][3]int{
		{{0, 0, 255}, {0, 0, 0}, {0, 0, 157}, {100, 229, 4}},
		{{100, 0, 3}, {1, 100, 0}, {0, 10, 0}, {0, 168, 0}},
		{{16, 30, 0}, {0, 125, 0}, {15, 0, 9}, {0, 139, 0}},
		{{200, 2, 0}, {0, 125, 0}, {0, 0, 9}, {0, 200, 0}},
	}
	r3 := [][][3]int{
		{{85, 85, 85}, {0, 0, 0}, {52, 52, 52}, {111, 111, 111}},
		{{34, 34, 34}, {34, 34, 34}, {3, 3, 3}, {56, 56, 56}},
		{{15, 15, 15}, {42, 42, 42}, {8, 8, 8}, {46, 46, 46}},
		{{67, 67, 67}, {42, 42, 42}, {3, 3, 3}, {67, 67, 67}},
	}

	m4 := [][][3]int{
		{{0, -1, -120}, {300, 0, 157}},
		{{1, 100, 0}, {256, 10, 0}},
	}
	r4 := [][][3]int{
		{{0, 0, 0}, {137, 137, 137}},
		{{34, 34, 34}, {88, 88, 88}},
	}

	test(m1, r1)
	test(m2, r2)
	test(m3, r3)
	test(m4, r4)
}

func test(m, r [][][3]int) {
	p := grayscale(m)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func grayscale(m [][][3]int) [][][3]int {
	p := make([][][3]int, len(m))
	for i := range m {
		p[i] = make([][3]int, len(m[i]))
	}
	for i := range p {
		for j := range p[i] {
			g := 0
			for k := range m[i][j] {
				g += clamp(m[i][j][k], 0, 255)
			}
			g = int(float64(g)/3 + 0.5)
			g = clamp(g, 0, 255)

			for k := range p[i][j] {
				p[i][j][k] = g
			}
		}
	}
	return p
}

func clamp(x, a, b int) int {
	if x < a {
		x = a
	} else if x > b {
		x = b
	}
	return x
}

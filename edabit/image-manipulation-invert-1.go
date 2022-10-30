/*

Images can be described as a 3D array.

// This image has only one white pixel:

[
  [[255, 255, 255]]
]

// This one is a 2 by 2 black image:

[
  [[0, 0, 0], [0, 0, 0]],
  [[0, 0, 0], [0, 0, 0]]
]

Your task is to create a function that takes a 3D array representation of an image and returns the inverse of that.

For example, white becomes black, black becomes white, etc.
Examples

invert([
  [[255, 255, 255], [255, 255, 255]],
  [[255, 255, 255], [255, 255, 255]]
]) ➞ [
  [[0, 0, 0], [0, 0, 0]],
  [[0, 0, 0], [0, 0, 0]]
]

Notes

	A valid RGB value ranges from 0 to 255 (inclusive).
	If the given array contains out of bound values, convert them to the nearest valid one.
	Next challenge in this series: Image Manipulation: 255 Shades of Grey (Part 2)

*/

package main

import (
	"reflect"
)

func main() {
	m1 := [][][3]int{
		{{255, 255, 255}, {255, 255, 255}},
		{{255, 255, 255}, {255, 255, 255}},
	}
	r1 := [][][3]int{
		{{0, 0, 0}, {0, 0, 0}},
		{{0, 0, 0}, {0, 0, 0}},
	}

	m2 := [][][3]int{
		{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
		{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
		{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
	}
	r2 := [][][3]int{
		{{255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
		{{255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
		{{255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
	}

	m3 := [][][3]int{
		{{0, 0, 255}, {0, 0, 0}, {0, 0, 157}, {100, 229, 4}},
		{{100, 0, 3}, {1, 100, 0}, {0, 10, 0}, {0, 168, 0}},
		{{16, 30, 0}, {0, 125, 0}, {15, 0, 9}, {0, 139, 0}},
		{{200, 2, 0}, {0, 125, 0}, {0, 0, 9}, {0, 200, 0}},
	}
	r3 := [][][3]int{
		{{255, 255, 0}, {255, 255, 255}, {255, 255, 98}, {155, 26, 251}},
		{{155, 255, 252}, {254, 155, 255}, {255, 245, 255}, {255, 87, 255}},
		{{239, 225, 255}, {255, 130, 255}, {240, 255, 246}, {255, 116, 255}},
		{{55, 253, 255}, {255, 130, 255}, {255, 255, 246}, {255, 55, 255}},
	}

	m4 := [][][3]int{
		{{0, 255, 255}, {256, 255, 255}},
		{{255, -1, 255}, {255, 255, 255}},
	}
	r4 := [][][3]int{
		{{255, 0, 0}, {0, 0, 0}},
		{{0, 255, 0}, {0, 0, 0}},
	}

	test(m1, r1)
	test(m2, r2)
	test(m3, r3)
	test(m4, r4)
}

func test(m, r [][][3]int) {
	p := invert(m)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func invert(m [][][3]int) [][][3]int {
	p := make([][][3]int, len(m))
	for i := range m {
		p[i] = make([][3]int, len(m[i]))
	}
	for i := range p {
		for j := range p[i] {
			for k := range p[i][j] {
				p[i][j][k] = ^clamp(m[i][j][k], 0, 255) & 0xff
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

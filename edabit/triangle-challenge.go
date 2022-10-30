/*

Given the perimeter and the area of a triangle, devise a function that returns the length of the sides of all triangles that fit those specifications.
The length of the sides must be integers. Sort results in ascending order.

triangle(perimeter, area) ➞ [[s1, s2, s3]]

Examples

triangle(12, 6) ➞ [[3, 4, 5]]

triangle(45, 97.42786) ➞ [[15, 15, 15]]

triangle(70, 210) ➞ [[17, 25, 28], [20, 21, 29]]

triangle(3, 0.43301) ➞ [[1, 1, 1]]

Notes

N/A

*/

package main

import (
	"fmt"
	"math"
	"reflect"
)

func main() {
	test(3, 0.43301, [][3]int{{1, 1, 1}})
	test(201, 49.99937, [][3]int{{1, 100, 100}})
	test(98, 420, [][3]int{{24, 37, 37}, {25, 34, 39}, {29, 29, 40}})
	test(70, 210, [][3]int{{17, 25, 28}, {20, 21, 29}})
	test(30, 30, [][3]int{{5, 12, 13}})
	test(1792, 55440, [][3]int{{170, 761, 861}, {291, 626, 875}})
	test(150, 420, [][3]int{{26, 51, 73}})
	test(864, 23760, [][3]int{{132, 366, 366}, {135, 352, 377}})
}

func test(P int, A float64, r [][3]int) {
	p := triangle(P, A)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func triangle(P int, A float64) (r [][3]int) {
	m := make(map[[2]int]bool)
	for a := 1; a < P; a++ {
		for b := a; b < P; b++ {
			c := P - a - b
			if c <= 0 {
				break
			}

			x := 4 * A
			y := float64((a + b + c) * (a + b - c) * (a - b + c) * (-a + b + c))
			if math.Abs(x*x-y) > 1e-2 {
				continue
			}

			s := min(min(a, b), c)
			t := mid(a, b, c)
			u := max(max(a, b), c)
			if i := [2]int{s, u}; !m[i] {
				r, m[i] = append(r, [3]int{s, t, u}), true
			}
		}
	}
	return
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func mid(a, b, c int) int {
	x := a - b
	y := b - c
	z := a - c
	if x*y > 0 {
		return b
	}
	if x*z > 0 {
		return c
	}
	return a
}

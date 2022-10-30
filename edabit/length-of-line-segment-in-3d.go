/*

Write a function that takes coordinates of two points on a three-dimensional plane and returns the length of the line segment connecting those two points.

Examples

lineLength(arr[0]={15, 7, 5}, arr[1]={22, 11, 1}) ➞ 8.06

lineLength(arr[0]={0, 0, 0}, arr[1]={0, 0, 0}) ➞ 0

lineLength(arr[0]={0, 0, 0}, arr[1]={1, 1, 1}) ➞ 1.41

Notes

    Numbers in argument array can be positive or negative.
    The order of the given numbers is X, Y, Z.
    There is 0.1 tolerance, so you don't need to round your result.
    This challenge is easier than it looks.

Check my profile for other challenges in the series.

*/

package main

import (
	"math"
)

func main() {
	test(vec3{15, 7, 5}, vec3{22, 11, 1}, 9)
	test(vec3{1, 1, 1}, vec3{0, 0, 0}, 1.73)
	test(vec3{-33, 33, -33}, vec3{33, -33, 33}, 114.31)
	test(vec3{1, 2, 3}, vec3{4, 5, 6}, 5.19)
	test(vec3{719, 10, 334}, vec3{-65, 1, 175}, 800.01)
	test(vec3{-11, -12, 1}, vec3{-13, -14, -15}, 16.24)
	test(vec3{}, vec3{}, 0)
}

func test(a, b vec3, r float64) {
	assert(math.Abs(length(a, b)-r) < 1e-1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type vec3 struct {
	x, y, z float64
}

func length(a, b vec3) float64 {
	dx := a.x - b.x
	dy := a.y - b.y
	dz := a.z - b.z
	return math.Sqrt(dx*dx + dy*dy + dz*dz)
}

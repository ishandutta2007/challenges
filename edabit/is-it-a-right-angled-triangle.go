/*

Find out if a right-angled triangle can be made given some facts about the shape.

    Given varying information about a shape, create a function that returns True if the shape could be a right-angle triangle and False if not.
    You will be given a list of numbers and a string stating whether the numbers are angles or sides.
    The information may indicate more than one possible shape, but we just need to know if these details could be found in a right-angled triangle.

Examples

is_right_angle([30, 60], "angle") ➞ True
# A third angle could be 90

is_right_angle([20, 20, 20, 20], "angle") ➞ False
# More than 3 sides

is_right_angle([4, 5, 3], "side") ➞ True
# 3**2 + 4**2 = 5**2

is_right_angle([4, 5], "side") ➞ True
# Third side may be 3

Notes

Check the Resources for more info on right-angle triangles.

*/

package main

import (
	"sort"
)

func main() {
	assert(rightangle([]int{30, 60}, "angle") == true)
	assert(rightangle([]int{30, 60, 90}, "angle") == true)
	assert(rightangle([]int{90}, "angle") == true)
	assert(rightangle([]int{90, 90, 90}, "angle"))
	assert(rightangle([]int{20, 20, 20, 20}, "angle") == false)
	assert(rightangle([]int{}, "angle") == true)
	assert(rightangle([]int{90, 90}, "angle") == false)
	assert(rightangle([]int{45, 46}, "angle") == false)
	assert(rightangle([]int{45, 46}, "side") == true)
	assert(rightangle([]int{4, 5, 6}, "side") == false)
	assert(rightangle([]int{}, "side") == true)
	assert(rightangle([]int{3, 4, 5}, "side") == true)
	assert(rightangle([]int{60, 60, 60}, "angle") == false)
	assert(rightangle([]int{177, 2, 1}, "angle") == false)
	assert(rightangle([]int{20, 20, 20, 20}, "side") == false)
	assert(rightangle([]int{43}, "angle") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rightangle(s []int, t string) bool {
	if len(s) < 2 {
		return positive(s)
	}
	if len(s) > 3 {
		return false
	}

	var p [3]int
	copy(p[:], s)

match:
	switch t {
	case "side":
		if len(s) == 2 {
			return true
		}

		sort.Ints(p[:])
		if p[0]*p[0]+p[1]*p[1] != p[2]*p[2] {
			return false
		}

	case "angle":
		if len(s) == 2 {
			p[2] = 180 - (p[0] + p[1])
		}
		for i := range p {
			if p[i] == 90 {
				break match
			}
		}
		return false

	default:
		return false
	}

	return positive(p[:])
}

func positive(a []int) bool {
	for i := range a {
		if a[i] <= 0 {
			return false
		}
	}
	return true
}

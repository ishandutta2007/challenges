/*

Write a function that squishes an array from the left or the right.

Examples

squish([1, 2, 3, 4, 5], "left")
➞ [[1, 2, 3, 4, 5], [3, 3, 4, 5], [6, 4, 5], [10, 5], [15]]

squish([1, 2, 3, 4, 5], "right")
➞ [[1, 2, 3, 4, 5], [1, 2, 3, 9], [1, 2, 12], [1, 14], [15]]

squish([1, 0, 2, -3], "left")
➞ [[1, 0, 2, -3], [1, 2, -3], [3, -3], [0]]

squish([1, 0, 2, -3], "right")
➞ [[1, 0, 2, -3], [1, 0, -1], [1, -1], [0]]

Notes

    Squishing from the left is to successively sum the first two elements of an array (shortening the array in the process).
    Squishing from the right is to successively sum the last two elements of an array.
    Include the original array as the first element in either squish.
    Return an empty array if the input is an empty array.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 2, 3, 4, 5}, "left", [][]int{{1, 2, 3, 4, 5}, {3, 3, 4, 5}, {6, 4, 5}, {10, 5}, {15}})
	test([]int{1, 0, 2, -3}, "left", [][]int{{1, 0, 2, -3}, {1, 2, -3}, {3, -3}, {0}})
	test([]int{4, 9, -3, 2, 5}, "left", [][]int{{4, 9, -3, 2, 5}, {13, -3, 2, 5}, {10, 2, 5}, {12, 5}, {17}})
	test([]int{8, -7, 6, 1, 0, 2}, "left", [][]int{{8, -7, 6, 1, 0, 2}, {1, 6, 1, 0, 2}, {7, 1, 0, 2}, {8, 0, 2}, {8, 2}, {10}})
	test([]int{8, 7}, "left", [][]int{{8, 7}, {15}})
	test([]int{8}, "left", [][]int{{8}})
	test([]int{}, "left", [][]int{})

	test([]int{1, 2, 3, 4, 5}, "right", [][]int{{1, 2, 3, 4, 5}, {1, 2, 3, 9}, {1, 2, 12}, {1, 14}, {15}})
	test([]int{1, 0, 2, -3}, "right", [][]int{{1, 0, 2, -3}, {1, 0, -1}, {1, -1}, {0}})
	test([]int{4, 9, -3, 2, 5}, "right", [][]int{{4, 9, -3, 2, 5}, {4, 9, -3, 7}, {4, 9, 4}, {4, 13}, {17}})
	test([]int{8, -7, 6, 1, 0, 2}, "right", [][]int{{8, -7, 6, 1, 0, 2}, {8, -7, 6, 1, 2}, {8, -7, 6, 3}, {8, -7, 9}, {8, 2}, {10}})
	test([]int{8, 7}, "right", [][]int{{8, 7}, {15}})
	test([]int{8}, "right", [][]int{{8}})
	test([]int{}, "right", [][]int{})
}

func test(a []int, d string, r [][]int) {
	p := squish(a, d)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func squish(a []int, d string) [][]int {
	r := [][]int{}
	p := append([]int{}, a...)
	for {
		n := len(p)
		if n > 0 {
			r = append(r, p)
		}
		if n < 2 {
			break
		}

		q := make([]int, n-1)
		switch d {
		case "left":
			copy(q[1:], p[2:])
			q[0] = p[0] + p[1]
		case "right":
			copy(q[:n-2], p[:])
			q[n-2] = p[n-1] + p[n-2]
		default:
			return nil
		}

		p = q
	}
	return r
}

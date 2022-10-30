/*

Write a function that returns the largest even integer in an array with its corresponding index and the parity of that index,
but determining the parity of that index is limited to not using the modulo operator %.

Output Structure

{"@odd|even index " + index_of_largest: largest_integer}

Examples

bitwiseIndex([107, 19, 36, -18, -78, 24, 97]) ➞ {"@even index 2": 36}

bitwiseIndex([31, 7, 2, 13, 7, 9, 10, 13]) ➞ {"@even index 6": 10}

bitwiseIndex([4, 4, 4, 4, 4, 4]) ➞ {"@even index 0": 4}

bitwiseIndex([-31, -7, -13, -7, -9, -13]) ➞ "No even integer found!"

Notes

    The use of indexOf() and max() are restricted.
    If there are no even integers, return "No even integer found!".
    The set of limitations imposed on this challenge dictates the level of difficulty.
    Another version of this challenge that deals with recursion can be found here.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	itab := [][]int{
		{107, 19, 36, -18, -78, 24, 97},
		{31, 7, 2, 13, 7, 9, 10, 13},
		{4, 4, 4, 4, 4, 4},
		{-31, -7, -13, -7, -9, -13},
		{1, 128, 9, 56, -1, 7, 18, 49},
		{63, 12, 77, 112, 75, 92},
		{6, 6, 6, 6, 6, 6},
		{1, 129, 91, 5, -1, 7, 11, 9},
		{-84, -42, 0, -2, -94, -8},
	}
	otab := []interface{}{
		map[string]int{"@even index 2": 36},
		map[string]int{"@even index 6": 10},
		map[string]int{"@even index 0": 4},
		"No even integer found!",
		map[string]int{"@odd index 1": 128},
		map[string]int{"@odd index 3": 112},
		map[string]int{"@even index 0": 6},
		"No even integer found!",
		map[string]int{"@even index 2": 0},
	}
	for i := range itab {
		assert(reflect.DeepEqual(bitwise(itab[i]), otab[i]))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bitwise(a []int) interface{} {
	v, n := 0, -1
	for i := range a {
		if a[i]&1 == 0 && (n < 0 || v < a[i]) {
			v, n = a[i], i
		}
	}

	if n < 0 {
		return "No even integer found!"
	}

	k := fmt.Sprintf("@even index %d", n)
	if n&1 != 0 {
		k = fmt.Sprintf("@odd index %d", n)
	}
	return map[string]int{k: v}
}

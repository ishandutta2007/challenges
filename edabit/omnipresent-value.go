/*

A value is omnipresent if it exists in every subarray inside the main array.

To illustrate:

[[3, 4], [8, 3, 2], [3], [9, 3], [5, 3], [4, 3]]
// 3 exists in every element inside this array, so is omnipresent.

Create a function that determines whether an input value is omnipresent for a given array.
Examples

isOmnipresent([[1, 1], [1, 3], [5, 1], [6, 1]], 1) ➞ true

isOmnipresent([[1, 1], [1, 3], [5, 1], [6, 1]], 6) ➞ false

isOmnipresent([[5], [5], [5], [6, 5]], 5) ➞ true

isOmnipresent([[5], [5], [5], [6, 5]], 6) ➞ false

Notes

Sub-arrays can be any length.

*/

package main

func main() {
	assert(isomni([][]int{
		{1, 1},
		{1, 3},
		{5, 1},
		{6, 1},
	}, 1) == true)

	assert(isomni([][]int{
		{1, 1},
		{1, 3},
		{5, 1},
		{6, 1},
	}, 6) == false)

	assert(isomni([][]int{
		{5},
		{5},
		{5},
		{6, 5},
	}, 5) == true)

	assert(isomni([][]int{
		{5},
		{6, 6, 6},
		{1, 6, 2},
		{6, 5},
	}, 6) == false)

	assert(isomni([][]int{
		{5, 1},
		{6, 6, 6, 1},
		{1, 6, 2},
		{6, 1, 5},
	}, 1) == true)
}

func isomni(a [][]int, v int) bool {
loop:
	for i := range a {
		for j := range a[i] {
			if a[i][j] == v {
				continue loop
			}
		}
		return false
	}
	return true
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

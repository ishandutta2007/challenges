/*

Write a function that takes two arrays and adds the first element in the first array with the first element in the second array, the second element in the first array with the second element in the second array, etc, etc.
Return true if all element combinations add up to the same number. Otherwise, return false.

Examples

puzzlePieces([1, 2, 3, 4], [4, 3, 2, 1]) ➞ true
// 1 + 4 = 5;  2 + 3 = 5;  3 + 2 = 5;  4 + 1 = 5
// Both arrays sum to [5, 5, 5, 5]

puzzlePieces([1, 8, 5, 0, -1, 7], [0, -7, -4, 1, 2, -6]) ➞ true

puzzlePieces([1, 2], [-1, -1]) ➞ false

puzzlePieces([9, 8, 7], [7, 8, 9, 10]) ➞ false

Notes

    Each array will have at least one element.
    Return false if both arrays are of different length.

*/

package main

func main() {
	assert(puzzle([]int{1, 2, 3, 4}, []int{4, 3, 2, 1}) == true)
	assert(puzzle([]int{1, 8, 5, 0, -1, 7}, []int{0, -7, -4, 1, 2, -6}) == true)
	assert(puzzle([]int{2, 1, 1}, []int{-2, -1, -1}) == true)
	assert(puzzle([]int{2}, []int{-2}) == true)
	assert(puzzle([]int{5, -1}, []int{-6, 0}) == true)
	assert(puzzle([]int{0, 0, 0, 0, 0}, []int{1, 1, 1, 1, 1}) == true)
	assert(puzzle([]int{1, 2}, []int{-1, -1}) == false)
	assert(puzzle([]int{9, 8, 7}, []int{7, 8, 9, 10}) == false)
	assert(puzzle([]int{9, 8, 7}, []int{7, 8, 9, 16}) == false)
	assert(puzzle([]int{1, 1, 1}, []int{1, 1, 2}) == false)
	assert(puzzle([]int{1, 8, 1}, []int{1, -8, -1}) == false)
	assert(puzzle([]int{0, 0, 0, 0, 0}, []int{1, 1, 0, 1, 1}) == false)
	assert(puzzle([]int{0, 0, 0, 0, 0}, []int{1, 1, 1, 1}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func puzzle(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}

	var x int
	for i := range a {
		y := a[i] + b[i]
		if i == 0 {
			x = y
		} else if x != y {
			return false
		}
	}
	return true
}

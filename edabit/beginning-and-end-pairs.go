/*

Write a function that pairs the first number in an array with the last, the second number with the second to last, etc.
Examples

pairs([1, 2, 3, 4, 5, 6, 7]) ➞ [[1, 7], [2, 6], [3, 5], [4, 4]]

pairs([1, 2, 3, 4, 5, 6]) ➞ [[1, 6], [2, 5], [3, 4]]

pairs([5, 9, 8, 1, 2]) ➞ [[5, 2], [9, 1], [8, 8]]

pairs([]) ➞ []

Notes

    If the array has an odd length, repeat the middle element twice for the last pair.
    Return an empty array if the input is an empty array.

*/

package main

func main() {
	eq(pairs([]int{1, 2, 3, 4, 5, 6, 7}), [][2]int{{1, 7}, {2, 6}, {3, 5}, {4, 4}})
	eq(pairs([]int{1, 2, 3, 4, 5, 6}), [][2]int{{1, 6}, {2, 5}, {3, 4}})
	eq(pairs([]int{5, 9, 8, 1, 2}), [][2]int{{5, 2}, {9, 1}, {8, 8}})
	eq(pairs([]int{5, 6, 7}), [][2]int{{5, 7}, {6, 6}})
	eq(pairs([]int{1, 1, 4, 4, 5, 5}), [][2]int{{1, 5}, {1, 5}, {4, 4}})
	eq(pairs([]int{9, 9, 9, 9, 3, 3, 9}), [][2]int{{9, 9}, {9, 3}, {9, 3}, {9, 9}})
	eq(pairs([]int{5, 6}), [][2]int{{5, 6}})
	eq(pairs([]int{5}), [][2]int{{5, 5}})
	eq(pairs([]int{}), [][2]int{})
}

func pairs(a []int) [][2]int {
	var p [][2]int
	l := len(a)
	for i := 0; i < l/2; i++ {
		p = append(p, [2]int{a[i], a[l-1-i]})
	}
	if l&1 != 0 {
		p = append(p, [2]int{a[l/2], a[l/2]})
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(a, b [][2]int) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

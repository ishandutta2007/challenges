/*

Create a function that returns true if the first array is a subset of the second. Both arrays will contain only unique values.
Examples

isSubset([3, 2, 5], [5, 3, 7, 9, 2]) ➞ true

isSubset([8, 9], [7, 1, 9, 8, 4, 5, 6]) ➞ true

isSubset([1, 2], [3, 5, 9, 1]) ➞ false

Notes

N/A

*/

package main

func main() {
	assert(subset([]int{3, 2, 5}, []int{5, 3, 7, 9, 2}) == true)
	assert(subset([]int{8, 9}, []int{7, 1, 9, 8, 4, 5, 6}) == true)
	assert(subset([]int{1, 2}, []int{1, 2, 3}) == true)
	assert(subset([]int{1, 2}, []int{3, 5, 9, 1}) == false)
	assert(subset([]int{1, 2, 3, 4}, []int{4, 3, 2, 1}) == true)
	assert(subset([]int{7, 9, 8, 4, 2}, []int{7, 9, 5, 8, 4}) == false)
}

func subset(a, b []int) bool {
	m := make(map[int]bool)
	for i := range b {
		m[b[i]] = true
	}
	for i := range a {
		if _, f := m[a[i]]; !f {
			return false
		}
	}
	return true
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

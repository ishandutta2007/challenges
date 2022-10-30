/*

Given three arrays of integers: arr1, arr2, arr3, return the sum of integers which are common in all three arrays.
Examples

sumCommon([1, 2, 3], [5, 3, 2], [7, 3, 2]) ➞ 5
// 2 & 3 are common in all 3 arrays.

sumCommon([1, 2, 2, 3], [5, 3, 2, 2], [7, 3, 2, 2]) ➞ 7
// 2, 2 & 3 are common in all 3 arrays.

sumCommon([1], [1], [2]) ➞ 0

Notes

N/A

*/

package main

func main() {
	assert(threes([]int{1, 2, 3}, []int{5, 3, 2}, []int{7, 3, 2}) == 5)
	assert(threes([]int{1, 2, 2, 3}, []int{5, 3, 2, 2}, []int{7, 3, 2, 2}) == 7)
	assert(threes([]int{1}, []int{1}, []int{1}) == 1)
	assert(threes([]int{1}, []int{1}, []int{2}) == 0)
	assert(threes([]int{1, 2, 2, 3, 2}, []int{5, 3, 2, 2, 1}, []int{7, 3, 2, 2, 1}) == 8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func threes(a, b, c []int) int {
	m := make(map[int][3]int)
	count(m, a, 0)
	count(m, b, 1)
	count(m, c, 2)

	r := 0
	for k, p := range m {
		r += k * min(p[0], min(p[1], p[2]))
	}
	return r
}

func count(m map[int][3]int, a []int, b int) {
	for _, v := range a {
		p := m[v]
		p[b]++
		m[v] = p
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

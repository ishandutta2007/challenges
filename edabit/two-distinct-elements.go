/*

In each input array, every number repeats at least once, except for two. Write a function that returns the two unique numbers.
Examples

returnUnique([1, 9, 8, 8, 7, 6, 1, 6]) ➞ [9, 7]

returnUnique([5, 5, 2, 4, 4, 4, 9, 9, 9, 1]) ➞ [2, 1]

returnUnique([9, 5, 6, 8, 7, 7, 1, 1, 1, 1, 1, 9, 8]) ➞ [5, 6]

Notes

Keep the same ordering in the output.

*/

package main

func main() {
	assert(uniq2([]int{1, 9, 8, 8, 7, 6, 1, 6}) == [2]int{9, 7})
	assert(uniq2([]int{5, 5, 2, 4, 4, 4, 9, 9, 9, 1}) == [2]int{2, 1})
	assert(uniq2([]int{9, 5, 6, 8, 7, 7, 1, 1, 1, 1, 1, 9, 8}) == [2]int{5, 6})
	assert(uniq2([]int{4, 3, 9, 9, 1, 1, 6, 1, 6, 2, 4}) == [2]int{3, 2})
	assert(uniq2([]int{44, 44, 44, 2, 55, 55, 55, 0, 66, 66, 66}) == [2]int{2, 0})
	assert(uniq2([]int{-9, -9, -9, 7, -9, -9, 1}) == [2]int{7, 1})
	assert(uniq2([]int{2, 2, -19, 2, 7, 7, 4, 9, 9, 0, 0, 3, 3, 3}) == [2]int{-19, 4})
}

func uniq2(a []int) [2]int {
	m := make(map[int][2]int)
	for i, v := range a {
		m[v] = [2]int{i, m[v][1] + 1}
	}

	var (
		r [2]int
		i [2]int
		n int
	)
	for k, v := range m {
		if v[1] == 1 {
			r[n], i[n] = k, v[0]
			if n++; n == 2 {
				break
			}
		}
	}
	if i[0] > i[1] {
		r[0], r[1] = r[1], r[0]
	}

	return r
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

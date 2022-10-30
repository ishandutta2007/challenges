/*

The distance between two array values is the number of indices between them. Given a, find the minimum distance between any pair of equal elements in the array. If no such value exists, return -1.

*/

package main

func main() {
	assert(mindist([]int{3, 2, 1, 2, 3}) == 2)
	assert(mindist([]int{7, 1, 3, 4, 1, 7}) == 3)
	assert(mindist([]int{1, 2, 3, 4}) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mindist(a []int) int {
	m := make(map[int]int)
	r := -1
	for i, v := range a {
		j, f := m[v]
		if f {
			d := i - j
			if r < 0 || r > d {
				r = d
			}
		}
		m[v] = i
	}
	return r
}

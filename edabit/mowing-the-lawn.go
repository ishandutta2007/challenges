/*

Create a function that takes in an array of grass heights and a variable sequence of lawn mower cuts and outputs the array of successive grass heights.

If after a cut, any single element in the array reaches zero or negative, return "Done" instead of the array of new heights.

A demo:

cuttingGrass([3, 4, 4, 4], 1, 1, 1) ➞ [[2, 3, 3, 3], [1, 2, 2, 2], "Done"]

// 1st cut shaves off 1: [3, 4, 4, 4] ➞ [2, 3, 3, 3]
// 2nd cut shaves off 1: [2, 3, 3, 3] ➞ [1, 2, 2, 2]
// 3rd cut shaves off 1: [1, 2, 2, 2] ➞ [0, 1, 1, 1], but one element reached zero so we return "Done".

Examples

cuttingGrass([5, 6, 7, 5], 1, 2, 1)
➞ [[4, 5, 6, 4], [2, 3, 4, 2], [1, 2, 3, 1]]

cuttingGrass([4, 4, 4, 4], 1, 1, 1, 1)
➞ [[3, 3, 3, 3], [2, 2, 2, 2], [1, 1, 1, 1], "Done"]

cuttingGrass([8, 9, 9, 8, 8], 2, 3, 2, 1)
➞ [[6, 7, 7, 6, 6], [3, 4, 4, 3, 3], [1, 2, 2, 1, 1], "Done"]

cuttingGrass([1, 0, 1, 1], 1, 1, 1) ➞ ["Done", "Done", "Done"]

Notes

    The number of lawn cuts is variable.
    There will be at least one cut.
    Return "Done" onwards for each additional cut if the grass has already been completely mowed (see fourth example).

*/

package main

func main() {
	p1 := []interface{}{[]int{2, 3, 3, 3}, []int{1, 2, 2, 2}, "Done"}
	p2 := []interface{}{[]int{3, 3, 3, 3}, []int{2, 2, 2, 2}, []int{1, 1, 1, 1}, "Done"}
	p3 := []interface{}{[]int{4, 5, 6, 4}, []int{2, 3, 4, 2}, []int{1, 2, 3, 1}}
	p4 := []interface{}{[]int{6, 7, 7, 6, 6}, []int{3, 4, 4, 3, 3}, []int{1, 2, 2, 1, 1}, "Done"}
	p5 := []interface{}{"Done", "Done", "Done"}
	p6 := []interface{}{[]int{2, 3, 2, 3}, []int{1, 2, 1, 2}, "Done"}
	p7 := []interface{}{"Done", "Done", "Done"}

	asserti(cutgrass([]int{3, 4, 4, 4}, 1, 1, 1), p1)
	asserti(cutgrass([]int{4, 4, 4, 4}, 1, 1, 1, 1), p2)
	asserti(cutgrass([]int{5, 6, 7, 5}, 1, 2, 1), p3)
	asserti(cutgrass([]int{8, 9, 9, 8, 8}, 2, 3, 2, 1), p4)
	asserti(cutgrass([]int{1, 0, 1, 1}, 1, 1, 1), p5)
	asserti(cutgrass([]int{4, 5, 4, 5}, 2, 1, 1), p6)
	asserti(cutgrass([]int{4, 2, 2}, 2, 1, 1), p7)
}

func cutgrass(h []int, c ...int) []interface{} {
	p := make([]interface{}, len(c))
	r := h
	i := 0
loop:
	for ; i < len(c); i++ {
		q := make([]int, len(h))
		for j := range h {
			q[j] = r[j] - c[i]
			if q[j] <= 0 {
				break loop
			}
		}
		p[i], r = q, q
	}

	for ; i < len(c); i++ {
		p[i] = "Done"
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func asserti(a, b []interface{}) {
	assert(len(a) == len(b))
	for i := range a {
		x, u := a[i].([]int)
		y, v := b[i].([]int)
		assert(u == v)
		assert((u && eqi(x, y)) || a[i] == b[i])
	}
}

func eqi(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

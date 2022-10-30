/*

Create a function that takes in a nested array and an element and returns the frequency of that element by nested level.
Examples

freqCount([1, 4, 4, [1, 1, [1, 2, 1, 1]]], 1)
➞ [[0, 1], [1, 2], [2, 3]]
# The array has one 1 at level 0, 2 1's at level 1, and 3 1's at level 2.

freqCount([1, 5, 5, [5, [1, 2, 1, 1], 5, 5], 5, [5]], 5)
➞ [[0, 3], [1, 4], [2, 0]]

freqCount([1, [2], 1, [[2]], 1, [[[2]]], 1, [[[[2]]]]], 2)
➞ [[0, 0], [1, 1], [2, 1], [3, 1], [4, 1]]

Notes

    Start the default nesting (an array with no nesting) at 0.
    Output the nested levels in order (e.g. 0 first, then 1, then 2, etc.).
    Output 0 for the frequency if that particular level has no instances of that element (see example #2).

*/

package main

import (
	"sort"
)

type any interface{}

func main() {
	a1 := []any{1, 1, 1, 1}
	a2 := []any{1, 1, 2, 2}
	a3 := []any{1, 1, 2, []any{1}}
	a4 := []any{1, 1, 2, []any{[]any{1}}}
	a5 := []any{[]any{[]any{1}}}
	a6 := []any{1, 4, 4, []any{1, 1, []any{1, 2, 1, 1}}}
	a7 := []any{1, 5, 5, []any{5, []any{1, 2, 1, 1}, 5, 5}, 5, []any{5}}
	a8 := []any{1, []any{2}, 1, []any{[]any{[]any{2}}}, 1, []any{[]any{2}}, 1, []any{[]any{[]any{[]any{2}}}}}

	r1 := [][2]int{{0, 4}}
	r2 := [][2]int{{0, 2}}
	r3 := [][2]int{{0, 2}, {1, 1}}
	r4 := [][2]int{{0, 2}, {1, 0}, {2, 1}}
	r5 := [][2]int{{0, 0}, {1, 0}, {2, 1}}
	r6 := [][2]int{{0, 1}, {1, 2}, {2, 3}}
	r7 := [][2]int{{0, 3}, {1, 4}, {2, 0}}
	r8 := [][2]int{{0, 0}, {1, 1}, {2, 1}, {3, 1}, {4, 1}}

	test(a1, 1, r1)
	test(a2, 1, r2)
	test(a3, 1, r3)
	test(a4, 1, r4)
	test(a5, 1, r5)
	test(a6, 1, r6)
	test(a7, 5, r7)
	test(a8, 2, r8)
}

func test(a []any, v int, r [][2]int) {
	t := freqcount(a, v)
	assert(len(t) == len(r))
	for i := range t {
		assert(t[i] == r[i])
	}
}

func freqcount(p []any, v int) [][2]int {
	m := make(map[int]int)
	q := []any{p}
	l := []int{0}
	d := 0
	for len(q) > 0 {
		switch u := q[0].(type) {
		case []any:
			for i := range u {
				switch u := u[i].(type) {
				case []any:
					q = append(q, u)
					l = append(l, l[0]+1)
					d = max(d, l[0]+1)

				case int:
					if u == v {
						m[l[0]]++
					}

				default:
					panic("unreachable")
				}
			}
		}

		q = q[1:]
		l = l[1:]
	}

	for i := 0; i <= d; i++ {
		if _, f := m[i]; !f {
			m[i] = 0
		}
	}

	var r [][2]int
	for k, v := range m {
		r = append(r, [2]int{k, v})
	}
	sort.Slice(r, func(i, j int) bool {
		return r[i][0] < r[j][0]
	})

	return r
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

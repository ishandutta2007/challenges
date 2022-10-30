/*

Let's start with some definitions:

a relation is a set of ordered pairs of elements (in this challenge, we'll be using integers)
For instance, [(1, 2), (5, 1), (-9, 12), (0, 0), (3, 2)] is a relation.

a relation is called transitive if for any two pairs of elements (a, b) and (b, c) in this relation, a pair (a, c) is also present,

[(1, 2), (2, 4), (6, 5), (1, 4)] is transitive, because it contains (1, 2) and (2, 4), but (1, 4) as well,

[(7, 8), (9, 10), (15, -5)] is transitive, because there aren't any two pairs (a, b), (c, d) present such that b = c.

[(5, 9), (9, 54), (0, 0)] is not transitive, because it contains (5, 9) and (9, 54), but not (5, 54)

Given a list of pairs of integers, determine if a relation is transitive or not.

Input / output
You will be given a list of pairs of integers in any reasonable format. Consider a relation

[(1, 6), (9, 1), (6, 5), (0, 0)]

The following formats are equivalent:

[(1, 6), (9, 1), (6, 5), (0, 0)] # list of pairs (2-tuples)
[1, 9, 6, 0], [6, 1, 5, 0] # two lists [x1, x2, ..., xn] [y1, y2, ..., yn]
[[1, 6], [9, 1], [6, 5], [0, 0] # two-dimentional int array
[4, 1, 6, 9, 1, 6, 5, 0, 0] # (n, x1, y1, ..., xn, yn)
[1+6i, 9+i, 6+5i, 0+0i] # list of complex numbers

... many others, whatever best suits golfing purposes
Output: a truthy value for a transitive relation, falsy otherwise. You may assume that the input will consist of at least one pair, and that the pairs are unique.

*/

package main

func main() {
	assert(transitive([][2]int{{1, 2}, {5, 1}, {-9, 12}, {0, 0}, {3, 2}}) == false)
	assert(transitive([][2]int{{1, 2}, {2, 4}, {6, 5}, {1, 4}}) == true)
	assert(transitive([][2]int{{7, 8}, {9, 10}, {15, -5}}) == true)
	assert(transitive([][2]int{{5, 9}, {9, 54}, {0, 0}}) == false)
	assert(transitive([][2]int{{1, 6}, {9, 1}, {6, 5}, {0, 0}}) == false)
	assert(transitive([][2]int{{1, 6}, {6, 5}, {1, 5}, {0, 0}, {9, 1}, {9, 6}, {9, 5}}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func transitive(a [][2]int) bool {
	m := make(map[int]map[int]bool)
	for _, p := range a {
		x, y := p[0], p[1]
		if m[x] == nil {
			m[x] = make(map[int]bool)
		}
		m[x][y] = true
	}

	for x, p := range m {
		for y := range p {
			for z := range m[y] {
				if !m[x][z] {
					return false
				}
			}
		}
	}
	return true
}

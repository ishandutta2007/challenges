/*

Matryoshka dolls are traditionally wooden dolls that can be nested by fitting smaller dolls into larger ones.
Suppose arrays can be nested similarly, placing smaller arrays into larger ones, in the following sense:

Array A can be nested inside Array B if:

    min(array A) > min(array B)
    max(array A) < max(array B)

For example, if A = [2, 3, 9, 5] and B = [10, 2, 1], then A can be nested inside B, since:

    min(A) = 2 > 1 = min(B) and
    max(A) = 9 < 10 = max(B)

Create a function that returns true if every single sub-array inside an array can be nested Matroyshka style, and false otherwise.
Examples

matryoshka([[2, 2, 7], [3, 4, 5, 6], [4, 5]]) ➞ true
// [4, 5] nested inside [3, 4, 5, 6], [3, 4, 5, 6] nested inside [2, 2, 7], etc.
// Dolls nested from largest to smallest.

matryoshka([[4, 5], [6, 3], [7, 6, 5, 4, 3, 2], [8, 1]]) ➞ true
// Dolls nested from smallest to largest.

matryoshka([[7, 1], [7, 6, 5, 4, 3, 2], [6, 3], [4, 5]]) ➞ false
// [7, 1] and [7, 6, 5, 4, 3, 2] share the same max.
// Second doll cannot be nested properly inside first doll.

matryoshka([[1, 5], [2, 6], [3, 7]]) ➞ false
// Elements are overlapping, cannot be nested.

Notes

    Subarrays can be nested from smallest to largest or largest to smallest.
    Elements must be strictly nested - e.g. no two arrays can share either the same MAX or the same MIN (see example #3).
    Subarrays may not necessarily have unique elements (see example #1).
    Subarrays can be in any order (see example #2).

*/

package main

import (
	"math"
	"sort"
)

func main() {
	assert(matryoshka([][]int{{2, 3, 9, 5}, {10, 2, 1}}) == true)
	assert(matryoshka([][]int{{2, 2, 7}, {3, 4, 5, 6}, {4, 5}}) == true)
	assert(matryoshka([][]int{{4, 5}, {6, 3}, {7, 6, 5, 4, 3, 2}, {8, 1}}) == true)
	assert(matryoshka([][]int{{7, 1}, {7, 6, 5, 4, 3, 2}, {6, 3}, {4, 5}}) == false)
	assert(matryoshka([][]int{{1, 5}, {2, 6}, {3, 7}}) == false)
	assert(matryoshka([][]int{{1, 2, 3, 4, 5, 6, 7, 8}, {2, 3, 4, 5, 6, 7}, {3, 4, 5, 6}, {4, 5}}) == true)
	assert(matryoshka([][]int{{4, 5}, {2, 6}, {1, 9}, {-5, 10, 11}}) == true)
	assert(matryoshka([][]int{{3, 3}, {4, 4}, {5, 5, 5}}) == false)
	assert(matryoshka([][]int{{1, 1, 1, 1, 2}, {3, 2, 5, 0}, {-1, 500}}) == true)
	assert(matryoshka([][]int{{1, 8}, {2, 3, 4, 5, 6, 7}, {3, 6}, {4, 5}}) == true)
	assert(matryoshka([][]int{{6, 2}, {9, 4}}) == false)
	assert(matryoshka([][]int{{7, 1}, {7, 6, 5, 4, 3, 2}, {6, 3}, {4, 5}}) == false)
	assert(matryoshka([][]int{{1, 5}, {2, 6}, {3, 7}}) == false)
	assert(matryoshka([][]int{{5, 1}, {4, 2}, {4, 2}}) == false)
	assert(matryoshka([][]int{{5, 1}, {4, 2}, {3, 3}}) == true)
	assert(matryoshka([][]int{{5, 1}, {4, 2}, {3, 3, 3, 3, 3, 3, 3}}) == true)
	assert(matryoshka([][]int{{1, 2, 3, 4}, {2, 3, 4}}) == false)
	assert(matryoshka([][]int{{1, 2, 3, 4}, {2, 3}}) == true)
	assert(matryoshka([][]int{{1, 50, 100}, {3, 25, 75}, {10, 40, 50}, {25, 45}}) == true)
	assert(matryoshka([][]int{{1, 50, 100}, {3, 25, 75}, {10, 40, 50}, {25, 55}}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func matryoshka(a [][]int) bool {
	r := make([][2]int, len(a))
	for i := range a {
		r[i][0] = math.MaxInt32
		r[i][1] = math.MinInt32
		for j := range a[i] {
			r[i][0] = min(r[i][0], a[i][j])
			r[i][1] = max(r[i][1], a[i][j])
		}
	}
	sort.Slice(r, func(i, j int) bool {
		return r[i][1] < r[j][1]
	})

	for i := 1; i < len(r); i++ {
		if !(r[i-1][0] > r[i][0] && r[i-1][1] < r[i][1]) {
			return false
		}
	}
	return true
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

/*

Input

Take a list of values xi each paired with a key yi.

[(x1, y1), (x2, y2), ...]

Output

Return a list L containing only values from the set {xi}.

    The length of L must be equal to the number of unique keys k in the set {yi}.
    For each unique key k there must be a value from {xi} that has key k.

Details

    Standard loopholes disallowed.
    You can assume all values in the input will be nonnegative integers.
    There may be duplicate values and keys.
    You can assume there is at least one value/key pair in the input.
    If you prefer to take two lists of equal length as input (one for values, one for keys) that is fine.
    You may not take any other input.
    The order of the list you output does not matter.
    The xi you choose for each key does not matter.

For example, with input [[0, 0], [1, 3], [2, 3]] you can return either [0, 1] or [0, 2] or any permutation of these.
Examples

[[1, 2], [3, 2], [3, 0]]  -> [1, 3] or [3, 3]
[[7, 2], [7, 0], [7, 1]]  -> [7, 7, 7]
[[4, 0], [4, 0], [9, 1], [5, 2]]  -> [4, 9, 5]
[[9, 1], [99, 10], [5, 5], [0, 3]]  -> [9, 99, 5, 0]

Fewest bytes wins.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][2]int{{1, 2}, {3, 2}, {3, 0}}, []int{3, 3})
	test([][2]int{{7, 2}, {7, 0}, {7, 1}}, []int{7, 7, 7})
	test([][2]int{{4, 0}, {4, 0}, {9, 1}, {5, 2}}, []int{4, 9, 5})
	test([][2]int{{9, 1}, {99, 10}, {5, 5}, {0, 3}}, []int{9, 99, 5, 0})
}

func test(a [][2]int, r []int) {
	p := uniq(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func uniq(a [][2]int) []int {
	r := []int{}
	m := make(map[int]int)
	for i := range a {
		v := a[i][0]
		k := a[i][1]

		if j, f := m[k]; f {
			r[j] = v
		} else {
			r, m[k] = append(r, v), i
		}
	}
	return r
}

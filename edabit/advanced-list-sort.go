/*

Create a function that takes a list of numbers or strings and returns a list with the items from the original list stored into sublists.
Items of the same value should be in the same sublist.

Examples

advanced_sort([2, 1, 2, 1]) ➞ [[2, 2], [1, 1]]

advanced_sort([5, 4, 5, 5, 4, 3]) ➞ [[5, 5, 5], [4, 4], [3]]

advanced_sort(["b", "a", "b", "a", "c"]) ➞ [["b", "b"], ["a", "a"], ["c"]]

Notes

The sublists should be returned in the order of each element's first appearance in the given list.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]interface{}{1, 2, 1, 2}, [][]interface{}{{1, 1}, {2, 2}})
	test([]interface{}{2, 1, 2, 1}, [][]interface{}{{2, 2}, {1, 1}})
	test([]interface{}{3, 2, 1, 3, 2, 1}, [][]interface{}{{3, 3}, {2, 2}, {1, 1}})
	test([]interface{}{5, 5, 4, 3, 4, 4}, [][]interface{}{{5, 5}, {4, 4, 4}, {3}})
	test([]interface{}{80, 80, 4, 60, 60, 3}, [][]interface{}{{80, 80}, {4}, {60, 60}, {3}})
	test([]interface{}{'c', 'c', 'b', 'c', 'b', 1, 1}, [][]interface{}{{'c', 'c', 'c'}, {'b', 'b'}, {1, 1}})
	test([]interface{}{1234, 1235, 1234, 1235, 1236, 1235}, [][]interface{}{{1234, 1234}, {1235, 1235, 1235}, {1236}})
	test([]interface{}{"1234", "1235", "1234", "1235", "1236", "1235"}, [][]interface{}{{"1234", "1234"}, {"1235", "1235", "1235"}, {"1236"}})
}

func test(a []interface{}, r [][]interface{}) {
	p := advsort(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func advsort(a []interface{}) (p [][]interface{}) {
	m := make(map[interface{}]int)
	n := 0
	for _, v := range a {
		if i, f := m[v]; f {
			p[i] = append(p[i], v)
		} else {
			p = append(p, []interface{}{v})
			m[v], n = n, n+1
		}
	}
	return p
}

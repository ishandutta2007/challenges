/*

Write a function that moves all elements of one type to the end of the list.

Examples

move_to_end([1, 3, 2, 4, 4, 1], 1) ➞ [3, 2, 4, 4, 1, 1]
# Move all the 1s to the end of the array.

move_to_end([7, 8, 9, 1, 2, 3, 4], 9) ➞ [7, 8, 1, 2, 3, 4, 9]

move_to_end(["a", "a", "a", "b"], "a") ➞ ["b", "a", "a", "a"]

Notes

Keep the order of the un-moved items the same.

*/

package main

import (
	"reflect"
)

func main() {
	test([]interface{}{1, 3, 2, 4, 4, 1}, 1, []interface{}{3, 2, 4, 4, 1, 1})
	test([]interface{}{7, 8, 9, 1, 2, 3, 4}, 9, []interface{}{7, 8, 1, 2, 3, 4, 9})
	test([]interface{}{7, 7, 7, 6, 6, 6, 6}, 7, []interface{}{6, 6, 6, 6, 7, 7, 7})
	test([]interface{}{"a", "c", "c", "c", "b", "c"}, "b", []interface{}{"a", "c", "c", "c", "c", "b"})
	test([]interface{}{"a", "c", "c", "c", "b", "c"}, "c", []interface{}{"a", "b", "c", "c", "c", "c"})
	test([]interface{}{"a", "a", "a", "b"}, "a", []interface{}{"b", "a", "a", "a"})
}

func test(a []interface{}, v interface{}, r []interface{}) {
	p := move2end(a, v)
	assert(reflect.DeepEqual(p, r))
}

func move2end(a []interface{}, v interface{}) []interface{} {
	p := make([]interface{}, len(a))
	i := 0
	j := len(a) - 1
	for k := range a {
		if a[k] != v {
			p[i], i = a[k], i+1
		} else {
			p[j], j = a[k], j-1
		}
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

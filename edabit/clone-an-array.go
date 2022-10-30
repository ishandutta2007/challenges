/*

The Code tab has a code which attempts to add a clone of an array to itself. There is no error message, but the results are not as expected. Can you fix the code?

Examples

clone([1, 1]) ➞ [1, 1, [1, 1]]

clone([1, 2, 3]) ➞ [1, 2, 3, [1, 2, 3]]

clone(["x", "y"]) ➞ ["x", "y", ["x", "y"]]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]any{1, 1}, []any{1, 1, []any{1, 1}})
	test([]any{1, 2, 3}, []any{1, 2, 3, []any{1, 2, 3}})
	test([]any{"x", "y"}, []any{"x", "y", []any{"x", "y"}})
	test([]any{"a", "b", "c"}, []any{"a", "b", "c", []any{"a", "b", "c"}})
	test([]any{}, []any{[]any{}})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []any) {
	p := clone(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func clone(a []any) []any {
	r := append([]any{}, a...)
	r = append(r, a)
	return r
}

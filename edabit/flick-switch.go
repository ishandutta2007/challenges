/*

Create a function that always returns true for every item in a given array. However, if an element is the word "flick", switch to always returning the opposite boolean value.

Examples

switches(["edabit", "flick", "eda", "bit"]) ➞ [true, false, false, false]

switches(["flick", 11037, 3.14, 53]) ➞ [false, false, false, false]

switches([false, false, "flick", "sheep", "flick"]) ➞ [true, true, false, false, true]

Notes

	"flick" will always be given in lowercase.
	An array may contain multiple flicks.
	Switch the boolean value on the same element as the flick itself.

*/

package main

import "reflect"

func main() {
	test([]interface{}{"edabit", "flick", "eda", "bit"}, []bool{true, false, false, false})
	test([]interface{}{"flick", 11037, 3.14, 53}, []bool{false, false, false, false})
	test([]interface{}{false, false, "flick", "sheep", "flick"}, []bool{true, true, false, false, true})
	test([]interface{}{[]string{"john", "smith", "susan"}, "flick"}, []bool{true, false})
	test([]interface{}{"flick", "flick", "flick", "flick", "flick"}, []bool{false, true, false, true, false})
	test([]interface{}{}, []bool{})
}

func switches(v []interface{}) []bool {
	b := make([]bool, len(v))
	t := true
	for i := range v {
		if v[i] == "flick" {
			t = !t
		}
		b[i] = t
	}
	return b
}

func test(v []interface{}, r []bool) {
	b := switches(v)
	assert(reflect.DeepEqual(b, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

According to the lodash documentation, _.drop creates a slice of an array with n elements dropped from the beginning.

Your challenge is to write your own version using vanilla JavaScript.

Examples

drop([1, 2, 3], 1) ➞ [2, 3]

drop([1, 2, 3], 2) ➞ [3]

drop([1, 2, 3], 5) ➞ []

drop([1, 2, 3], 0) ➞ [1, 2, 3]

Notes

    Do not attempt to import lodash; you are simply writing your own version.
    This entire series of challenges can be found here.

*/

package main

import "reflect"

func main() {
	test([]interface{}{1, 2, 3}, 2, []interface{}{3})
	test([]interface{}{1, 2, 3}, 5, []interface{}{})
	test([]interface{}{1, 2, 3}, 0, []interface{}{1, 2, 3})
	test([]interface{}{"banana", "orange", "watermelon", "mango"}, 2, []interface{}{"watermelon", "mango"})
	test([]interface{}{}, 2, []interface{}{})
}

func test(a []interface{}, n int, r []interface{}) {
	p := drop(a, n)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func drop(a []interface{}, n int) []interface{} {
	if n < 0 {
		return a
	}
	if n > len(a) {
		n = len(a)
	}
	return a[n:]
}

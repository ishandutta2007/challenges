/*

Create a function that takes an array of strings and integers, and filters out the array so that it returns an array of integers only.

Examples

filter_array([1, 2, 3, "a", "b", 4]) ➞ [1, 2, 3, 4]

filter_array(["A", 0, "Edabit", 1729, "Ruby", "1729"]) ➞ [0, 1729]

filter_array(["Nothing", "here"]) ➞ []

Notes

Don't overthink this one.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]interface{}{1, 2, 3, "a", "b", 4}, []int{1, 2, 3, 4})
	test([]interface{}{"A", 1, "&amp", 0, -9, "Edabit"}, []int{1, 0, -9})
	test([]interface{}{"Nothing", "here"}, []int{})
}

func test(a []interface{}, r []int) {
	p := filter(a)
	fmt.Println(p)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func filter(a []interface{}) []int {
	var r []int
	for _, p := range a {
		switch v := p.(type) {
		case int:
			r = append(r, v)
		}
	}
	return r
}

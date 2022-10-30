/*

According to the lodash documentation, _.compact creates an array with all falsey values removed. The values false, null, 0, "", undefined, and NaN are falsey.

Your task is to build this helper function without using lodash. You will write a function that receives an array and removes all falsey values.
Examples

compact([0, 1, false, 2, "", 3]);   // => [1, 2, 3]

Notes

    Do not attempt to import lodash; you are simply writing your own version.
    This entire series of challenges can be found here.

*/

package main

import (
	"fmt"
	"math"
	"reflect"
)

func main() {
	test([]interface{}{1, 0, false, nil, "banana"}, []interface{}{1, "banana"})
	test([]interface{}{}, []interface{}{})

	m1 := map[string]string{"color": "red", "make": "toyota"}
	m2 := map[string]string{"color": "blue", "make": "mazda"}
	test([]interface{}{m1, m2, nil}, []interface{}{m1, m2})
}

func test(a, r []interface{}) {
	p := compact(a)
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

func compact(a []interface{}) []interface{} {
	j := 0
	for _, v := range a {
		if !falsey(v) {
			a[j], j = v, j+1
		}
	}
	return a[:j]
}

func falsey(v interface{}) bool {
	if v == nil {
		return true
	}

	rv := reflect.ValueOf(v)
	if rv.IsZero() {
		return true
	}

	switch rv.Kind() {
	case reflect.Float32, reflect.Float64:
		return math.IsNaN(rv.Float())
	}

	return false
}

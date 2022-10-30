/*

Write a function that inverts the keys and values of a dictionary.

Examples

invert({ "z": "q", "w": "f" })
➞ { "q": "z", "f": "w" }

invert({ "a": 1, "b": 2, "c": 3 })
➞ { 1: "a", 2: "b", 3: "c" }

invert({ "zebra": "koala", "horse": "camel" })
➞ { "koala": "zebra", "camel": "horse" }

Notes

N/A

*/

package main

import "reflect"

func main() {
	m1 := map[interface{}]interface{}{
		"a": 1, "b": 2, "c": 3,
	}
	p1 := map[interface{}]interface{}{
		1: "a", 2: "b", 3: "c",
	}

	m2 := map[interface{}]interface{}{
		"z": "q", "w": "f",
	}
	p2 := map[interface{}]interface{}{
		"q": "z", "f": "w",
	}

	m3 := map[interface{}]interface{}{
		"zebra": "koala", "horse": "camel",
	}
	p3 := map[interface{}]interface{}{
		"koala": "zebra", "camel": "horse",
	}

	test(m1, p1)
	test(m2, p2)
	test(m3, p3)
}

func test(m, r map[interface{}]interface{}) {
	p := invert(m)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func invert(m map[interface{}]interface{}) map[interface{}]interface{} {
	p := make(map[interface{}]interface{})
	for k, v := range m {
		p[v] = k
	}
	return p
}

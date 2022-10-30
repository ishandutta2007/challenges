/*

A function takes in two hashes as input. Both hashes contain exactly the same keys.
Return an array of keys where the values in each hash differs.

Examples

differs({a: 1, b: 2, c: 3}, {a: 3, b: 2, c: 1}) ➞ ["a", "c"]

differs({a: 1, b: 1, c: 1}, {a: 2, b: 2, c: 2}) ➞ ["a", "b", "c"]

differs({a: 3, b: 3, c: 3}, {a: 3, b: 3, c: 3}) ➞ []

Notes

N/A

*/

package main

import (
	"reflect"
	"sort"
)

func main() {
	test(map[string]int{"a": 1, "b": 2, "c": 3}, map[string]int{"a": 3, "b": 2, "c": 1}, []string{"a", "c"})
	test(map[string]int{"a": 1, "b": 1, "c": 1}, map[string]int{"a": 2, "b": 2, "c": 2}, []string{"a", "b", "c"})
	test(map[string]int{"a": 3, "b": 3, "c": 3}, map[string]int{"a": 3, "b": 3, "c": 3}, []string{})
}

func test(m, n map[string]int, r []string) {
	assert(reflect.DeepEqual(differs(m, n), r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func differs(m, n map[string]int) []string {
	p := []string{}
	for k := range m {
		if m[k] != n[k] {
			p = append(p, k)
		}
	}
	sort.Strings(p)
	return p
}

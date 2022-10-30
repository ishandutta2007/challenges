/*

In this challenge you will receive an input of the form:

[[[[[[[[[[[]]]]]]]]]]]

In other words, an array containing an array containing an array containing... an array containing nothing.

Your goal is to measure the depth of this array, where [] has a depth 1, [[]] has depth of 2, [[[]]] has depth 3, etc.
Examples

measureDepth([]) ➞ 1

measureDepth([[]]) ➞ 2

measureDepth([[[]]]) ➞ 3

measureDepth([[[[[[[[[[[]]]]]]]]]]]) ➞ 11

Notes

For a bonus challenge, try to find a solution without recursion.

*/

package main

import (
	"reflect"
)

func main() {
	test("[]", 1)
	test("[[]]", 2)
	test("[[[]]]", 3)
	test("[[[[[[]]]]]]", 6)
	test("[[[[[[[[]]]]]]]]", 8)
	test("[[[[[[[[[[[[[]]]]]]]]]]]]]", 13)
	test("[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]", 17)
	test("[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]", 18)
}

func test(s string, r int) {
	assert(depth(emptify(s)) == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func depth(v interface{}) int {
	n := 0
	rv := reflect.ValueOf(v)
	for {
		if rv.Kind() == reflect.Interface {
			rv = rv.Elem()
		}
		if rv.Kind() != reflect.Slice || rv.Len() == 0 {
			break
		}

		rv, n = rv.Index(0), n+1
	}
	return n
}

func emptify(s string) (v interface{}) {
	p := 0
	i := 0
	for ; i < len(s); i, p = i+1, p+1 {
		if s[i] != '[' {
			break
		}
		v = []interface{}{v}
	}
	for ; i < len(s); i, p = i+1, p-1 {
		if s[i] != ']' {
			return nil
		}
	}

	if p != 0 {
		return nil
	}

	return
}

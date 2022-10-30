/*

Write a function that accepts the width and height (m, n) and an optional proc s and generates a list with m elements. Each element is a string consisting of either:

    The default character (hash #) repeating n times (if no proc is given).
    The character passed in through the proc repeating n times.

Examples

make_rug(3, 5) ➞ [
  "#####",
  "#####",
  "#####"
]

make_rug(3, 5, '$')  ➞ [
  "$$$$$",
  "$$$$$",
  "$$$$$"
]

make_rug(2, 2, 'A')  ➞ [
  "AA"
  "AA"
]

Notes

You can set a value for the parameter when creating the function e.g. def func(x = 3)

*/

package main

import (
	"reflect"
	"strings"
)

func main() {
	test(3, 5, "#", []string{
		"#####",
		"#####",
		"#####",
	})
	test(3, 5, "$", []string{
		"$$$$$",
		"$$$$$",
		"$$$$$",
	})
	test(2, 2, "A", []string{
		"AA",
		"AA",
	})
	test(3, 1, "b", []string{
		"b",
		"b",
		"b",
	})
	test(2, 1, "bcb", []string{
		"bcb",
		"bcb",
	})
}

func rug(m, n int, p string) []string {
	r := strings.Repeat(p, n)
	var s []string
	for i := 0; i < m; i++ {
		s = append(s, r)
	}
	return s
}

func test(m, n int, p string, r []string) {
	assert(reflect.DeepEqual(rug(m, n, p), r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

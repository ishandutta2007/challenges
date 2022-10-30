/*

Create a function that divides a string into parts of size n.
Examples

partition("chew", 2) ➞ ["ch", "ew"]

partition("thematic", 4) ➞ ["them", "atic"]

partition("c++", 2) ➞ ["c+", "+"]

Notes

For inputs that do not split evenly into parts of size n, the last element in the array will have a "leftover" string (see example #3).

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("them", 2, []string{"th", "em"})
	test("thematic", 4, []string{"them", "atic"})
	test("movement", 2, []string{"mo", "ve", "me", "nt"})
	test("python", 2, []string{"py", "th", "on"})
	test("c++", 2, []string{"c+", "+"})
}

func test(s string, n int, r []string) {
	p := partition(s, n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func partition(s string, n int) []string {
	var (
		p []string
		m int
		u string
	)
	for _, r := range s {
		u += string(r)
		if m++; m == n {
			p, m, u = append(p, u), 0, ""
		}
	}
	if u != "" {
		p = append(p, u)
	}

	return p
}

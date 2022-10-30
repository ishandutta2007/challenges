/*

Create a function that takes two parameters and, if both parameters are strings, add them as if they were integers or if the two parameters are integers, concatenate them.
Examples

stupid_addition(1, 2) ➞ "12"

stupid_addition("1", "2") ➞ 3

stupid_addition("1", 2) ➞ None

Notes

    If the two parameters are different data types, return None.
    All parameters will either be strings or integers.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	assert(add(1, 2) == "12")
	assert(add("1", "2") == 3)
	assert(add(1, "2") == nil)
	assert(add("1", 2) == nil)
}

func add(x, y interface{}) interface{} {
	a, i1 := x.(int)
	b, i2 := y.(int)
	if i1 && i2 {
		return fmt.Sprintf("%d%d", a, b)
	}

	s, s1 := x.(string)
	t, s2 := y.(string)
	if s1 && s2 {
		a, _ := strconv.Atoi(s)
		b, _ := strconv.Atoi(t)
		return a + b
	}

	return nil
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

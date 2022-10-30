/*

Create a function that creates a pattern as a 2D array for a given number.
Examples

 >
 >>
 >>>
 >>
 >

arrow(3) ➞ [">", ">>", ">>>", ">>", ">"]

 >
 >>
 >>>
 >>>>
 >>>>
 >>>
 >>
 >

arrow(4) ➞ [">", ">>", ">>>", ">>>>", ">>>>", ">>>", ">>", ">"]

Notes

Function argument will always be a number greater than 0.

*/

package main

import (
	"strings"
)

func main() {
	eq(arrow(0), []string{})
	eq(arrow(3), []string{">", ">>", ">>>", ">>", ">"})
	eq(arrow(4), []string{">", ">>", ">>>", ">>>>", ">>>>", ">>>", ">>", ">"})
	eq(arrow(7), []string{">", ">>", ">>>", ">>>>", ">>>>>", ">>>>>>", ">>>>>>>", ">>>>>>", ">>>>>", ">>>>", ">>>", ">>", ">"})
	eq(arrow(8), []string{">", ">>", ">>>", ">>>>", ">>>>>", ">>>>>>", ">>>>>>>", ">>>>>>>>", ">>>>>>>>", ">>>>>>>", ">>>>>>", ">>>>>", ">>>>", ">>>", ">>", ">"})
	eq(arrow(9), []string{">", ">>", ">>>", ">>>>", ">>>>>", ">>>>>>", ">>>>>>>", ">>>>>>>>", ">>>>>>>>>", ">>>>>>>>", ">>>>>>>", ">>>>>>", ">>>>>", ">>>>", ">>>", ">>", ">"})
	eq(arrow(10), []string{">", ">>", ">>>", ">>>>", ">>>>>", ">>>>>>", ">>>>>>>", ">>>>>>>>", ">>>>>>>>>", ">>>>>>>>>>", ">>>>>>>>>>", ">>>>>>>>>", ">>>>>>>>", ">>>>>>>", ">>>>>>", ">>>>>", ">>>>", ">>>", ">>", ">"})
}

func arrow(n int) []string {
	var p []string
	for i := 1; i <= n; i++ {
		p = append(p, strings.Repeat(">", i))
	}
	for i := n - (n & 1); i > 0; i-- {
		p = append(p, strings.Repeat(">", i))
	}
	return p
}

func eq(s, t []string) {
	assert(len(s) == len(t))
	for i := range s {
		assert(s[i] == t[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

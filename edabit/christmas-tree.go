/*

Write a function to create a Christmas tree based on height h.

Examples

tree(1) ➞ [
  "#"
]

tree(2) ➞ [
  " # ",
  "###"
]

tree(5) ➞ [
  "    #    ",
  "   ###   ",
  "  #####  ",
  " ####### ",
  "#########"
]

tree(0) ➞ []

Notes

N/A

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	test(0)
	test(1)
	test(2)
	test(5)
}

func test(n uint) {
	p := tree(n)
	fmt.Println(n)
	for i := range p {
		fmt.Printf("%q\n", p[i])
	}
	fmt.Println()
}

func tree(n uint) []string {
	p := make([]string, n)
	a := 2*int(n) - 1
	for i := range p {
		b := 2*(i+1) - 1
		p[i] = strings.Repeat(" ", (a-b)/2)
		p[i] += strings.Repeat("#", b)
		p[i] += strings.Repeat(" ", (a-b)/2)
	}
	return p
}

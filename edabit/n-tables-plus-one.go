/*

Create a function that takes a number n and returns the first 10 multiples of n with 1 added to it, separated by commas.

Examples

nTablesPlusOne(7) ➞ "8,15,22,29,36,43,50,57,64,71"

nTablesPlusOne(1) ➞ "2,3,4,5,6,7,8,9,10,11"

nTablesPlusOne(3) ➞ "4,7,10,13,16,19,22,25,28,31"

Notes

There is no comma after the last number.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(table(7) == "8,15,22,29,36,43,50,57,64,71")
	assert(table(1) == "2,3,4,5,6,7,8,9,10,11")
	assert(table(3) == "4,7,10,13,16,19,22,25,28,31")
	assert(table(134) == "135,269,403,537,671,805,939,1073,1207,1341")
}

func table(n int) string {
	w := new(bytes.Buffer)
	for i := 1; i <= 10; i++ {
		fmt.Fprintf(w, "%d,", n*i+1)
	}
	s := w.String()
	return s[:len(s)-1]
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

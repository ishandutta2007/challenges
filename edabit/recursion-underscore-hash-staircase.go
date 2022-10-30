/*

Create a function that will build a staircase using the underscore _ and hash # symbols. A positive value denotes the staircase's upward direction and downwards for a negative value.
Examples

staircase(3) ➞ "__#\n_##\n###"
__#
_##
###

staircase(7) ➞ "______#\n_____##\n____###\n___####\n__#####\n_######\n#######"
______#
_____##
____###
___####
__#####
_######
#######

staircase(2) ➞ "_#\n##"
_#
##

staircase(-8) ➞ "########\n_#######\n__######\n___#####\n____####\n_____###\n______##\n_______#"
########
_#######
__######
___#####
____####
_____###
______##
_______#

Notes

    All inputs are either positive or negative values.
	The string to be returned should be adjoined with the newline character \n.
	You're expected to solve this challenge using a recursive approach.
	You can read more on recursion (see Resources tab) if you aren't familiar with it or haven't fully understood the concept before taking this challenge.
	If you think recursion is fun, you can find a collection of those challenges here.
	A non-recursive version of this challenge can be found here.

*/

package main

import (
	"bytes"
	"fmt"
	"io"
)

func main() {
	test(3, "__#\n_##\n###")
	test(7, "______#\n_____##\n____###\n___####\n__#####\n_######\n#######")
	test(2, "_#\n##")
	test(-8, "########\n_#######\n__######\n___#####\n____####\n_____###\n______##\n_______#")
	test(4, "___#\n__##\n_###\n####")
	test(-12, "############\n_###########\n__##########\n___#########\n____########\n_____#######\n______######\n_______#####\n________####\n_________###\n__________##\n___________#")
	test(11, "__________#\n_________##\n________###\n_______####\n______#####\n_____######\n____#######\n___########\n__#########\n_##########\n###########")
	test(-6, "######\n_#####\n__####\n___###\n____##\n_____#")
	test(0, "")
	test(1, "_")
	test(-1, "#")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, t string) {
	s := staircase(n)
	fmt.Printf("staircase=%d\n%s\n\n", n, s)
	assert(s == t)
}

func staircase(n int) string {
	w := new(bytes.Buffer)
	switch {
	case n == 1:
		fmt.Fprintf(w, "_\n")
	case n >= 0:
		staircaser(w, n-1, 1, -1, 1)
	default:
		staircaser(w, 0, -n, 1, -1)
	}

	s := w.String()
	if len(s) > 0 {
		s = s[:len(s)-1]
	}
	return s
}

func staircaser(w io.Writer, u, h, du, dh int) {
	if u < 0 || h <= 0 {
		return
	}

	for i := 0; i < u; i++ {
		fmt.Fprintf(w, "_")
	}
	for i := 0; i < h; i++ {
		fmt.Fprintf(w, "#")
	}
	fmt.Fprintf(w, "\n")

	staircaser(w, u+du, h+dh, du, dh)
}

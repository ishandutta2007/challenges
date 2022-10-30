/*

Create a function that creates a box based on dimension n.
Examples

makeBox(5) ➞ [
  "#####",
  "#   #",
  "#   #",
  "#   #",
  "#####"
]

makeBox(3) ➞ [
  "###",
  "# #",
  "###"
]

makeBox(2) ➞ [
  "##",
  "##"
]

makeBox(1) ➞ [
  "#"
]

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	b1 := "#####\n" +
		"#   #\n" +
		"#   #\n" +
		"#   #\n" +
		"#####"

	b2 := "###\n" +
		"# #\n" +
		"###"

	b3 := "##\n" +
		"##"

	b4 := "#"

	b5 := "######\n" +
		"#    #\n" +
		"#    #\n" +
		"#    #\n" +
		"#    #\n" +
		"######"

	b6 := "####\n" +
		"#  #\n" +
		"#  #\n" +
		"####"

	assert(makebox(5) == b1)
	assert(makebox(3) == b2)
	assert(makebox(2) == b3)
	assert(makebox(1) == b4)
	assert(makebox(6) == b5)
	assert(makebox(4) == b6)
}

func makebox(n int) string {
	if n <= 0 {
		return ""
	}

	w := new(bytes.Buffer)
	c := strings.Repeat("#", n)
	fmt.Fprintln(w, c)
	for i := 1; i < n-1; i++ {
		fmt.Fprintf(w, "#")
		for j := 1; j < n-1; j++ {
			fmt.Fprintf(w, " ")
		}
		fmt.Fprintf(w, "#\n")
	}
	if n > 1 {
		fmt.Fprintln(w, c)
	}

	s := w.String()
	return s[:len(s)-1]
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

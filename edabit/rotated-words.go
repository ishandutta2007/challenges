/*

Some characters do not change after a rotation of 180 degrees. They can be read, although sometimes in a different way.
For example, uppercase letters "H", "I", "N", "O", "S", "X", "Z" after rotation are not changed, the letter "M" becomes a "W", and vice versa.

So, the word "WOW" turns into the word "MOM". On the other hand, the word "HOME" cannot be rotated.

Find the number of unique readable Rotated Words in the input string txt (without duplicates).
Examples

rotatedWords("HSSN") ➞ 1
// String can be rotated to a valid string

rotatedWords("OS IS UPDATED") ➞ 2
// "OS" and "IS" can be rotated to a valid string

rotatedWords("MUBASHIR") ➞ 0

Notes

String contains only uppercase letters.

*/

package main

import (
	"strings"
)

func main() {
	assert(rotatedwords("MUBASHIR") == 0)
	assert(rotatedwords("HSSN") == 1)
	assert(rotatedwords("ON") == 1)
	assert(rotatedwords("OS IS UPDATED") == 2)
	assert(rotatedwords("WHO IS WHO") == 2)
	assert(rotatedwords("JS") == 0)
	assert(rotatedwords("I III I III") == 2)
	assert(rotatedwords("SOS IN THE SEA") == 2)
	assert(rotatedwords("WHO IS rotatedWords AND WHO IS NO") == 3)
	assert(rotatedwords("SIN AND COS") == 1)
	assert(rotatedwords("I HAVE A GOOD JOB") == 1)
	assert(rotatedwords("HAVE A GOOD DAY") == 0)
	assert(rotatedwords("") == 0)
}

func rotatedwords(s string) int {
	if s == "" {
		return 0
	}

	m := make(map[string]bool)
	c := 0
	t := strings.Split(s, " ")
loop:
	for _, w := range t {
		for _, r := range w {
			if !rotatable(r) {
				continue loop
			}
		}
		if !m[w] {
			m[w] = true
			c++
		}
	}

	return c
}

func rotatable(r rune) bool {
	switch r {
	case 'H', 'I', 'N', 'O', 'S', 'X', 'Z', 'M', 'W':
		return true
	}
	return false
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

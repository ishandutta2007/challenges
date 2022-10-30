/*

Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

Note:

    You may use one character in the keyboard more than once.
    You may assume the input string will only contain letters of alphabet.

*/

package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Println(words([]string{"Hello", "Alaska", "Dad", "Peace"}))
}

func words(s []string) []string {
	m := map[rune]int{
		'Q': 1,
		'W': 1,
		'E': 1,
		'R': 1,
		'T': 1,
		'Y': 1,
		'U': 1,
		'I': 1,
		'O': 1,
		'P': 1,
		'A': 2,
		'S': 2,
		'D': 2,
		'F': 2,
		'G': 2,
		'H': 2,
		'J': 2,
		'K': 2,
		'L': 2,
		'Z': 3,
		'X': 3,
		'C': 3,
		'V': 3,
		'B': 3,
		'N': 3,
		'M': 3,
	}

	var p []string
loop:
	for _, w := range s {
		l := -1
		for _, r := range w {
			r = unicode.ToUpper(r)
			if m[r] == 0 {
				continue loop
			}
			if l < 0 {
				l = m[r]
			}
			if l != m[r] {
				continue loop
			}
		}
		p = append(p, w)
	}
	return p
}

/*

Mexican Wave Simulator

The wave (known as a Mexican wave in the English-speaking world outside North America) is an example of metachronal rhythm achieved in a packed stadium when successive groups of spectators briefly stand, yell, and raise their arms.

Create a function that takes a string and turns it into a Mexican Wave.

Notes

    All test cases will be lowercase strings.
    Ignore spaces (they are considered empty seats).
    An empty string should return an empty array.

*/

package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Printf("%q\n", wave("edabit"))
	fmt.Printf("%q\n", wave("just do it"))
	fmt.Printf("%q\n", wave("dogs cats pigs"))
	fmt.Printf("%q\n", wave(" "))
	fmt.Printf("%q\n", wave(""))
	fmt.Printf("%q\n", wave("G"))
	fmt.Printf("%q\n", wave(" blue"))
	fmt.Printf("%q\n", wave("green "))
}

func wave(s string) []string {
	var w []string
	for i, u := range s {
		if unicode.IsSpace(u) {
			continue
		}

		p := ""
		for j, r := range s {
			if i == j {
				r = unicode.ToUpper(r)
			}
			p += string(r)
		}
		w = append(w, p)
	}
	return w
}

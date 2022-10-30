/*

Create a function that splits a string into an array of identical clusters.

Notes

    Each cluster should only have one unique character.
    The resulting array should be in the same order as the input string.
    Should work with letters, numbers and other characters.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(splitgroups("aaabbbaabbab"))
	fmt.Println(splitgroups("5556667788"))
	fmt.Println(splitgroups("abbbcc88999&&!!!_"))
	fmt.Println(splitgroups("555"))
	fmt.Println(splitgroups("AABBCC"))
	fmt.Println(splitgroups(""))
}

func splitgroups(s string) []string {
	var p []string

	r := strings.NewReader(s)
	for {
		c, _, err := r.ReadRune()
		if err != nil {
			break
		}

		t := string(c)
		for {
			d, _, _ := r.ReadRune()
			if c != d {
				r.UnreadRune()
				break
			}
			t += string(c)
		}
		p = append(p, t)
	}

	return p
}

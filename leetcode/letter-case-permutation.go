/*

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

    S will be a string with length between 1 and 12.
    S will consist only of letters or digits.

*/

package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Println(perm("a1b2"))
	fmt.Println(perm("3z4"))
	fmt.Println(perm("12345"))
	fmt.Println(perm("abcdefghij"))
}

func perm(s string) []string {
	return permrec([]rune(s), 0)
}

func permrec(r []rune, i int) (p []string) {
	if i >= len(r) {
		p = append(p, string(r))
		return
	}

	lo := unicode.ToLower(r[i])
	up := unicode.ToUpper(r[i])

	r[i] = lo
	p = append(p, permrec(r, i+1)...)
	if lo != up {
		r[i] = up
		p = append(p, permrec(r, i+1)...)
	}
	return
}

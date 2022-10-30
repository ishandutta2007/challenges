/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

*/

package main

import (
	"fmt"
	"strings"
	"unicode/utf8"
)

func main() {
	fmt.Println(lcp([]string{"flower", "flow", "flight"}))
	fmt.Println(lcp([]string{"dog", "racecar", "car"}))
	fmt.Println(lcp([]string{"web", "web", "web"}))
}

func lcp(s []string) string {
	var p strings.Builder

	n := 0
loop:
	for {
		var a rune
		var l int
		for i := 0; i < len(s)-1; i++ {
			a, l = utf8.DecodeRuneInString(s[i][n:])
			b, _ := utf8.DecodeRuneInString(s[i+1][n:])
			if a != b {
				break loop
			}
		}
		if l == 0 {
			break
		}
		p.WriteRune(a)
		n += l
	}
	return p.String()
}

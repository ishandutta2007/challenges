/*

Challenge
Given two strings of letters, determine whether the second can be made from the first by removing one letter. The remaining letters must stay in the same order.

Examples
funnel("leave", "eave") => true
funnel("reset", "rest") => true
funnel("dragoon", "dragon") => true
funnel("eave", "leave") => false
funnel("sleet", "lets") => false
funnel("skiff", "ski") => false

*/

package main

import (
	"fmt"
	"unicode/utf8"
)

func main() {
	fmt.Println(funnel("leave", "eave"))
	fmt.Println(funnel("reset", "rest"))
	fmt.Println(funnel("dragoon", "dragon"))
	fmt.Println(funnel("eave", "leave"))
	fmt.Println(funnel("sleet", "lets"))
	fmt.Println(funnel("skiff", "ski"))
}

func funnel(a, b string) bool {
	i := 0
	j := 0
	for i < len(a) && j < len(b) {
		r1, s1 := utf8.DecodeRuneInString(a[i:])
		r2, s2 := utf8.DecodeRuneInString(b[j:])
		i += s1

		if r1 != r2 {
			return a[i:] == b[j:]
		}
		j += s2
	}
	return false
}

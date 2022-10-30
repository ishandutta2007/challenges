/*

You have an array of item codes with the following format: "[letters][digits]"

Create a function that splits these strings into their alphabetic and numeric parts.

*/

package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Println(splitcode("TEWA8392"))
	fmt.Println(splitcode("MMU778"))
	fmt.Println(splitcode("SRPE5532"))
	fmt.Println(splitcode("SKU8977"))
	fmt.Println(splitcode("MCI5589"))
	fmt.Println(splitcode("WIEB3921"))
}

func splitcode(s string) [2]string {
	var c [2]string
	for i, r := range s {
		if unicode.IsDigit(r) {
			c = [2]string{s[:i], s[i:]}
			break
		}
	}
	return c
}

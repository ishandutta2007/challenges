/*

Write a function that splits a string into substrings of size n, adding a specified delimiter between each of the pieces.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(splitdelim("bellow", 2, "&"))
	fmt.Println(splitdelim("magnify", 3, ":"))
	fmt.Println(splitdelim("poisonous", 2, "~"))
	fmt.Println(splitdelim("shape-shifting", 5, "^"))
	fmt.Println(splitdelim("nebulous", 1, "#"))
}

func splitdelim(s string, n int, d string) string {
	p := new(bytes.Buffer)
	i := 0
	for _, r := range s {
		if i >= n {
			i = 0
			p.WriteString(d)
		}
		p.WriteRune(r)
		i++
	}
	return p.String()
}

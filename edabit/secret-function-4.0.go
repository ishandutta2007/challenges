/*

Create a function based on the input and output. Look at the examples, there is a pattern.

Examples

secret("p.one.two.three") ➞ "<p class='one two three'></p>"

secret("p.one") ➞ "<p class='one'></p>"

secret("p.four.five") ➞ "<p class='four five'></p>"

Notes

Input is a string.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(secret("p.one.two.three") == "<p class='one two three'></p>")
	assert(secret("p.one") == "<p class='one'></p>")
	assert(secret("h3.one") == "<h3 class='one'></h3>")
	assert(secret("p.four.five") == "<p class='four five'></p>")
	assert(secret("p.a.b.c.d") == "<p class='a b c d'></p>")
	assert(secret("h1.a.b.c.d") == "<h1 class='a b c d'></h1>")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func secret(s string) string {
	t := strings.Split(s, ".")
	p := strings.Join(t[1:], " ")
	return fmt.Sprintf("<%s class='%s'></%s>", t[0], p, t[0])
}

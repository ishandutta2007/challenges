/*

Create a function that takes a string and returns the first character of every word if the length of the word is even and the middle character if the length of the word is odd.

Examples

stmid("Alexa have to paid") ➞ "ehtp"
// "e" is the middle character of "Alexa"
// "h" is the first character of "have"

stmid("Th3 0n3 4nd 0n1y") ➞ "hnn0"

stmid("who is the winner") ➞ "hihw"

Notes

N/A

*/

package main

import (
	"bytes"
	"strings"
)

func main() {
	assert(stmid("Alexa have to paid") == "ehtp")
	assert(stmid("Th3 0n3 4nd 0n1y") == "hnn0")
	assert(stmid("who is the winner") == "hihw")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func stmid(s string) string {
	w := new(bytes.Buffer)
	t := strings.Split(s, " ")
	for _, p := range t {
		r := []rune(p)
		n := len(r)
		if n&1 == 0 {
			w.WriteRune(r[0])
		} else {
			w.WriteRune(r[n/2])
		}
	}
	return w.String()
}

/*

Create a function which concantenates the number 7 to the end of every chord in an array. Ignore all chords which already end with 7.
Examples

jazzify(["G", "F", "C"]) ➞ ["G7", "F7", "C7"]

jazzify(["Dm", "G", "E", "A"]) ➞ ["Dm7", "G7", "E7", "A7"]

jazzify(["F7", "E7", "A7", "Ab7", "Gm7", "C7"]) ➞ ["F7", "E7", "A7", "Ab7", "Gm7", "C7"]

jazzify([]) ➞ []

Notes

    Return an empty array if the given array is empty.
    You can expect all the tests to have valid chords.

*/

package main

import (
	"strings"
)

func main() {
	eq(jazzify([]string{"G", "F", "C"}), []string{"G7", "F7", "C7"})
	eq(jazzify([]string{"Dm", "G", "E", "A"}), []string{"Dm7", "G7", "E7", "A7"})
	eq(jazzify([]string{"F7", "E7", "A7", "Ab7", "Gm7", "C7"}), []string{"F7", "E7", "A7", "Ab7", "Gm7", "C7"})
	eq(jazzify([]string{}), []string{})
}

func jazzify(s []string) []string {
	p := make([]string, len(s))
	for i := range s {
		p[i] = s[i]
		if !strings.HasSuffix(p[i], "7") {
			p[i] += "7"
		}
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(a, b []string) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

/*

Given a string, create a function which outputs an array, building and deconstructing the string letter by letter. See the examples below for some helpful guidance.
Examples

constructDeconstruct("Hello") ➞ [
  "H",
  "He",
  "Hel",
  "Hell",
  "Hello",
  "Hell",
  "Hel",
  "He",
  "H"
]

constructDeconstruct("edabit") ➞ [
  "e",
  "ed",
  "eda",
  "edab",
  "edabi",
  "edabit",
  "edabi",
  "edab",
  "eda",
  "ed",
  "e"
]

constructDeconstruct("the sun") ➞ [
  "t",
  "th",
  "the",
  "the ",
  "the s",
  "the su",
  "the sun",
  "the su",
  "the s",
  "the ",
  "the",
  "th",
  "t"
]

Notes

Include spaces (see example #3).

*/

package main

import (
	"bytes"
	"fmt"
	"reflect"
)

func main() {
	test("Hello", []string{
		"H",
		"He",
		"Hel",
		"Hell",
		"Hello",
		"Hell",
		"Hel",
		"He",
		"H",
	})

	test("edabit", []string{
		"e",
		"ed",
		"eda",
		"edab",
		"edabi",
		"edabit",
		"edabi",
		"edab",
		"eda",
		"ed",
		"e",
	})

	test("the sun", []string{
		"t",
		"th",
		"the",
		"the ",
		"the s",
		"the su",
		"the sun",
		"the su",
		"the s",
		"the ",
		"the",
		"th",
		"t",
	})

	test("so long partner", []string{"s", "so", "so ", "so l", "so lo", "so lon", "so long", "so long ", "so long p", "so long pa", "so long par", "so long part", "so long partn", "so long partne", "so long partner", "so long partne", "so long partn", "so long part", "so long par", "so long pa", "so long p", "so long ", "so long", "so lon", "so lo", "so l", "so ", "so", "s"})
	test("s p a c e s", []string{"s", "s ", "s p", "s p ", "s p a", "s p a ", "s p a c", "s p a c ", "s p a c e", "s p a c e ", "s p a c e s", "s p a c e ", "s p a c e", "s p a c ", "s p a c", "s p a ", "s p a", "s p ", "s p", "s ", "s"})
	test("edabit is a awesome", []string{"e", "ed", "eda", "edab", "edabi", "edabit", "edabit ", "edabit i", "edabit is", "edabit is ", "edabit is a", "edabit is a ", "edabit is a a", "edabit is a aw", "edabit is a awe", "edabit is a awes", "edabit is a aweso", "edabit is a awesom", "edabit is a awesome", "edabit is a awesom", "edabit is a aweso", "edabit is a awes", "edabit is a awe", "edabit is a aw", "edabit is a a", "edabit is a ", "edabit is a", "edabit is ", "edabit is", "edabit i", "edabit ", "edabit", "edabi", "edab", "eda", "ed", "e"})
	test("123456789", []string{"1", "12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789", "12345678", "1234567", "123456", "12345", "1234", "123", "12", "1"})
	test("", []string{})
	test("        ", []string{" ", "  ", "   ", "    ", "     ", "      ", "       ", "        ", "       ", "      ", "     ", "    ", "   ", "  ", " "})
}

func test(s string, r []string) {
	p := unravel(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func unravel(s string) []string {
	r := []string{}
	p := []rune(s)
	for i := 0; i < len(p); i++ {
		w := new(bytes.Buffer)
		for j := 0; j <= i; j++ {
			w.WriteRune(p[j])
		}
		r = append(r, w.String())
	}
	for i := len(r) - 2; i >= 0; i-- {
		r = append(r, r[i])
	}
	return r
}

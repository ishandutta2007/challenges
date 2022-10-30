/*

Create a function that returns an array of the given string but offset by spaces. Here are some more precise instructions:

    Keep adding spaces on the left until you have the same number of spaces as the word length.
    Then keep removing spaces until you reach the original word.

Below are some helpful examples!

Examples

wiggleString("hello") ➞ [
  "hello",
  " hello",
  "  hello",
  "   hello",
  "    hello",
  "     hello"
  "    hello",
  "   hello",
  "  hello",
  " hello",
  "hello"
]

wiggleString("EDABIT") ➞ [
  "EDABIT",
  " EDABIT",
  "  EDABIT",
  "   EDABIT",
  "    EDABIT",
  "     EDABIT",
  "      EDABIT",
  "     EDABIT",
  "    EDABIT",
  "   EDABIT",
  "  EDABIT",
  " EDABIT",
  "EDABIT"
]

wiggleString("Wiggle Time") ➞ [
  "Wiggle Time",
  " Wiggle Time",
  "  Wiggle Time",
  "   Wiggle Time",
  "    Wiggle Time",
  "     Wiggle Time",
  "      Wiggle Time",
  "       Wiggle Time",
  "        Wiggle Time",
  "         Wiggle Time",
  "          Wiggle Time",
  "           Wiggle Time",
  "          Wiggle Time",
  "         Wiggle Time",
  "        Wiggle Time",
  "       Wiggle Time",
  "      Wiggle Time",
  "     Wiggle Time",
  "    Wiggle Time",
  "   Wiggle Time",
  "  Wiggle Time",
  " Wiggle Time",
  "Wiggle Time"
]

*/

package main

import (
	"fmt"
	"strings"
	"unicode/utf8"
)

func main() {
	test("hello")
	test("EDABIT")
	test("Wiggle Time")
	test("the dog")
	test("wiggle wiggle wiggle")
	test("Hello World!")
	test("Edabit is fun!")
	test("123456789")
	test("qwertyuiop")
	test("python javascript")
}

func test(s string) {
	p := wiggle(s)
	for i := range p {
		fmt.Printf("%q\n", p[i])
	}
}

func wiggle(s string) []string {
	var p []string
	n := utf8.RuneCountInString(s)
	for i := 0; i <= n; i++ {
		p = append(p, strings.Repeat(" ", i)+s)
	}
	for i := n - 1; i >= 0; i-- {
		p = append(p, strings.Repeat(" ", i)+s)
	}
	return p
}

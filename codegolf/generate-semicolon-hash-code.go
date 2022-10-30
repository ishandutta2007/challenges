/*

Related to: Make a ;# interpreter

In the above linked challenge the task was to create an interpreter for the esoteric language ;#.

The ;# language
The language has exactly two commands: ; and # (all other characters are ignored by the interpreter):

;: Increment the accumulator

#: Modulo the accumulator by 127, print the corresponding ASCII character and reset the accumulator to 0.

Challenge
Because I am lazy but still want to test some more testcases, I need a program or function which converts plain text to ;# code.

Input
The input is a string, taken either as argument or through stdin. It will only contain printable ASCII characters and newlines.

Output
The output is the generated ;# program by returning, or printing to stdout. As long as the program is valid, it may contain excess characters other than # and ; as all other characters are ignored.

Examples
Input: Hello, World!
Output: ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#

Input: ABC
Output: ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#

Input: ;#
Output: ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;#

*/

package main

import (
	"bytes"
	"fmt"
	"io"
)

func main() {
	test("Hello, World!")
	test("ABC")
	test(";#")
}

func test(s string) {
	b := new(bytes.Buffer)
	interpret(b, gen(s))
	p := b.String()
	fmt.Println(p)
	assert(p == s)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(s string) string {
	w := new(bytes.Buffer)
	for i := 0; i < len(s); i++ {
		for j := 0; j < int(s[i]); j++ {
			w.WriteByte(';')
		}
		w.WriteByte('#')
	}
	return w.String()
}

func interpret(w io.Writer, s string) {
	ac := 0
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case ';':
			ac++
		case '#':
			fmt.Fprintf(w, "%c", ac%127)
			ac = 0
		}
	}
}

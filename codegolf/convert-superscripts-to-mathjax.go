/*

CGCC hasn't always had MathJax. Back in the dark ages, it would have been necessary to write x2 as x² (the horror!). In this challenge, you will be given some math which may include superscripts, and you should convert it to MathJax.

Input:

Input will consist of one or more letters a to z, some with superscripts. Answers may choose to handle only upper or lower case, or both.

Examples of inputs would be x, x², xy², x²y², or x²yz. There will never be duplicates of a letter (so xx or x²zx won't be given), but you cannot assume the superscripts or letters are in any particular order.
The first character in the input will never be a superscript.

Superscripts consist of the characters ¹, ², ³, ⁴, ⁵, ⁶, ⁷, ⁸, ⁹, and ⁰. These can be joined into multi-digit superscripts, like x²¹ (x21).
You can assume ⁰ or ¹ are never given as superscripts, and there will not be leading ⁰s.

Output:

Output should consist of a MathJax representation of the input. This must start and finish with \$.

Characters without superscripts can be written as themselves; xyz would simply become \$xyz\$. Characters with superscripts should be followed by ^, then the superscript written with normal digits and wrapped in {}.
For example, x²¹z⁴⁸⁸ would become \$x^{21}z^{488}\$. Optionally, single digit superscripts can be written without the {}. For example, x² could be either \$x^{2}\$ or \$x^2\$.

Test cases:

x           \$x\$
xyz         \$xyz\$
x²          \$x^{2}\$ OR \$x^2\$
x²¹         \$x^{21}\$
x²yz²       \$x^{2}yz^{2}\$ OR \$x^2yz^2\$
xy¹¹z       \$xy^{11}z\$
x⁴          \$x^{4}\$ OR \$x^4\$
x⁶⁰         \$x^{60}\$

Other:

This is code-golf, shortest answer (in bytes) per language wins!

*/

package main

import (
	"bytes"
	"fmt"
	"unicode"
)

func main() {
	assert(mathjax("x") == `\$x\$`)
	assert(mathjax("xyz") == `\$xyz\$`)
	assert(mathjax("x²") == `\$x^{2}\$`)
	assert(mathjax("x²¹") == `\$x^{21}\$`)
	assert(mathjax("x²yz²") == `\$x^{2}yz^{2}\$`)
	assert(mathjax("xy¹¹z") == `\$xy^{11}z\$`)
	assert(mathjax("x⁴") == `\$x^{4}\$`)
	assert(mathjax("x⁶⁰") == `\$x^{60}\$`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mathjax(s string) string {
	w := new(bytes.Buffer)
	p := rune(0)
	fmt.Fprintf(w, "\\$")
	for _, r := range s {
		r = conv(r)
		if unicode.IsDigit(r) && !unicode.IsDigit(p) {
			fmt.Fprintf(w, "^{")
		} else if !unicode.IsDigit(r) && unicode.IsDigit(p) {
			fmt.Fprintf(w, "}")
		}
		fmt.Fprintf(w, "%c", r)
		p = r
	}
	if unicode.IsDigit(p) {
		fmt.Fprintf(w, "}")
	}
	fmt.Fprintf(w, "\\$")
	return w.String()
}

func conv(r rune) rune {
	switch r {
	case '¹':
		return '1'
	case '²':
		return '2'
	case '³':
		return '3'
	case '⁴':
		return '4'
	case '⁵':
		return '5'
	case '⁶':
		return '6'
	case '⁷':
		return '7'
	case '⁸':
		return '8'
	case '⁹':
		return '9'
	case '⁰':
		return '0'
	}
	return r
}

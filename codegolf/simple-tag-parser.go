/*

This is a model of a forgiving HTML parser. Instead of parsing HTML and extracting attributes, in this code golf, the tag parser will be simple.

Write a function that parses a tag structure and returns its parenthized form. An opening tag consists of one lowercase letter, and a closing tag consists of one uppercase letter.
For example, aAbaAB parses into (a)(b(a)), or in HTML, <a></a><b><a></a></b>. Of course, tags can be in juxtaposition and nest.

"Prematurely" closed tags must be handled. For example, in abcA, the A closes the outermost a, so it parses into (a(b(c))).

Extra closing tags are simply ignored: aAB parses into (a).

Overlapping tags are NOT handled. For example, abAB parses into (a(b)), not (a(b))(b), by the previous rule of extra closing tags (abAB -> abA ((a(b))) + B (extra)).

Assuming no whitespaces and other illegal characters in the input.

You are not allowed to use any library.

Here is a reference implementation and a list of test cases:

#!/usr/bin/python

def pars(inpu):
  outp = ""
  stac = []
  i = 0
  for x in inpu:
    lowr = x.lower()
    if x == lowr:
      stac.append(x)
      outp += "(" + x
      i = i + 1
    else:
      while len(stac) > 1 and stac[len(stac) - 1] != lowr:
        outp += ")"
        stac.pop()
        i = i - 1
      if len(stac) > 0:
        outp += ")"
        stac.pop()
        i = i - 1
  outp += ")" * i
  return outp

tests = [
  ("aAaAbB", "(a)(a)(b)"),
  ("abBcdDCA", "(a(b)(c(d)))"),
  ("bisSsIB", "(b(i(s)(s)))"),
  ("aAabc", "(a)(a(b(c)))"),
  ("abcdDA", "(a(b(c(d))))"),
  ("abcAaA", "(a(b(c)))(a)"),
  ("acAC", "(a(c))"),
  ("ABCDEFG", ""),
  ("AbcBCabA", "(b(c))(a(b))")
]

for case, expe in tests:
  actu = pars(case)
  print "%s: C: [%s] E: [%s] A: [%s]" % (["FAIL", "PASS"][expe == actu], case, expe, actu)
Shortest code wins.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
	"unicode"
)

func main() {
	assert(tag("aAaAbB") == "(a)(a)(b)")
	assert(tag("abBcdDCA") == "(a(b)(c(d)))")
	assert(tag("bisSsIB") == "(b(i(s)(s)))")
	assert(tag("aAabc") == "(a)(a(b(c)))")
	assert(tag("abcdDA") == "(a(b(c(d))))")
	assert(tag("abcAaA") == "(a(b(c)))(a)")
	assert(tag("acAC") == "(a(c))")
	assert(tag("ABCDEFG") == "")
	assert(tag("AbcBCabA") == "(b(c))(a(b))")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tag(s string) string {
	w := new(bytes.Buffer)
	p := []rune{}
	i := 0
	for _, r := range s {
		l := unicode.ToLower(r)
		if r == l {
			p, i = append(p, r), i+1
			fmt.Fprintf(w, "(%c", r)
		} else {
			for len(p) > 1 && p[len(p)-1] != l {
				p, i = p[:len(p)-1], i-1
				fmt.Fprintf(w, ")")
			}
			if len(p) > 0 {
				p, i = p[:len(p)-1], i-1
				fmt.Fprintf(w, ")")
			}
		}
	}
	fmt.Fprintf(w, "%v", strings.Repeat(")", i))
	return w.String()
}

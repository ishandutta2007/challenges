/*

Background

In C, there is a function to help parse command-line arguments: getopt.

Getopt takes the argument count (argc), the argument list (argv), and a string representing the options the program should take (optstring).

The option string (optstring) is a series of option characters each followed by one colon (for an option requiring an argument), two colons (for an option with an optional argument), or zero colons (for an option without an argument).

For example: one might use the following option string for their company's new widget.

"v::x:hy:S:G::dns:f::"
But that looks horrible! The options are all mixed together! This option string would look much better if it were sorted:

"f::G::v::S:s:x:y:dhn"

Specifications

The input will be a string matching the regular expression ([A-Za-z]:{0,2})+

You should take input as a string or list of characters.

You should output the string sorted by the method detailed below.

You do not need to handle empty input.

You do not need to handle input with repeated options of the same type ("aa" is not valid, but "aa:a::" is valid).

Sorting Method
In the sorted option string:

The characters followed by two colons come first, sorted alphabetically, with uppercase letters before their respective lowercase letters (i.e. "aBb", not "Bab").

Then are the characters with one colon, sorted alphabetically, with uppercase letters before their respective lowercase letters.

Last are the characters with no colon, sorted alphabetically, with uppercase letters before their respective lowercase letters.

Rules

Standard Loopholes are forbidden.
Scoring
This is code-golf, so shortest answer in bytes in each language wins.

Examples
# "input" => "output"
"v::x:hy:S:G::dns:f::" => "f::G::v::S:s:x:y:dhn"
"aa:a::" => "a::a:a"
"B:" => "B:"
"Confusio:n::" => "n::o:Cfinosu"
"Confusio:n:" => "n:o:Cfinosu"
"m:qW:X:xc:vViI" => "c:m:W:X:IiqVvx"
"V:omo:V" => "o:V:moV"
"agg:ra:va::ting::" => "a::g::a:g:aginrtv"
"input" => "inptu"
Long test case (312 characters)

Invaid Inputs (you don't have to handle):

"gg" (duplicated option)
"" (empty string)
":w:" (first colon isn't after a character)
"x:y:0:fhn" ('0' is not alphabetic)
"A:::" (3 colons is invalid)

*/

package main

import (
	"bytes"
	"fmt"
	"sort"
	"strings"
)

func main() {
	assert(sortopt("v::x:hy:S:G::dns:f::") == "f::G::v::S:s:x:y:dhn")
	assert(sortopt("aa:a::") == "a::a:a")
	assert(sortopt("B:") == "B:")
	assert(sortopt("Confusio:n::") == "n::o:Cfinosu")
	assert(sortopt("Confusio:n:") == "n:o:Cfinosu")
	assert(sortopt("m:qW:X:xc:vViI") == "c:m:W:X:IiqVvx")
	assert(sortopt("V:omo:V") == "o:V:moV")
	assert(sortopt("agg:ra:va::ting::") == "a::g::a:g:aginrtv")
	assert(sortopt("gg") == "invalid option")
	assert(sortopt("") == "invalid option")
	assert(sortopt(":w:") == "invalid option")
	assert(sortopt("x:y:0:fhn") == "invalid option")
	assert(sortopt("A:::") == "invalid option")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type char struct {
	code byte
	args int
}

func sortopt(s string) string {
	p := []char{}
	n := len(s)
	for i := 0; i < n; i++ {
		if !isalpha(s[i]) {
			return "invalid option"
		}

		c := char{s[i], 0}
		for ; i+1 < n && s[i+1] == ':'; i++ {
			c.args++
		}
		if c.args > 2 {
			return "invalid option"
		}
		p = append(p, c)
	}

	sort.Slice(p, func(i, j int) bool {
		x := p[i]
		y := p[j]
		if x.args > y.args {
			return true
		}
		if x.args < y.args {
			return false
		}

		u := tolower(x.code)
		v := tolower(y.code)
		if u < v {
			return true
		}
		if u > v {
			return false
		}
		return x.code < y.code
	})

	w := new(bytes.Buffer)
	for i, c := range p {
		if i > 0 && p[i] == p[i-1] {
			return "invalid option"
		}
		fmt.Fprintf(w, "%c%s", c.code, strings.Repeat(":", c.args))
	}

	r := w.String()
	if len(r) == 0 {
		return "invalid option"
	}
	return r
}

func isalpha(c byte) bool {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
}

func tolower(c byte) byte {
	if 'A' <= c && c <= 'Z' {
		c = (c - 'A') + 'a'
	}
	return c
}

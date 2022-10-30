/*

Recreate C#'s String.Format where the first argument is the string template and all subsequent arguments are the values for the corresponding placeholders in the template.

Examples

String.Format("{0}{1}{2}{1}{0}",  "k",  "a", "y") ➞ "kayak"

String.Format("Palindromes are {0}", "fun") ➞ "Palindromes are fun"

String.Format("Hello {0}.\nGeneral {1}",  "there",  "Kenobi") ➞ "Hello there.\nGeneral Kenobi"

Notes

N/A

*/

package main

import (
	"bytes"
	"fmt"
	"regexp"
	"strconv"
)

func main() {
	assert(format("Hello {0}.\nGeneral {1}", "there", "Kenobi") == "Hello there.\nGeneral Kenobi")
	assert(format("{0}{1}{2}{3}{2}{1}{0}", "r", "a", "c", "e") == "racecar")
	assert(format("{0}{1}{2}{1}{0}", "k", "a", "y") == "kayak")
	assert(format("Palindromes are {0}", "fun") == "Palindromes are fun")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func format(s string, a ...interface{}) string {
	re := regexp.MustCompile("{[0-9]+}")
	in := re.FindAllStringIndex(s, -1)

	w := new(bytes.Buffer)
	n := 0
	for i := 0; i < len(s); i++ {
		if n >= len(in) || i != in[n][0] {
			w.WriteByte(s[i])
			continue
		}

		j := in[n]
		k, err := strconv.Atoi(s[j[0]+1 : j[1]-1])
		if err != nil || k < 0 || k >= len(a) {
			w.WriteString(s[j[0]:j[1]])
		} else {
			fmt.Fprint(w, a[k])
		}
		i, n = j[1]-1, n+1
	}
	return w.String()
}

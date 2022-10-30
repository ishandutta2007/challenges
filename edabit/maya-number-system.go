/*

Maya numeral system was vigesimal (base 20) and positional: units, tens, hundreds (and so on) were read as descendant progressive powers of 20, instead of 10 like we do with our decimal system. Some examples:

- 39 => (1 x 20¹) + (19 x 20º)
- 815 => (2 x 20²) + (0 x 20¹) + (15 x 20º)
- 16125 => (2 x 20³) + (0 x 20²) + (6 x 20¹) + (5 x 20º)

Every digit (as to say the number to be multiplied for the power of 20) was symbolized with a combination of pebbles (dots), woodsticks (lines) and shells (used for the number 0) following a base5 system. See the table below:

Mayan Numbers

You must implement a function that, given a non-negative integer, returns a list of strings, with each string representing the symbolized single digit.

Symbols to use are "@" for shells, "-" for lines and "o" for dots. Dots have to be placed before the lines.

Examples

# Be careful, spaces between symbols are placed only for better readability!
# Don't use spaces in returned strings.

maya_number(39) ➞ ["o", "o o o o - - -"]

maya_number(815) ➞ ["o o", "@", "- - -"]

maya_number(16125) ➞ ["o o", "@", "o -", "-"]

Notes

    Check the Resources tab for more info on Maya numerals (and Maya arithmetic).
    All given integers are valid, no exceptions to handle.

*/

package main

import (
	"fmt"
	"reflect"
	"strings"
)

func main() {
	test(39, []string{"o", "oooo---"})
	test(815, []string{"oo", "@", "---"})
	test(16125, []string{"oo", "@", "o-", "-"})
	test(0, []string{"@"})
	test(1985, []string{"oooo", "oooo---", "-"})
	test(86420, []string{"--", "o---", "o", "@"})
	test(13579, []string{"o", "ooo--", "ooo---", "oooo---"})
	test(666, []string{"o", "ooo--", "o-"})
}

func test(n uint, r []string) {
	p := maya(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maya(n uint) []string {
	return beads(base20(n))
}

func base20(n uint) []uint {
	var d []uint
	for {
		d = append(d, n%20)
		if n /= 20; n == 0 {
			break
		}
	}
	return d
}

func beads(p []uint) []string {
	r := make([]string, len(p))
	for i, j := len(p)-1, 0; i >= 0; i, j = i-1, j+1 {
		u := int(p[i] / 5)
		v := int(p[i] % 5)
		if u == 0 && v == 0 {
			r[j] = "@"
		} else {
			r[j] = strings.Repeat("o", v) + strings.Repeat("-", u)
		}
	}
	return r
}

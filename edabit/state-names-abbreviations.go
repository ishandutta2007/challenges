/*

Create a function that filters out an array of state names into two categories based on the second parameter.

    Abbreviations abb
    Full names full

Examples

filterStateNames(["Arizona", "CA", "NY", "Nevada"], "abb")
➞ ["CA", "NY"]

filterStateNames(["Arizona", "CA", "NY", "Nevada"], "full")
➞ ["Arizona", "Nevada"]

filterStateNames(["MT", "NJ", "TX", "ID", "IL"], "abb")
➞ ["MT", "NJ", "TX", "ID", "IL"]

filterStateNames(["MT", "NJ", "TX", "ID", "IL"], "full")
➞ []

Notes

State abbreviations will always be in uppercase.

*/

package main

import (
	"reflect"
	"unicode"
)

func main() {
	test([]string{"Arizona", "CA", "NY", "Nevada"}, "abb", []string{"CA", "NY"})
	test([]string{"Arizona", "CA", "NY", "Nevada"}, "full", []string{"Arizona", "Nevada"})
	test([]string{"MT", "NJ", "TX", "ID", "IL"}, "abb", []string{"MT", "NJ", "TX", "ID", "IL"})
	test([]string{"MT", "NJ", "TX", "ID", "IL"}, "full", []string{})
	test([]string{"Montana", "FL"}, "abb", []string{"FL"})
	test([]string{"Montana", "FL"}, "full", []string{"Montana"})
}

func test(s []string, ab string, r []string) {
	p := states(s, ab)
	assert(len(p) == len(r))
	if len(p) != 0 {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func states(s []string, ab string) []string {
	var f func(string) bool
	switch ab {
	case "abb":
		f = func(s string) bool {
			if len(s) != 2 {
				return false
			}
			return unicode.IsUpper(rune(s[0])) && unicode.IsUpper(rune(s[1]))
		}
	case "full":
		f = func(s string) bool { return len(s) > 2 }
	default:
		f = func(string) bool { return true }
	}

	var p []string
	for _, s := range s {
		if f(s) {
			p = append(p, s)
		}
	}
	return p
}

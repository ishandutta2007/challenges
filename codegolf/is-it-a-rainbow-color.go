/*

Challenge:

The challenge is to determine whether or not a color, given it's name, is one of the colors in the rainbow.

When supplied with a color, your program should output a truthy value if it is a color in the rainbow, and a falsy one otherwise.

Rules:

The possible input options are exhaustive, and defined in the test cases. You can assume that you will not receive any other input than the ones defined
Character casing for inputs can be one of: UPPER, lower, or Title Case, but must be consistent
Standard loopholes not allowed

Test Cases:

Truthy:

red
orange
yellow
green
blue
indigo
violet

Falsy:

purple
brown
pink
cyan
maroon

*/

package main

import "strings"

func main() {
	assert(rainbow("red") == true)
	assert(rainbow("orange") == true)
	assert(rainbow("yellow") == true)
	assert(rainbow("green") == true)
	assert(rainbow("blue") == true)
	assert(rainbow("indigo") == true)
	assert(rainbow("violet") == true)

	assert(rainbow("purple") == false)
	assert(rainbow("brown") == false)
	assert(rainbow("pink") == false)
	assert(rainbow("cyan") == false)
	assert(rainbow("maroon") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rainbow(s string) bool {
	tab := map[string]bool{
		"red":    true,
		"orange": true,
		"yellow": true,
		"green":  true,
		"blue":   true,
		"indigo": true,
		"violet": true,
	}
	return tab[strings.ToLower(s)]
}

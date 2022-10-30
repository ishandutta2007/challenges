/*

Fruit salads are served best when the fruits are sliced and diced into small chunks!

For this challenge, slice each fruit in half and sort the chunks alphabetically. This recipe tastes best when the chunks are joined together to make a string.

Worked Example

fruitSalad(["apple", "pear", "grapes"]) ➞ "apargrapepesple"

// Chunks: ["ap", "ple", "pe", "ar", "gra", "pes"]
// Sorted chunks: ["ap", "ar", "gra", "pe", "pes", "ple"]
// Final string: "apargrapepesple"

Examples

fruitSalad(["apple", "pear", "grapes"]) ➞ "apargrapepesple"

fruitSalad(["raspberries", "mango"]) ➞ "erriesmangoraspb"

fruitSalad(["banana"]) ➞ "anaban"

Notes

    If a fruit has an odd number of letters, make the right side larger than the left.
    For example: "apple" will be sliced into "ap" and "ple".
    All fruits will be given in lowercase.

*/

package main

import (
	"sort"
	"strings"
)

func main() {
	assert(fruitsalad([]string{"apple", "pear", "grapes"}) == "apargrapepesple")
	assert(fruitsalad([]string{"banana", "kiwi", "strawberry", "blueberries"}) == "anabanberryblueberrieskistrawwi")
	assert(fruitsalad([]string{"raspberries", "mango"}) == "erriesmangoraspb")
	assert(fruitsalad([]string{"banana"}) == "anaban")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fruitsalad(s []string) string {
	var p []string
	for i := range s {
		r := []rune(s[i])
		n := len(r)
		p = append(p, string(r[:n/2]))
		p = append(p, string(r[n/2:]))
	}
	sort.Strings(p)
	return strings.Join(p, "")
}

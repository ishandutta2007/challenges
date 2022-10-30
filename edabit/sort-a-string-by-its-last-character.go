/*

Create a function that takes a string of words and return a string sorted alphabetically by the last character of each word.

Examples

sortByLast("herb camera dynamic") ➞ "camera herb dynamic"

sortByLast("stab traction artist approach") ➞ "stab approach traction artist"

sortByLast("sample partner autonomy swallow trend") ➞ "trend sample partner swallow autonomy"

Notes

    Tests consist of lowercase alphabetic characters (a-z) and spaces.
    If two words have the same last character, sort by the order they originally appeared.

*/

package main

import (
	"sort"
	"strings"
	"unicode/utf8"
)

func main() {
	assert(sortlast("herb camera dynamic") == "camera herb dynamic")
	assert(sortlast("stab traction artist approach") == "stab approach traction artist")
	assert(sortlast("sample partner autonomy swallow trend") == "trend sample partner swallow autonomy")
	assert(sortlast("dividend platform pupil conclusion silence breakfast") == "dividend silence pupil platform conclusion breakfast")
	assert(sortlast("harm") == "harm")
	assert(sortlast("card warrant opinion medium illustrate") == "card illustrate medium opinion warrant")
	assert(sortlast("cause fine virtue") == "cause fine virtue")
	assert(sortlast("introduce fashionable cause sacrifice reality") == "introduce fashionable cause sacrifice reality")
	assert(sortlast("brick moral institution loud talk resign worth") == "loud worth brick talk moral institution resign")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sortlast(s string) string {
	t := strings.Split(s, " ")
	sort.SliceStable(t, func(i, j int) bool {
		p, _ := utf8.DecodeLastRuneInString(t[i])
		q, _ := utf8.DecodeLastRuneInString(t[j])
		return p < q
	})
	return strings.Join(t, " ")
}

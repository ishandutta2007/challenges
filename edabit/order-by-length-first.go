/*

Graded lexicographic order (grlex order for short) is a way of ordering words that:

    First orders words by length.
    Then orders words of the same size by their dictionary order.

For example, in grlex order:

    "tray" < "trapped" since "tray" has length 4 while "trapped" has length 7.
    "trap" < "tray" since both have length 4, but "trap" comes before "tray" in the dictionary.

Given an array of words, return that array in grlex order.
Examples

makeGrlex(["small", "big"]) ➞ ["big", "small"]

makeGrlex(["cat", "ran", "for", "the", "rat"]) ➞ ["cat", "for", "ran", "rat", "the"]

makeGrlex(["this", "is", "a", "small", "test"]) ➞ ["a", "is", "test", "this", "small"]

Notes

N/A

*/

package main

import (
	"reflect"
	"sort"
)

func main() {
	test([]string{"small", "big"}, []string{"big", "small"})
	test([]string{"big", "cat", "ran", "for", "the", "fat", "rat"}, []string{"big", "cat", "fat", "for", "ran", "rat", "the"})
	test([]string{"this", "is", "a", "small", "test"}, []string{"a", "is", "test", "this", "small"})
	test([]string{"let", "us", "try", "some", "long", "test", "to", "see", "if", "this", "works", "as", "it", "should"}, []string{"as", "if", "it", "to", "us", "let", "see", "try", "long", "some", "test", "this", "works", "should"})
}

func test(s, r []string) {
	assert(reflect.DeepEqual(order(s), r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func order(s []string) []string {
	r := append([]string{}, s...)
	sort.Slice(r, func(i, j int) bool {
		n := len(r[i])
		m := len(r[j])
		if n < m {
			return true
		}
		if n > m {
			return false
		}
		return r[i] < r[j]
	})
	return r
}

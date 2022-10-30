/*

Create a function that takes an initial word and extracts any words that start with the same letters as the initial word.
Examples

dictionary("bu", ["button", "breakfast", "border"]) ➞ ["button"]

dictionary("tri", ["triplet", "tries", "trip", "piano", "tree"]) ➞ ["triplet", "tries", trip"]

dictionary("beau", ["pastry", "delicious", "name", "boring"]) ➞ []

Notes

    If none of the words match, return an empty array.
    Keep the filtered array in the same relative order as the original array of words.

*/

package main

import (
	"fmt"
	"reflect"
	"strings"
)

func main() {
	test("bu", []string{"button", "breakfast", "border"}, []string{"button"})
	test("beau", []string{"pastry", "delicious", "name", "boring"}, []string{})
	test("there", []string{"there", "here", "everywhere"}, []string{"there"})
	test("sno", []string{"snow", "paper", "ghost"}, []string{"snow"})
	test("ma", []string{"marriage", "married", "many", "delight"}, []string{"marriage", "married", "many"})
	test("no", []string{"inferno", "notion", "nominate", "note", "fairy"}, []string{"notion", "nominate", "note"})
	test("cre", []string{"creating", "creature", "creed", "increasing"}, []string{"creating", "creature", "creed"})
}

func test(s string, t, r []string) {
	p := dictionary(s, t)
	fmt.Println(p)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func dictionary(s string, t []string) []string {
	var r []string
	for _, p := range t {
		if strings.HasPrefix(p, s) {
			r = append(r, p)
		}
	}
	return r
}

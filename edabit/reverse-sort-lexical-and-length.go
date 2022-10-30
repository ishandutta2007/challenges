/*

Write a function that sorts the words in a given string lexicographically (lexical sort) and by length in reverse order.

Examples

reverseSort("You've rocked the pragmatic world in the making!")
 ➞ "pragmatic making! You've rocked world the the in"

reverseSort("Tesh makes my world worth enjoying and living for.")
 ➞ "enjoying living worth world makes Tesh for. and my"

reverseSort(reverseSort("Shaken by the bloody truth and crazy lies.")
 ➞ "Shaken bloody truth lies. crazy the and by"

reverseSort("Java streams and collections are fun to program with!")
 ➞ "collections streams program with! Java fun are and to"

Notes

    Special characters, punctuations and symbols are part of the word that directly preceeds it.
    The space character separates each word in the given string.
    Case insensitive sorting is required.

*/

package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	itab := []string{
		"You've rocked the pragmatic world in the making!",
		"Tesh makes my world worth enjoying and living for.",
		"Shaken by the bloody truth and crazy lies.",
		"Java streams and collections are fun to program with!",
		"Tesha is a woman of true substance and a beauty.",
		"Lexical sort is similar to alphanumeric sorting.",
		"To do or not to do, is all up to you.",
		"Javascript array methods are fun to program with!",
		"Programming in JavaScript is a lot of fun.",
		"Truly, a heart that beats for no one but for Tesh.",
	}
	otab := []string{
		"pragmatic making! You've rocked world the the in",
		"enjoying living worth world makes Tesh for. and my",
		"Shaken bloody truth lies. crazy the and by",
		"collections streams program with! Java fun are and to",
		"substance beauty. woman Tesha true and of is a a",
		"alphanumeric sorting. similar Lexical sort to is",
		"you. not do, all up To to to or is do",
		"Javascript program methods with! array fun are to",
		"Programming JavaScript fun. lot of is in a",
		"Truly, Tesh. heart beats that one for for but no a",
	}
	for i := range itab {
		p := revsort(itab[i])
		fmt.Println(itab[i])
		fmt.Println(p)
		fmt.Println(otab[i])
		fmt.Println()
		assert(p == otab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func revsort(s string) string {
	t := strings.Split(s, " ")
	sort.Slice(t, func(i, j int) bool {
		switch n, m := len(t[i]), len(t[j]); {
		case n > m:
			return true
		case n == m:
			return strings.ToLower(t[i]) > strings.ToLower(t[j])
		}
		return false
	})
	return strings.Join(t, " ")
}

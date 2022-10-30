/*

Create a function that takes a string and returns a string ordered by the length of the words.
From shortest to longest word. If there are words with the same amount of letters, order them alphabetically.

Examples

sortByLength("Hello my friend") ➞ "my Hello friend"

sortByLength("Have a wonderful day") ➞ "a day Have wonderful"

sortByLenght("My son loves pineapples") ➞ "My son loves pineapples"

Notes

Punctuation (periods, commas, etc) belongs to the word in front of it.

*/

package main

import (
	"sort"
	"strings"
)

func main() {
	assert(lensort("Hello my friend") == "my Hello friend")
	assert(lensort("Three can keep a secret, if two of them are dead") == "a if of are can two dead keep them Three secret,")
	assert(lensort("To be or not to be, that is the question.") == "be is or To to be, not the that question.")
	assert(lensort("I have a dream") == "a I have dream")
	assert(lensort("This is the end") == "is end the This")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lensort(s string) string {
	t := strings.Split(s, " ")
	sort.Slice(t, func(i, j int) bool {
		if len(t[i]) < len(t[j]) {
			return true
		}
		if len(t[i]) > len(t[j]) {
			return false
		}
		a := strings.ToLower(t[i])
		b := strings.ToLower(t[j])
		return (a == b && t[i] < t[j]) || a < b
	})
	return strings.Join(t, " ")
}

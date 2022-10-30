/*

A haiku is a poem with three lines, with a 5/7/5 syllable count, respectively.

A haiku-w is poem with three lines, with a 5/7/5 word count, respectively.

Challenge
Write a program that will return true if the input is a haiku-w, and false if not.

A valid haiku-w input must consist of 3 lines, separated by a newline.

Line 1 must consist of 5 words, each word separated by a space.
Line 2 must consist of 7 words, each word separated by a space.
Line 3 must consist of 5 words, each word separated by a space.
Examples
The man in the suit
is the same man from the store.
He is a cool guy.
Result: True

Whitecaps on the bay:
A broken signboard banging
In the April wind.
Result: False

Rules
This is code-golf, so the shortest answer in bytes wins.
Standard code-golf loopholes apply. Cheating is prohibited.
Other boolean return values, such as 1 and 0, are acceptable.
A length-3 list of strings as an input is also acceptable.
Valid haiku-w inputs should not have leading or trailing spaces, or multiple spaces separating words.

*/

package main

import "strings"

func main() {
	assert(haikuw([]string{
		"The man in the suit",
		"is the same man from the store.",
		"He is a cool guy.",
	}) == true)

	assert(haikuw([]string{
		"Whitecaps on the bay:",
		"A broken signboard banging",
		"In the April wind.",
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func haikuw(s []string) bool {
	if len(s) != 3 {
		return false
	}

	c := []int{5, 7, 5}
	for i := range s {
		t := strings.Split(s[i], " ")
		if len(t) != c[i] {
			return false
		}
	}
	return true
}

/*

You're given a string of words. You need to find the word "Nemo", and return a string like this: "I found Nemo at [the order of the word you find nemo]!".

If you can't find Nemo, return "I can't find Nemo :(".
Examples

findNemo("I am finding Nemo !") ➞ "I found Nemo at 4!"

findNemo("Nemo is me") ➞ "I found Nemo at 1!"

findNemo("I Nemo am") ➞ "I found Nemo at 2!"

Notes

    ! , ? . are always separated from the last word.
    Nemo will always look like Nemo, and not NeMo or other capital variations.
    Nemo's, or anything that says Nemo with something behind it, doesn't count as Finding Nemo.
    If there are multiple Nemo's in the sentence, only return for the first one.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(findnemo("I am Ne mo Nemo !") == "I found Nemo at 5!")
	assert(findnemo("N e m o is NEMO NeMo Nemo !") == "I found Nemo at 8!")
	assert(findnemo("I am Nemo's dad Nemo senior .") == "I found Nemo at 5!")
	assert(findnemo("Oh, hello !") == "I can't find Nemo :(")
	assert(findnemo("Is it Nemos, Nemona, Nemoor or Garfield?") == "I can't find Nemo :(")
	assert(findnemo("Nemo is a clown fish, he has white and orange stripes. Nemo , come back!") == "I found Nemo at 1!")
}

func findnemo(s string) string {
	toks := strings.Split(s, " ")
	for i, tok := range toks {
		if tok == "Nemo" {
			return fmt.Sprintf("I found Nemo at %d!", i+1)
		}
	}
	return "I can't find Nemo :("
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

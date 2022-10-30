/*

Create a function that replaces "the" in the sentence with "an" or "a". Remember that if the next word begins with a vowel, use "an". In the case of a consonant, use "a".

Examples

replaceThe("the dog and the envelope") ➞ "a dog and an envelope"

replaceThe("the boy ran at the wall") ➞ "a boy ran at a wall"

replaceThe("the egg, the spoon and the espionage") ➞ "an egg, a spoon and an espionage"

Notes

    Sentences will always be in lowercase.
    The last word of the sentence will never be "the".
    This won't cover edge cases such as "an hour" or "a unique thing" (since they sound differently to the rule).

*/

package main

import (
	"strings"
	"unicode"
)

func main() {
	assert(replace("the dog and the envelope") == "a dog and an envelope")
	assert(replace("the boy ran at the wall") == "a boy ran at a wall")
	assert(replace("the egg, the spoon and the espionage") == "an egg, a spoon and an espionage")
	assert(replace("where is the spoon") == "where is a spoon")
	assert(replace("the quick brown fox jumps over the lazy dog") == "a quick brown fox jumps over a lazy dog")
	assert(replace("this edabit thing is quite neat") == "this edabit thing is quite neat")
	assert(replace("enter the correct password to access the epic program") == "enter a correct password to access an epic program")
	assert(replace("the man blew the final candle out and all was dark") == "a man blew a final candle out and all was dark")
	assert(replace("the ant ate the egg salad which the eel had been intending to eat over the weekend") == "an ant ate an egg salad which an eel had been intending to eat over a weekend")
	assert(replace("this the random english sentence which you have to pass") == "this a random english sentence which you have to pass")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func replace(s string) string {
	p := ""
	t := strings.Split(s, " ")
	for i := 0; i < len(t); i++ {
		if strings.ToLower(t[i]) == "the" && i+1 < len(t) {
			p += "a"
			if isvowel(t[i+1][0]) {
				p += "n"
			}
		} else {
			p += t[i]
		}
		if i+1 < len(t) {
			p += " "
		}
	}
	return p
}

func isvowel(c byte) bool {
	return strings.IndexRune("aeiou", unicode.ToLower(rune(c))) >= 0
}

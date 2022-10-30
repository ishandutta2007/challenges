/*

Create a function that takes a string (without spaces) and a word array, cleaves the string into words based on the array, and returns the correctly spaced version of the string (a sentence). If a section of the string is encountered that can't be found on the word array, return "Cleaving stalled: Word not found".
Examples

const words = ["about", "be", "hell", "if", "is", "it", "me", "other", "outer", "people", "the", "to", "up", "where"]

cleave("ifitistobeitisuptome", words) ➞ "if it is to be it is up to me"

cleave("hellisotherpeople", words) ➞ "hell is other people"

cleave("hellisotterpeople", words) ➞ "Cleaving stalled: Word not found"

Notes

Words in the words array can appear more than once in the string. The words array is a reference guide, kind of like a dictionary that lists which words are allowed.

*/

package main

func main() {
	w1 := []string{"about", "be", "hell", "if", "is", "it", "me", "other", "outer", "people", "the", "to", "up", "where"}
	w2 := []string{"a", "after", "all", "an", "and", "are", "as", "by", "continued", "deadlines", "doubly", "fish", "for", "go", "happen", "happened", "i", "illusion", "is", "long", "love", "lunchtime", "make", "moment", "noise", "nothing", "of", "or", "people", "problem", "second", "so", "summarize", "summary", "thanks", "the", "then", "they", "time", "to", "whooshing"}

	assert(cleaver("ifitistobeitisuptome", w1) == "if it is to be it is up to me")
	assert(cleaver("hellisotherpeople", w1) == "hell is other people")
	assert(cleaver("hellisotterpeople", w1) == "Cleaving stalled: Word not found")

	assert(cleaver("solongandthanksforallthefish", w2) == "so long and thanks for all the fish")
	assert(cleaver("solongandthanksforalllthefish", w2) == "Cleaving stalled: Word not found")
	assert(cleaver("tosummarizethesummaryofthesummarypeopleareaproblem", w2) == "to summarize the summary of the summary people are a problem")
	assert(cleaver("timeisanillusionlunchtimedoublyso", w2) == "time is an illusion lunchtime doubly so")
	assert(cleaver("ilovedeadlinesilovethewhooshingnoisetheymakeastheygoby", w2) == "i love deadlines i love the whooshing noise they make as they go by")
	assert(cleaver("ilovedeadlinesilovethewheezingnoisetheymakeastheygoby", w2) == "Cleaving stalled: Word not found")
	assert(cleaver("foramomentnothinghappenedthenafterasecondorsonothingcontinuedtohappen", w2) == "for a moment nothing happened then after a second or so nothing continued to happen")

	assert(cleaver("", w1) == "")
	assert(cleaver("", w2) == "")
}

func cleaver(s string, w []string) string {
	t, f := cleaverrec(s, w)
	if !f {
		return "Cleaving stalled: Word not found"
	}
	if len(t) > 0 {
		t = t[:len(t)-1]
	}
	return t
}

func cleaverrec(s string, w []string) (string, bool) {
	if len(s) == 0 {
		return "", true
	}

	for _, p := range w {
		if len(s) >= len(p) && s[:len(p)] == p {
			t, f := cleaverrec(s[len(p):], w)
			if !f {
				continue
			}

			return s[:len(p)] + " " + t, true
		}
	}
	return "", false
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

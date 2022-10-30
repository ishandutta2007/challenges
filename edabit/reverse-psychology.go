/*

For this challenge, you will NOT be given a string.
Your task isn't to add "Do not" before the given string.
If there is no given string, you will not return "Do not do anything."
Do not check the examples to know how to do this challenge.

Examples

reversePsychology("wash the dishes") ➞ "Do not wash the dishes."

reversePsychology("eat your lunch") ➞ "Do not eat your lunch."

reversePsychology("go to school") ➞ "Do not go to school."

Notes

Are available.

*/

package main

func main() {
	assert(psych("wash the dishes") == "Do not wash the dishes.")
	assert(psych("eat your lunch") == "Do not eat your lunch.")
	assert(psych("go to school") == "Do not go to school.")
	assert(psych("") == "Do not do anything.")
	assert(psych("read") == "Do not read.")
	assert(psych("learn Python") == "Do not learn Python.")
	assert(psych("exercise") == "Do not exercise.")
	assert(psych("buy PC parts") == "Do not buy PC parts.")
	assert(psych("do your homework") == "Do not do your homework.")
	assert(psych("drink water") == "Do not drink water.")
	assert(psych("look around") == "Do not look around.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func psych(s string) string {
	if s == "" {
		s = "do anything"
	}
	return "Do not " + s + "."
}

/*

There is a game in which you try not to repeat a word while your opponent tries to see if you have repeated one.

"THE RAIN IN SPAIN" has no repeats.

"IN THE RAIN AND THE SNOW" repeats THE.

"THE RAIN IN SPAIN IN THE PLAIN" repeats THE and IN.

Write a program to test a phrase.
Input

Input is a line containing words separated by single spaces, where a word consists of one or more uppercase letters.
A line contains no more than 80 characters.

Output

The output is "yes" if no word is repeated, and "no" if one or more words repeat.

*/

package main

import "strings"

func main() {
	assert(norepeats("THE RAIN IN SPAIN") == "yes")
	assert(norepeats("IN THE RAIN AND THE SNOW") == "no")
	assert(norepeats("THE RAIN IN SPAIN IN THE PLAIN") == "no")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func norepeats(s string) string {
	t := strings.Split(s, " ")
	m := make(map[string]bool)
	for _, t := range t {
		if m[t] {
			return "no"
		}
		m[t] = true
	}
	return "yes"
}

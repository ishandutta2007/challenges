/*

Challenge

For each character of the string except for the last one, do the following:

    Output the current character.

    Followed by randomly outputting from the following list a random number of times between 1 - 5 (inclusive):
        The current character
        The next character of the string
        The switchcase version of the character that you are currently on
        The switchcase version of the next character of the string.

Test Cases

String --> SSSTSStrTrIiinIIngn

, . , . , . Hello world! --> ,,,  ..    , ,,    ....    , ,   .. .. .   HHH HHEeelLlLllooO   wwOworOOrrrRllDd!!D

Programming Puzzles and Code Golf --> PrPPrRrOooooogggRgGraAraaaMMMmmmimMIiininGGgG  PPPPuZzZZzZzzZzllLLEEeEsEsssS  a aANnNddD C  COCoooOOdeDe   E GGGoOllFFf

Notes

    You only need to apply the switchcase version of a character if the character is part of the alphabet (A-Z and a-z).
    Your random function does not need to be uniform but it still needs to have a chance of returning any element in the list given.
    You are allowed to use any standard I/O format.
    You may assume that the length of the input is greater than or equal to two.
    You may assume that the input only consists of ASCII characters.
    The title is not a test case (it is unintentional if it is a valid test case).
    Switchcase means to turn the char to lowercase if it is uppercase and to turn it to uppercase if it is lowercase.

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
	"time"
	"unicode"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(gen("String"))
	fmt.Println(gen(", . , . , . Hello world!"))
	fmt.Println(gen("Programming Puzzles and Code Golf"))
}

func gen(s string) string {
	w := new(bytes.Buffer)
	l := rune(-1)
	for i, r := range s {
		w.WriteRune(r)
		if i > 0 {
			pick(w, l, r)
		}
		l = r
	}
	pick(w, l, l)
	return w.String()
}

func pick(w *bytes.Buffer, a, b rune) {
	p := []rune{a, b, swc(a), swc(b)}
	n := 1 + rand.Intn(5)
	for i := 0; i < n; i++ {
		j := rand.Intn(len(p))
		w.WriteRune(p[j])
	}
}

func swc(r rune) rune {
	if unicode.IsLower(r) {
		return unicode.ToUpper(r)
	}
	if unicode.IsUpper(r) {
		return unicode.ToLower(r)
	}
	return r
}

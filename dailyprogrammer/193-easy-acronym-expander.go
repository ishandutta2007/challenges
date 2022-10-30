/*

Description

During online gaming (or any video game that requires teamwork) , there is often times that you need to speak to your teammates. Given the nature of the game, it may be inconvenient to say full sentences and it's for this reason that a lot of games have acronyms in place of sentences that are regularly said.

Example

gg : expands to 'Good Game'
brb : expands to 'be right back'

and so on...

This is even evident on IRC's and other chat systems.

However, all this abbreviated text can be confusing and intimidating for someone new to a game. They're not going to instantly know what 'gl hf all'(good luck have fun all) means. It is with this problem that you come in.

You are tasked with converting an abbreviated sentence into its full version.
Inputs & Outputs
Input

On console input you will be given a string that represents the abbreviated chat message.
Output

Output should consist of the expanded sentence
Wordlist

Below is a short list of acronyms paired with their meaning to use for this challenge.

    lol - laugh out loud

    dw - don't worry

    hf - have fun

    gg - good game

    brb - be right back

    g2g - got to go

    wtf - what the fuck

    wp - well played

    gl - good luck

    imo - in my opinion

Sample cases
input

wtf that was unfair

output

'what the fuck that was unfair'

input

gl all hf

output

'good luck all have fun'

Test case
input

imo that was wp. Anyway I've g2g

output

????

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
	"unicode"
)

func main() {
	test("wtf that was unfair", "what the fuck that was unfair")
	test("gl all hf", "good luck all have fun")
	test("imo that was wp. Anyway I've g2g", "in my opinion that was well played. Anyway I've got to go")
	test("GG", "Good Game")
	test("brb", "be right back")
}

func test(s, r string) {
	p := unacronym(s)
	fmt.Println(s)
	fmt.Println(p)
	fmt.Println()
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func unacronym(s string) string {
	m := map[string]string{
		"lol": "laugh out loud",
		"dw":  "don't worry",
		"hf":  "have fun",
		"gg":  "good game",
		"brb": "be right back",
		"g2g": "got to go",
		"wtf": "what the fuck",
		"wp":  "well played",
		"gl":  "good luck",
		"imo": "in my opinion",
	}

	w := new(bytes.Buffer)
	t := new(bytes.Buffer)
	for _, r := range s {
		switch {
		case unicode.IsSpace(r):
			output(m, w, t)
			w.WriteRune(r)
		default:
			t.WriteRune(r)
		}
	}
	output(m, w, t)

	return w.String()
}

func output(m map[string]string, w, t *bytes.Buffer) {
	defer t.Reset()

	s, u := unpunct(t.String())
	defer w.WriteString(u)

	l := strings.ToLower(s)
	p, f := m[l]
	if !f {
		w.WriteString(s)
		return
	}

	v := strings.Split(p, " ")
	for i := 0; i < len(s); i++ {
		if unicode.IsUpper(rune(s[i])) {
			v[i] = strings.Title(v[i])
		}
		w.WriteString(v[i])
		if i+1 < len(s) {
			w.WriteRune(' ')
		}
	}
}

func unpunct(s string) (a, b string) {
	a = s
	r := []rune(s)
	for i := len(r) - 1; i >= 0; i-- {
		if !unicode.IsPunct(r[i]) {
			a = string(r[:i+1])
			b = string(r[i+1:])
			break
		}
	}
	return
}

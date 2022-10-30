/*

This challenge has been divided into parts.
Your goal is to convert a sentence into a form of 'short-hand'

For Part 1 these are the rules
Take in 1 word
Remove all vowels, except the ones at the beginning and the end
If a letter is repeated more than once consecutively, reduce it to only one (e.g. Hello -> Hlo)
Create a function which converts the word into it's corresponding unicode characters based on above given rules, as given in the table
Letter	Corresponding Unicode Character
A	Λ
B	L
C	𐍉
D	Ꙅ
E	∟
F	⌽
G	T
H	|
I	⩗
J	)
K	<
L	(
M	ᨈ
N	ᑎ
O	┼
P	⊥
Q	⩁
R	\
S	⦵
T	_
U	⋃
V	⌵
W	⌵ (same as V)
X	X
Y	ɥ
Z	ᒣ
Test Cases
English Word	Substituted Word
Quick	⩁𐍉<
Brown	L\⌵ᑎ
Fox	⌽X
Jumped	)ᨈ⊥Ꙅ
Over	┼⌵|\
The	_|∟
Lazy	(ᒣɥ
Dog	ꙄT
As this is code-golf, shortest answer wins!

To get an idea of what part 2 will have in store check out this sandbox link.

Part 2 coming soon

*/

package main

import (
	"bytes"
	"strings"
)

func main() {
	assert(conv("Quick") == "⩁𐍉<")
	assert(conv("Brown") == "L\\⌵ᑎ")
	assert(conv("Fox") == "⌽X")
	assert(conv("Jumped") == ")ᨈ⊥Ꙅ")
	assert(conv("Over") == "┼⌵\\")
	assert(conv("The") == "_|∟")
	assert(conv("Lazy") == "(ᒣɥ")
	assert(conv("Dog") == "ꙄT")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func conv(s string) string {
	m := map[rune]rune{
		'A': 'Λ',
		'B': 'L',
		'C': '𐍉',
		'D': 'Ꙅ',
		'E': '∟',
		'F': '⌽',
		'G': 'T',
		'H': '|',
		'I': '⩗',
		'J': ')',
		'K': '<',
		'L': '(',
		'M': 'ᨈ',
		'N': 'ᑎ',
		'O': '┼',
		'P': '⊥',
		'Q': '⩁',
		'R': '\\',
		'S': '⦵',
		'T': '_',
		'U': '⋃',
		'V': '⌵',
		'W': '⌵',
		'X': 'X',
		'Y': 'ɥ',
		'Z': 'ᒣ',
	}

	w := new(bytes.Buffer)
	p := rune(-1)
	for i, r := range s {
		if 'a' <= r && r <= 'z' {
			r = r - 'a' + 'A'
		}
		if r == p || (i > 0 && i+1 < len(s) && isvowel(r)) {
			continue
		}
		if t, ok := m[r]; ok {
			r = t
		}

		w.WriteRune(r)
		p = r
	}
	return w.String()
}

func isvowel(r rune) bool {
	return strings.IndexRune("AEIOU", r) >= 0
}

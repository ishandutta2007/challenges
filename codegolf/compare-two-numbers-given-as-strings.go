/*

I have a problem at work. I need to compare two numbers that come as strings from two different databases. The numbers may come with leading zeroes and/or leading/trailing spaces.
So I may have "0001 " from one database and " 1  " from the other one.

I solved the problem in C# with the following code:
Func<string, string, bool> f = (a,b) => int.Parse(a.Trim()) == int.Parse(b.Trim())

The challenge

This is a really simple challenge, suitable for beginners and any kind of esoteric languages. Given two numbers as strings that may come with leading zeroes and/or leading/trailing spaces, write the shortest code that checks if the two strings represent the same number.

    The inputs need to be two strings or the equivalent in your language (a char array is OK), and they will always represent integer values greater than zero.
    The output must be any two consistent values that represent a truthy value and a falsey value.

Examples

A          B          Result
----------------------------
"0001"     "1    "    true
"1450"     "1450 "    true
"0010001 " " 10001  " true
"0010000"  "  10  "   false
"101023"   "101024"   false

This is code-golf, so may the shortest code for each language win!

*/

package main

import (
	"math/big"
	"strings"
)

func main() {
	assert(cmp("0001", "1    ") == true)
	assert(cmp("1450", "1450 ") == true)
	assert(cmp("0010001 ", " 10001") == true)
	assert(cmp("0010000", "  10  ") == false)
	assert(cmp("101023", "101024") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cmp(s, t string) bool {
	x := new(big.Int)
	y := new(big.Int)

	s = strings.TrimSpace(s)
	t = strings.TrimSpace(t)

	x.SetString(s, 10)
	y.SetString(t, 10)

	return x.Cmp(y) == 0
}

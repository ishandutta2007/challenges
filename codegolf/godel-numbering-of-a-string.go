/*

Background

Gödel numbers are a way of encoding any string with a unique positive integer, using prime factorisations:

First, each symbol in the alphabet is assigned a predetermined integer code.

Then, to encode a string x1x2x3…xn, where each xi

represents an symbol's integer code, the resultant number is

∏i=1npxii=2x1⋅3x2⋅5x3⋅…⋅pxnn

where pi
represents the i

th prime number. By the fundamental theorem of arithmetic, this is guaranteed to produce a unique representation.

For this challenge, we will only consider strings made of the symbols Gödel originally used for his formulae and use their values, which are:

    0: 1
    s: 3
    ¬: 5
    ∨: 7
    ∀: 9
    (: 11
    ): 13

...although for simplicity the symbols ¬, ∨, and ∀ can be replaced by the ASCII symbols ~, |, and A respectively.

(I don't know why Gödel used only odd numbers for these, but they're what he assigned so we're sticking with it)
Challenge

Given a string consisting only of the symbols above, output its Gödel encoding as an integer.

You may assume the input will consist only of character in the set 0s~|A().
Example

For the string ~s0:

    start with 1

, the multiplicative identity
the first character ~ has code 5
; the 1st prime is 2, so multiply by 25; the running product is 32
the 2nd character s has code 3
; the 2nd prime is 3, so multiply by 33; the running product is 864
the 3rd character 0 has code 1
; the 3rd prime is 5, so multiply by 51; the running product is 4320
so the final answer is 4320

Test-cases

Input        Output
""           1
"A"          512
"~s0"        4320
"0A0"        196830
")("         1451188224
"sssss0"     160243083000
"~(~0|~s0)"  42214303957706770300186902604046689348928700000
"0s~|A()"    5816705571109335207673649552794052292778133868750

Rules

    Your program does not have to work for strings that would produce larger integers than your programming language can handle, but it must work in theory
    You can accept input as a string, list of characters, or list of code-points
    You may use any reasonable I/O method
    Standard loopholes are forbidden
    This is code-golf, so the shortest code in bytes wins

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test("", "1")
	test("A", "512")
	test("~s0", "4320")
	test("0A0", "196830")
	test(")(", "1451188224")
	test("sssss0", "160243083000")
	test("~(~0|~s0)", "42214303957706770300186902604046689348928700000")
	test("0s~|A()", "5816705571109335207673649552794052292778133868750")
}

func test(s, r string) {
	m := map[rune]int64{
		'0': 1,
		's': 3,
		'¬': 5,
		'v': 7,
		'∀': 9,
		'(': 11,
		')': 13,

		'~': 5,
		'|': 7,
		'A': 9,
	}

	x := godel(s, m)
	fmt.Println(x)
	assert(x.String() == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func godel(s string, m map[rune]int64) *big.Int {
	r := big.NewInt(1)
	p := big.NewInt(2)
	for _, c := range s {
		x := new(big.Int)
		x.Exp(p, big.NewInt(m[c]), nil)
		r.Mul(r, x)
		nextprime(p)
	}
	return r
}

func nextprime(n *big.Int) {
	one := big.NewInt(1)
	for {
		n.Add(n, one)
		if n.ProbablyPrime(100) {
			break
		}
	}
}

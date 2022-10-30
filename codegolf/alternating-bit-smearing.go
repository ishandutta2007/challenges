/*

Introduction

This challenge requires you to set the trailing zeros of an integers binary representation to 010101…, this is best explained with an example:

Given the integer 400, the first step is to convert it to binary:

110010000

As we can see the fifth bit is the least significant 1 bit, so starting from there we replace the lower zeros by 0101:

110010101

Finally we convert that back to decimal: 405
Challenge

Given a positive integer return/output the corresponding resulting value of the above defined process.
Rules

    This sequence is only defined for integers with at least one 1 bit, so the input will always be ≥ 1
    You may take input as a string, list of digits (decimal) instead
    You don't have to handle invalid inputs

Testcases

Here are some more testcases with the intermediary steps (you don't have to print/return these):

In -> … -> … -> Out
1 -> 1 -> 1 -> 1
2 -> 10 -> 10 -> 2
3 -> 11 -> 11 -> 3
4 -> 100 -> 101 -> 5
24 -> 11000 -> 11010 -> 26
29 -> 11101 -> 11101 -> 29
32 -> 100000 -> 101010 -> 42
192 -> 11000000 -> 11010101 -> 213
400 -> 110010000 -> 110010101 -> 405
298 -> 100101010 -> 100101010 -> 298

*/

package main

import (
	"math/bits"
)

func main() {
	assert(smear(1) == 1)
	assert(smear(2) == 2)
	assert(smear(3) == 3)
	assert(smear(4) == 5)
	assert(smear(24) == 26)
	assert(smear(29) == 29)
	assert(smear(32) == 42)
	assert(smear(192) == 213)
	assert(smear(400) == 405)
	assert(smear(298) == 298)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func smear(x uint) uint {
	z := uint(bits.TrailingZeros(x))
	m := uint(1)<<z - 1
	s := 1 ^ (z & 1)
	return (x &^ m) | ((alt(z) >> s) & m)
}

func alt(n uint) uint {
	b := uint(0)
	for i := uint(0); i < n; i += 32 {
		b = (b << 32) | 0xaaaaaaaa
	}
	return b
}

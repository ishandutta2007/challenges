/*

Your task is to given two integer numbers, a and b calculate the modular multiplicative inverse of a modulo b, if it exists.

The modular inverse of a modulo b is a number c such that ac ≡ 1 (mod b). This number is unique modulo b for any pair of a and b. It exists only if the greatest common divisor of a and b is 1.

The Wikipedia page for modular multiplicative inverse can be consulted if you require more information about the topic.
Input and Output

Input is given as either two integers or a list of two integers. Your program should output either a single number, the modular multiplicative inverse that is in the interval 0 < c < b, or a value indicating there is no inverse.
The value can be anything, except a number in the range (0,b), and may also be an exception. The value should however be the same for cases in which there is no inverse.

0 < a < b can be assumed
Rules

    The program should finish at some point, and should solve each test case in less than 60 seconds
    Standard loopholes apply

Test cases

Test cases below are given in the format, a, b -> output

1, 2 -> 1
3, 6 -> Does not exist
7, 87 -> 25
25, 87 -> 7
2, 91 -> 46
13, 91 -> Does not exist
19, 1212393831 -> 701912218
31, 73714876143 -> 45180085378
3, 73714876143 -> Does not exist

Scoring

This is code golf, so the shortest code for each language wins.

This and this are similar questions, but both ask for specific situations.

*/

package main

import (
	"math/big"
)

func main() {
	assert(modinv(1, 2) == 1)
	assert(modinv(3, 6) == 0)
	assert(modinv(25, 87) == 7)
	assert(modinv(2, 91) == 46)
	assert(modinv(13, 91) == 0)
	assert(modinv(19, 1212393831) == 701912218)
	assert(modinv(31, 73714876143) == 45180085378)
	assert(modinv(3, 73714876143) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func modinv(a, b int64) int64 {
	x := big.NewInt(a)
	y := big.NewInt(b)
	z := new(big.Int)
	z.ModInverse(x, y)
	return z.Int64()
}

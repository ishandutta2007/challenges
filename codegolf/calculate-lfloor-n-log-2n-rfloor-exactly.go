/*

Given an integer n≥2, you need to calculate ⌊nlog2(n)⌋, assuming all integers in your language are unbounded.

However, you may not ignore floating-point errors - for example, in python lambda n:int(n*math.log2(n)) is an invalid solution, because for example for n=10**15, int(n*math.log2(n)) is 49828921423310432, while the actual answer is 49828921423310435.
Rules

    You can assume the input is an integer n≥2

    You may use any reasonable I/O method
    Standard loopholes are disallowed

Test cases

2 -> 2
3 -> 4
4 -> 8
5 -> 11
6 -> 15
7 -> 19
8 -> 24
9 -> 28
10 -> 33
100 -> 664
1000 -> 9965
10000 -> 132877

10 brownie points for beating my 4 byte 05AB1E answer.

This is code golf, so the shortest answer wins. Good luck!

*/

package main

import (
	"math/big"
)

func main() {
	assert(calc("2") == 2)
	assert(calc("3") == 4)
	assert(calc("4") == 8)
	assert(calc("5") == 11)
	assert(calc("6") == 15)
	assert(calc("7") == 19)
	assert(calc("8") == 24)
	assert(calc("9") == 28)
	assert(calc("10") == 33)
	assert(calc("100") == 664)
	assert(calc("1000") == 9965)
	assert(calc("10000") == 132877)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

x = floor(n*log2(n)) =>
x + 1 > nlogn >= x   =>
2^(x+1) > n^n >= 2^x

So we can count the number of bits in the binary representation of n^n

*/

func calc(s string) int {
	x := xint(s)
	y := xint(s)
	x.Exp(x, y, nil)
	return x.BitLen() - 1
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 0)
	return x
}

/*

Cryptocurrencies often have a lot of decimals. For example, the popular cryptocurrency Ethereum has 18 decimals.

When dealing with money, precision is important, you don't want to lose money because a number is losing precision.
However, with JavaScript, normal numbers only can go up to 9007199254740991.
To deal with this, Javascript now has BigInt for integers bigger than that.

However, in order to get back to a decimal number, the number needs to be formatted from a BigInt
to a string with the right number of decimals.

Write a function that takes as arguments a BigInt and the desired amount of decimals and returns a string (not a number,
as it will lose precision) with the correct amount of decimals.

Examples

formatBigInt(1938908490185852058934n, 18) ➞ "1938.908490185852058934"

formatBigInt(987654321987654321n, 6 ) ➞ "987654321987.654321"

formatBigInt(13902183984901849081284n, 12) ➞ "13902183984.901849081284"

Notes

N/A

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test("1938908490185852058934", 18, "1938.908490185852058934")
	test("987654321987654321", 6, "987654321987.654321")
	test("13902183984901849081284", 12, "13902183984.901849081284")
	test("923948293849023849082094892384024", 18, "923948293849023.849082094892384024")
}

func test(s string, p int, r string) {
	assert(format(xint(s), p) == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func format(x *big.Int, p int) string {
	s := x.String()
	if p < len(s) {
		s = fmt.Sprintf("%s.%s", s[:len(s)-p], s[len(s)-p:])
	}
	return s
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 10)
	return x
}

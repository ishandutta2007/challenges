/*

This is a big integer challenge. You are given an integer which is a perfect square.
It is composed of 40 or more digits. Compose a function which will find the exact square root of this integer.

Examples

square_root(152415787532388367501905199875019052100) ➞ 12345678901234567890

square_root(10203040506070809101112131413121110090807060504030201) ➞ 101010101010101010101010101

Notes

    All test cases are perfect squares.
    A good fortune bonus awaits you if you are able to complete this challenge without importing anything.

*/

package main

import "math/big"

func main() {
	test("152415787532388367501905199875019052100", "12345678901234567890")
	test("10203040506070809101112131413121110090807060504030201", "101010101010101010101010101")
	test("99999999999999999999999999999999980000000000000000000000000000000001", "9999999999999999999999999999999999")
	test("26012373132601867052476279556925062199860545403217014724556740172086055720960144", "5100232654752316987921302256990145665012")
	test("10000000000653082513985774051254010860475894726927998293429981274129769314201", "100000000003265412569875555660012547899")
}

func test(s, t string) {
	x := new(big.Int)
	y := new(big.Int)
	x.SetString(s, 10)
	y.SetString(t, 10)
	z := sqrt(x)
	assert(y.Cmp(z) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sqrt(x *big.Int) *big.Int {
	z := new(big.Int)
	z.Sqrt(x)
	return z
}

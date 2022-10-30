/*

Write a function f(a,b,c) that calculates a^b (mod c) in less than 10 seconds.

    a, b < 10^100
    c < 10000.

examples:

f(10^50, 10^50, 54123) = 46555
f(5^99, 10^99, 777) = 1

*/

package main

import (
	"math/big"
)

func main() {
	test("100000000000000000000000000000000000000000000000000", "100000000000000000000000000000000000000000000000000", "54123", "46555")
	test("1577721810442023610823457130565572459346412870218046009540557861328125", "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "777", "1")
}

func test(a, b, c, r string) {
	p := modexp(a, b, c)
	assert(p.String() == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func modexp(a, b, c string) *big.Int {
	x := xint(a)
	y := xint(b)
	z := xint(c)
	x.Exp(x, y, z)
	return x
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 0)
	return x
}

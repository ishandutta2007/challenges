/*

Background
The hyperfactorial is a variant of the factorial function. is defined as
H(n)=1^1⋅2^2⋅3^3⋅⋯⋅n^n

For example, H(4)=1^1⋅2^2⋅3^3⋅4^4=27648.

Test cases
n   H(n)
0   1
1   1
2   4
3   108
4   27648
5   86400000
6   4031078400000
7   3319766398771200000
8   55696437941726556979200000

Rules
The standard loopholes are forbidden.
As this is a code-golf, the shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test("0", "1")
	test("1", "1")
	test("2", "4")
	test("3", "108")
	test("4", "27648")
	test("5", "86400000")
	test("6", "4031078400000")
	test("7", "3319766398771200000")
	test("8", "55696437941726556979200000")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, r string) {
	x := hyperfactorial(xint(s))
	p := x.String()
	fmt.Println(p)
	assert(p == r)
}

func hyperfactorial(n *big.Int) *big.Int {
	var (
		zero = big.NewInt(0)
		one  = big.NewInt(1)
	)

	if n.Cmp(zero) < 0 {
		return zero
	}

	r := big.NewInt(1)
	for i := big.NewInt(1); i.Cmp(n) <= 0; i.Add(i, one) {
		x := new(big.Int)
		x.Exp(i, i, nil)
		r.Mul(r, x)
	}
	return r
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 10)
	return x
}

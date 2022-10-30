/*

The Challenge

Implement tetration (aka Power Tower or Hyperexponentiation) with the least amount of characters.

The Conditions

    Don't use the 'power' operator or its equivalents (such as pow(x,y), x^y, x**y, etc.)
    Input given as: x y (separated by a space)
    x is exponentiated by itself y times.
    Your method must be able to compute at least 4 3 (4 exponentiated by itself 3 times)

The Scoring

    Lowest score wins: (# of characters)
    Bonus deduction if you do not use the multiplication operator (-5 points).
    No Speed/Memory requirements. Take as long as you want.

Examples

x, 0 -> 1

2, 2 -> 2^2 = 4

2, 4 -> 2^(2^(2^2)) = 65536

4, 3 -> 4^(4^4) = 4^256 = 13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096

Open to suggestions/alterations/questions

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test("2", "2", "4")
	test("2", "4", "65536")
	test("4", "3", "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096")
}

func test(s, t, r string) {
	x := xint(s)
	y := xint(t)
	p := tetration(x, y)
	fmt.Println(p)
	assert(p.String() == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tetration(x, y *big.Int) *big.Int {
	var (
		one = big.NewInt(1)
	)

	p := new(big.Int)
	p.Set(x)
	r := big.NewInt(1)
	for i := big.NewInt(1); i.Cmp(y) < 0; i.Add(i, one) {
		r.Exp(x, p, nil)
		p.Set(r)
	}

	return r
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 10)
	return x
}

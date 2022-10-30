/*

Write a program or function that finds the number of zeroes at the end of n! in base 10, where n is an input number (in any desired format).

It can be assumed that n is a positive integer, meaning that n! is also an integer. There are no zeroes after a decimal point in n!.
Also, it can be assumed that your programming language can handle the value of n and n!.

Test cases

1
==> 0

5
==> 1

100
==> 24

666
==> 165

2016
==> 502

1234567891011121314151617181920
==> 308641972752780328537904295461

This is code golf. Standard rules apply. The shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test("1", "0")
	test("5", "1")
	test("100", "24")
	test("666", "165")
	test("2016", "502")
	test("1234567891011121314151617181920", "308641972752780328537904295461")
}

func test(n, r string) {
	x := zeroes(xint(n))
	y := xint(r)
	fmt.Println(x)
	assert(x.Cmp(y) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

The ending zeroes are limited by factors of 5. The number of multiples of 5 that are at most n is n/5 (with floor division),
but this doesn't count the repeated factors in multiples of 25, 125, .... To get those, divide n by 5 and recurse.

*/
func zeroes(n *big.Int) *big.Int {
	var (
		zero = big.NewInt(0)
		five = big.NewInt(5)
	)

	r := new(big.Int)
	for n.Cmp(zero) != 0 {
		n.Quo(n, five)
		r.Add(r, n)
	}
	return r
}

func xint(s string) *big.Int {
	r := new(big.Int)
	r.SetString(s, 0)
	return r
}

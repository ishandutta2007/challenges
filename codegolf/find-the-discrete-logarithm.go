/*

Task

Write a program/function that when given 3 positive integers a,b
and m as input outputs a positive integer x such that ax≡b (mod m) or that no such x exists.

A reference implementation can be found here.
Constraints

You can expect a and b to be less than m.

Scoring

This is code-golf so shortest bytes wins.
Sample Testcases

# a, b, m -> x

10, 10, 50 -> 1
10, 100, 200 -> 2
10, 1, 127 -> 42
35, 541, 1438 -> 83
35, 541, 1438 -> 1519
1816, 2629, 3077 -> 223
3306, 4124, 5359 -> 1923
346, 406, 430 -> None
749430, 2427332, 2500918 -> 8025683
3442727916, 3990620294, 6638635157 -> 5731137125

Note: in the third testcase the solution cannot be 0 since the solution has to be a positive number

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test(10, 10, 50)
	test(10, 100, 200)
	test(10, 1, 127)
	test(35, 541, 1438)
	test(1816, 2629, 3077)
	test(3306, 4124, 5359)
	test(346, 406, 430)
	test(749430, 2427332, 2500918)
	test(3442727916, 3990620294, 6638635157)
}

func test(a, b, m uint64) {
	x := dlog(a, b, m)
	fmt.Printf("a=%v b=%v m=%v x=%v\n", a, b, m, x)
	if x != 0 {
		assert(powm(a, x, m) == b)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func dlog(a, b, m uint64) uint64 {
	for x := uint64(1); x < m; x++ {
		if powm(a, x, m) == b {
			return x
		}
	}
	return 0
}

func powm(a, x, m uint64) uint64 {
	r := new(big.Int)
	r.Exp(xint(a), xint(x), xint(m))
	return r.Uint64()
}

func xint(n uint64) *big.Int {
	x := new(big.Int)
	x.SetUint64(n)
	return x
}

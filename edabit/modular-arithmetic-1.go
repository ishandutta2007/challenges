/*

Modify the inefficient code in the Code tab so it can pass the tests.

Examples

mod(base, exp, k) ➞ (base**(2**exp)) % k

mod(10, 1, 99 ) ➞ 1

mod(3, 2, 15 ) ➞ 6

mod(123, 20, 1234 ) ➞ 391

Notes

Try using loops.

*/

package main

import (
	"math/big"
)

func main() {
	assert(mod(10, 1, 99) == 1)
	assert(mod(3, 2, 15) == 6)
	assert(mod(123, 20, 1234) == 391)
	assert(mod(3, 5, 15) == 6)
	assert(mod(10, 5, 99) == 1)
	assert(mod(11, 23, 23) == 8)
	assert(mod(11, 1000, 23) == 12)
	assert(mod(5432, 234625, 4321) == 1734)
	assert(mod(146145432, 5423345, 542) == 100)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mod(b, e, k int64) int64 {
	x := big.NewInt(b)
	y := big.NewInt(1)
	y.Lsh(y, uint(e))
	z := big.NewInt(k)
	x.Exp(x, y, z)
	return x.Int64()
}

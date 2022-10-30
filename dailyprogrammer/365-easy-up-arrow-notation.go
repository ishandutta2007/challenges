/*

Description
We were all taught addition, multiplication, and exponentiation in our early years of math.
You can view addition as repeated succession. Similarly, you can view multiplication as repeated addition.
And finally, you can view exponentiation as repeated multiplication.
But why stop there? Knuth's up-arrow notation takes this idea a step further. The notation is used to represent repeated operations.

In this notation a single ↑ operator corresponds to iterated multiplication. For example:

2 ↑ 4 = ?
= 2 * (2 * (2 * 2))
= 2^4
= 16
While two ↑ operators correspond to iterated exponentiation. For example:

2 ↑↑ 4 = ?
= 2 ↑ (2 ↑ (2 ↑ 2))
= 2^2^2^2
= 65536
Consider how you would evaluate three ↑ operators. For example:

2 ↑↑↑ 3 = ?
= 2 ↑↑ (2 ↑↑ 2)
= 2 ↑↑ (2 ↑ 2)
= 2 ↑↑ (2 ^ 2)
= 2 ↑↑ 4
= 2 ↑ (2 ↑ (2 ↑ 2))
= 2 ^ 2 ^ 2 ^ 2
= 65536

In today's challenge, we are given an expression in Kuth's up-arrow notation to evaluate.

(These expression are way too big for a normal computer to calculate)

5 ↑↑↑↑ 5
7 ↑↑↑↑↑ 3
-1 ↑↑↑ 3
1 ↑ 0
1 ↑↑ 0
12 ↑↑↑↑↑↑↑↑↑↑↑ 25

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(upi(2, 1, 4))
	fmt.Println(upi(2, 2, 4))
	fmt.Println(upi(2, 3, 3))
	fmt.Println(upi(3, 2, 3))
	fmt.Println(upi(4, 2, 1))
	fmt.Println(upi(4, 2, 2))
	fmt.Println(upi(4, 2, 3))
}

func upi(a, n, b int64) *big.Int {
	ai := big.NewInt(a)
	ni := big.NewInt(n)
	bi := big.NewInt(b)
	return up(ai, ni, bi)
}

var (
	memo [][4]*big.Int
)

func get(a, n, b *big.Int) *big.Int {
	for _, m := range memo {
		if a.Cmp(m[0]) == 0 && n.Cmp(m[1]) == 0 && b.Cmp(m[2]) == 0 {
			return m[3]
		}
	}
	return nil
}

func put(a, n, b, v *big.Int) bool {
	if get(a, n, b) != nil {
		return false
	}

	memo = append(memo, [4]*big.Int{a, n, b, v})
	return true
}

func up(a, n, b *big.Int) *big.Int {
	v := get(a, n, b)
	if v != nil {
		return v
	}

	zero := big.NewInt(0)
	one := big.NewInt(1)
	if n.Cmp(one) == 0 {
		z := new(big.Int)
		z.Exp(a, b, nil)
		return z
	}

	if n.Cmp(one) >= 0 && b.Cmp(zero) == 0 {
		return one
	}

	bi := new(big.Int)
	bi.Sub(b, one)
	ni := new(big.Int)
	ni.Sub(n, one)

	return up(a, ni, up(a, n, bi))
}

/*

You are given the equation tan(a) = p/q and a positive integer, n.
Calculate tan(na).

If the result is defined, it is always a rational number. However, it can be very big.
Output the answer modulo (10^9 + 7)
If the answer is a/b and b is not divisible (10^9 + 7), there is a unique 0 <= x <= 10^9 + 7 where
a ≡ b mod (10^9 + 7)

Output this integer x

It is guaranteed that b is not divisible by (10^9 + 7) for all test cases

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(tanm(4, 2, 2))
	fmt.Println(tanm(5, 6, 7))
	fmt.Println(tanm(4, 2, 3))
	fmt.Println(tanm(5, 6, 1e3))
}

// calculate tan(na) knowing tan(a)=p/q
// by using tan() identities to subdivide
// tan(na) into parts
// tan(2a) = 2tan(a) / (1-tan^2(a))
// tan(a + b) = (tan(a)+tan(b)) / (1 - tan(a)tan(b))
func tan(p, q, n int) *big.Rat {
	if n < 0 {
		panic("invalid argument")
	}
	if n == 0 {
		return big.NewRat(0, 1)
	}
	if n == 1 {
		return big.NewRat(int64(p), int64(q))
	}

	one := big.NewRat(1, 1)
	two := big.NewRat(2, 1)

	r := new(big.Rat)
	if n%2 == 0 {
		// n is even, use tan(2a) identity
		x := tan(p, q, n/2)
		x.Mul(x, two)
		y := tan(p, q, n/2)
		y.Mul(y, y)
		y.Neg(y)
		y.Add(y, one)
		r.Quo(x, y)
	} else {
		// n is odd, use tan(a+b) identity
		// with a = 2m and b=1
		a := tan(p, q, 2*(n/2))
		b := tan(p, q, 1)
		x := new(big.Rat)
		x.Add(a, b)
		y := new(big.Rat)
		y.Mul(a, b)
		y.Neg(y)
		y.Add(y, one)
		r.Quo(x, y)
	}
	return r
}

// after getting the value of tangent
// treat p/q as
// p - qx = (1e9+7)y
// rewrite as p = qx + (1e9)y
// solve for x, y using gcd
// then we get
// m = qx + (1e9+7)y
// since m != p we have to
// multiply both sides by p/m to get
// p = q(px/m) + (1e9+7)(py/m)
// since we only care about solving for x
// we can ignore the y term at this stage
// then mod by (1e9+7) due to px/m can be too big
func tanm(p, q, n int) *big.Int {
	v := tan(p, q, n)
	x := v.Num()
	y := v.Denom()
	z := big.NewInt(1000000007)

	// use gcd to get the x and y constant into a and b
	a := new(big.Int)
	b := new(big.Int)
	c := new(big.Int)
	c.GCD(a, b, y, z)

	// multiply by p/m
	x.Quo(x, c)
	a.Mul(a, x)

	// mod it by 1e9+7
	a.Mod(a, z)

	return a
}

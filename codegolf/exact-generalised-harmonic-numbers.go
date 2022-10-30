/*

The generalised harmonic number of order m of n is H(n,m)=sum[k, n] 1/k^m

For example, the harmonic numbers are H(n, 1) and H(∞,2)=π^2/6.

These are related to the Riemann zeta function as

ζ(m)=lim n→∞ H(n,m)

Given two positive integers n>0, m>0, output the exact rational number H(n,m).
The fraction should be reduced to its simplest term (i.e. if it is ab, gcd(a,b)=1).

You may output as a numerator/denominator pair, a rational number or any clear value that distinguishes itself as a rational number.
You may not output as a floating point number.

This is code-golf, so the shortest code in bytes wins
Test cases

n, m -> Hₙ,ₘ
3, 7 -> 282251/279936
6, 4 -> 14011361/12960000
5, 5 -> 806108207/777600000
4, 8 -> 431733409/429981696
3, 1 -> 11/6
8, 3 -> 78708473/65856000
7, 2 -> 266681/176400
6, 7 -> 940908897061/933120000000
2, 8 -> 257/256
5, 7 -> 2822716691183/2799360000000

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	tab := []struct {
		n, m int64
		r    string
	}{
		{3, 7, "282251/279936"},
		{6, 4, "14011361/12960000"},
		{5, 5, "806108207/777600000"},
		{4, 8, "431733409/429981696"},
		{3, 1, "11/6"},
		{8, 3, "78708473/65856000"},
		{7, 2, "266681/176400"},
		{6, 7, "940908897061/933120000000"},
		{2, 8, "257/256"},
		{5, 7, "2822716691183/2799360000000"},
	}
	for _, p := range tab {
		v := H(p.n, p.m)
		fmt.Println(p.n, p.m, v)
		assert(v.String() == p.r)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func H(n, m int64) *big.Rat {
	r := new(big.Rat)
	p := big.NewInt(m)
	for k := int64(1); k <= n; k++ {
		x := big.NewInt(k)
		x.Exp(x, p, nil)
		u := new(big.Rat)
		u.SetInt(x)
		u.Inv(u)
		r.Add(r, u)
	}
	return r
}

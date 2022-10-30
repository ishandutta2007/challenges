/*

The Chinese Remainder Theorem tells us that we can always find a number that produces any required remainders under different prime moduli. Your goal is to write code to output such a number in polynomial time. Shortest code wins.

For example, say we're given these constraints:

	n ≡ 2 mod 7
	n ≡ 4 mod 5
	n ≡ 0 mod 11

One solution is n=44. The first constraint is satisfied because 44=6×7+2, and so 44 has remainder 2 when divided by 7, and thus 44≡2mod7.
The other two constraints are met as well. There exist other solutions, such as n=814 and n=−341.

Input

A non-empty list of pairs (pi,ai), where each modulus pi is a distinct prime and each target ai is a natural number in the range 0≤ai<pi.
You can take input in whatever form is convenient; it doesn't have to actually be a list of pairs. You may not assume the input is sorted.

Output

An integer n such that n ≡ a_i mod p_i for each index i. It doesn't have to be the smallest such value, and may be negative.

Polynomial time restriction

To prevent cheap solutions that just try n=0,1,2,…, and so on, your code must run in polynomial time in the length of the input.
Note that a number m in the input has length Θ(logm), so m itself is not polynomial in its length.
This means that you can't count up to m or do an operation m times, but you can compute arithmetic operations on the values.

You may not use an inefficient input format like unary to get around this.

Other bans

Built-ins to do the following are not allowed: Implement the Chinese Remainder theorem, solve equations, or factor numbers.

You may use built-ins to find mods and do modular addition, subtraction, multiplication, and exponentiation (with natural-number exponent). You may not use other built-in modular operations, including modular inverse, division, and order-finding.

Test cases

These give the smallest non-negative solution. Your answer may be different. It's probably better if you check directly that your output satisfies each constraint.

[(5, 3)]
3

[(7, 2), (5, 4), (11, 0)]
44

[(5, 1), (73, 4), (59, 30), (701, 53), (139, 112)]
1770977011

[(982451653, 778102454), (452930477, 133039003)]
68121500720666070

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test([][2]uint64{
		{5, 3},
	}, 3)

	test([][2]uint64{
		{7, 2},
		{5, 4},
		{11, 0},
	}, 44)

	test([][2]uint64{
		{5, 1},
		{73, 4},
		{59, 30},
		{701, 53},
		{139, 112},
	}, 1770977011)

	test([][2]uint64{
		{982451653, 778102454},
		{452930477, 133039003},
	}, 68121500720666070)
}

func test(a [][2]uint64, r uint64) {
	p := crt(a)
	fmt.Println(p)
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://crypto.stanford.edu/pbc/notes/numbertheory/crt.html
func crt(p [][2]uint64) uint64 {
	m := new(big.Int)
	a := new(big.Int)
	b := new(big.Int)
	bi := new(big.Int)

	M := big.NewInt(1)
	for _, v := range p {
		m.SetUint64(v[0])
		M.Mul(M, m)
	}

	t := new(big.Int)
	r := new(big.Int)
	for _, v := range p {
		m.SetUint64(v[0])
		a.SetUint64(v[1])
		b.Quo(M, m)
		bi.ModInverse(b, m)

		t.Set(a)
		t.Mul(t, b)
		t.Mul(t, bi)

		r.Add(r, t)
	}
	r.Mod(r, M)

	return r.Uint64()
}

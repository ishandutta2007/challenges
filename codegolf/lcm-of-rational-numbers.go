/*

The least common multiple (LCM) of a set of numbers A is the smallest integer b such that b/a is an integer for all integers a in A. This definition can be extended to rational numbers!

Task

Find the smallest positive rational b such that b/a is an integer for all rationals a in the input.
Rules

    Standard loopholes are forbidden.
    You may take numerators and denominators separately in the input, but may not take doubles, floats, etc.
    The input may not be fully reduced.
    You may take integer inputs as rationals with denominator of 1.
    Submissions that would feed rational numbers to an LCM/GCD builtin are allowed, but non-competing.

Test Cases

In:  3
Out: 3

In:  1/17
Out: 1/17

In:  1/2, 3/4
Out: 3/2

In:  1/3, 2/8
Out: 1

In:  1/4, 3
Out: 3

In:  2/5, 3
Out: 6

In:  1/2, 3/4, 5/6, 7/8
Out: 105/2

This is code-golf, so submissions using the fewest bytes win!

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test([]string{"3"}, "3")
	test([]string{"1/17"}, "1/17")
	test([]string{"1/2", "3/4"}, "3/2")
	test([]string{"1/3", "2/8"}, "1")
	test([]string{"1/4", "3"}, "3")
	test([]string{"2/5", "3"}, "6")
	test([]string{"1/2", "3/4", "5/6", "7/8"}, "105/2")
}

func test(s []string, r string) {
	var a []*big.Rat
	for i := range s {
		a = append(a, xrat(s[i]))
	}

	p := lcmrv(a)
	q := xrat(r)
	fmt.Println(p)
	assert(p.Cmp(q) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// lcm of rational numbers = lcm(numerators) / gcd(denominators)
func lcmrv(a []*big.Rat) *big.Rat {
	if len(a) == 0 {
		return nil
	}

	n := a[0].Num()
	d := a[0].Denom()
	for i := 1; i < len(a); i++ {
		n = lcm(n, a[i].Num())
		d = gcd(d, a[i].Denom())
	}
	r := new(big.Rat)
	r.SetFrac(n, d)
	return r
}

func lcm(a, b *big.Int) *big.Int {
	x := new(big.Int)
	x.Mul(a, b)
	y := gcd(a, b)
	x.Quo(x, y)
	return x
}

func gcd(a, b *big.Int) *big.Int {
	x := new(big.Int)
	x.GCD(nil, nil, a, b)
	return x
}

func xrat(s string) *big.Rat {
	x := new(big.Rat)
	x.SetString(s)
	return x
}

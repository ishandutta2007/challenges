// You're challenge for today is to create a program that can calculate pi accurately to at least 30 decimal places.
package main

import (
	"fmt"
	"math/big"
)

func main() {
	n := big.NewInt(2000)
	v := pi(n)
	s := v.FloatString(1001)
	fmt.Println(s[:len(s)-1])
}

// https://en.wikipedia.org/wiki/Pi#Spigot_algorithms
func pi(n *big.Int) *big.Rat {
	var (
		one     = big.NewInt(1)
		two     = big.NewInt(2)
		four    = big.NewInt(4)
		five    = big.NewInt(5)
		six     = big.NewInt(6)
		sixteen = big.NewInt(16)
	)

	p := big.NewRat(0, 1)

	r := new(big.Rat)
	a := new(big.Rat)
	b := new(big.Rat)
	c := new(big.Rat)
	d := new(big.Rat)
	e := new(big.Rat)

	i := big.NewInt(0)
	x := big.NewInt(0)
	y := big.NewInt(0)
	t := big.NewInt(1)
	for ; i.Cmp(n) < 0; i.Add(i, one) {
		a.SetFrac(one, t)
		t.Mul(t, sixteen)

		x.SetInt64(8)
		x.Mul(x, i)

		y.Add(x, one)
		b.SetFrac(four, y)

		y.Add(x, four)
		c.SetFrac(two, y)

		y.Add(x, five)
		d.SetFrac(one, y)

		y.Add(x, six)
		e.SetFrac(one, y)

		r.Set(b)
		r.Sub(r, c)
		r.Sub(r, d)
		r.Sub(r, e)
		r.Mul(r, a)

		p.Add(p, r)
	}
	return p
}

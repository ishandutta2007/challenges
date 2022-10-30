/*

I recently learned from a comment by MathOverflow user pregunton that it is possible to enumerate all rational numbers using iterated maps of the form f(x)=x+1 or g(x)=−1x, starting from 0.

For example,
0 ↦f 1 ↦f 2 ↦g -1/2 ↦f 1/2 ↦ f 3/2 ↦g -2/3 ↦f 1/3.

That is,
1/3=f(g(f(f(g(f(f(0)))))))=f∘g∘f∘f∘g∘f∘f(0).
This is an example of a shortest path of iterated maps to reach 13; every path from 0 to 13 requires at least seven steps.

Challenge
Your challenge is to take two integers, n and d, and return a string of f's and g's that represents a shortest path of iterated maps from 0 to n/d.

This is a code-golf, so shortest code wins.

Example
  n |  d | sequence of maps
----+----+-----------------
  1 |  3 | fgffgff
  3 |  1 | fff
  8 |  2 | ffff
  1 | -3 | gfff
  2 |  3 | fgfff
  0 |  9 | [empty string]
  1 |  1 | f
  2 |  1 | ff
  1 | -2 | gff
 -1 | -2 | fgff
  6 |  4 | ffgff
 -2 |  3 | gffgff
  8 |  9 | fgfffffffff

*/

package main

import (
	"bytes"
	"fmt"
	"math/big"
)

func main() {
	test(1, 3, "fgffgff")
	test(3, 1, "fff")
	test(8, 2, "ffff")
	test(1, -3, "gfff")
	test(2, 3, "fgfff")
	test(0, 9, "")
	test(1, 1, "f")
	test(2, 1, "ff")
	test(1, -2, "gff")
	test(-1, -2, "fgff")
	test(6, 4, "ffgff")
	test(-2, 3, "gffgff")
	test(8, 9, "fgfffffffff")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, d int64, r string) {
	p := seq(n, d)
	fmt.Println(p)
	assert(len(p) == len(r))
}

func seq(n, d int64) string {
	r := big.NewRat(n, d)
	a := "fg"
	p := []byte{}
	for {
		s := mkstr(p, a)
		v := fmap(s)
		if r.Cmp(v) == 0 {
			return s
		}
		p = iter(p, a)
	}
}

func iter(p []byte, a string) []byte {
	n := len(a)
	i := 0
	for ; i < len(p); i++ {
		if p[i]++; p[i] >= byte(n) {
			p[i] = 0
		} else {
			break
		}
	}
	if i >= len(p) {
		p = append(p, 0)
	}

	return p
}

func mkstr(p []byte, a string) string {
	w := new(bytes.Buffer)
	for _, i := range p {
		w.WriteByte(a[i])
	}
	return w.String()
}

func fmap(s string) *big.Rat {
	var (
		zero = big.NewRat(0, 1)
		one  = big.NewRat(1, 1)
	)

	x := new(big.Rat)
	for _, r := range s {
		switch r {
		case 'f':
			x.Add(x, one)
		case 'g':
			if x.Cmp(zero) != 0 {
				x.Inv(x)
				x.Neg(x)
			}
		}
	}
	return x
}

/*

Happy (Be-Lated) Pi Day! To celebrate, write a program that calculates a list of rational approximations of Pi. Output should look like:

3/1, 22/7, 333/106, 355/113, 52163/16604, 103993/33102, ...

Thanks to Cosmologicon for this programming suggestion in r/dailyprogrammer_ideas!

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	for i := int64(1); i <= 10; i++ {
		fmt.Println(ramanujan2(i))
	}
}

/*

https://keisan.casio.com/exec/system/1355104874
ramanujan infinite series 2

4/pi = sum[0, inf] ((-1)^n*(4n)!/(4^n*n!)^4) * ((1123 + 21460n)/(882*(2^n)))

*/
func ramanujan2(t int64) *big.Rat {
	if t < 1 {
		return nil
	}

	four := xint(4)
	r := new(big.Rat)
	for i := int64(0); i < t; i++ {
		n := xint(i)

		n1 := mul(pow(xint(-1), n), fact(mul(four, n)))
		d1 := pow(mul(pow(four, n), fact(n)), four)

		n2 := add(xint(1123), mul(xint(21460), n))
		d2 := pow(xint(882), mul(xint(2), n))

		r1 := xrat(n1, d1)
		r2 := xrat(n2, d2)
		r1.Mul(r1, r2)
		r.Add(r, r1)
	}
	r.Mul(r, big.NewRat(1, 882))
	r.Inv(r)
	r.Mul(r, big.NewRat(4, 1))
	return r
}

func xint(n int64) *big.Int {
	return big.NewInt(n)
}

func xrat(a, b *big.Int) *big.Rat {
	r := new(big.Rat)
	r.SetFrac(a, b)
	return r
}

func add(a, b *big.Int) *big.Int {
	r := new(big.Int)
	r.Add(a, b)
	return r
}

func mul(a, b *big.Int) *big.Int {
	r := new(big.Int)
	r.Mul(a, b)
	return r
}

func pow(a, b *big.Int) *big.Int {
	r := new(big.Int)
	r.Exp(a, b, nil)
	return r
}

func fact(n *big.Int) *big.Int {
	one := xint(1)
	r := xint(1)
	for i := xint(1); i.Cmp(n) <= 0; i.Add(i, one) {
		r.Mul(r, i)
	}
	return r
}

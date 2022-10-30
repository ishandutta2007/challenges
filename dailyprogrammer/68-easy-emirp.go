/*

Emirp is an interesting concept. The explanation about it is provided in the link i just gave.

Your task is to implement a function which prints out the emirps below a number(input) given by the user.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(gen(1000))
}

func gen(n uint64) []uint64 {
	var r []uint64
	for i := uint64(2); i <= n; i++ {
		if emirp(i) {
			r = append(r, i)
		}
	}
	return r
}

// http://oeis.org/A006567
func emirp(n uint64) bool {
	m := rev(n)
	if n == m {
		return false
	}

	x := new(big.Int)
	y := new(big.Int)
	x.SetUint64(n)
	y.SetUint64(m)
	return x.ProbablyPrime(2) && y.ProbablyPrime(2)
}

func rev(n uint64) uint64 {
	r := uint64(0)
	for ; n != 0; n /= 10 {
		r = (r * 10) + (n % 10)
	}
	return r
}

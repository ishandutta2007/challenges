/*

Factorial digit sum

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

*/

package main

import (
	"flag"
	"fmt"
	"math/big"
	"strconv"
)

func main() {
	N := int64(100)
	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.ParseInt(flag.Arg(0), 0, 64)
	}
	fmt.Println(factds(N))
}

func fact(n int64) *big.Int {
	if n <= 1 {
		return big.NewInt(1)
	}

	r := big.NewInt(1)
	for i := int64(2); i <= n; i++ {
		r.Mul(r, big.NewInt(i))
	}
	return r
}

func factds(n int64) uint64 {
	v := fact(n)
	s := v.String()
	r := uint64(0)
	for i := range s {
		r += uint64(s[i]) - '0'
	}
	return r
}

/*

Self powers

The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

*/

package main

import (
	"flag"
	"fmt"
	"math/big"
	"strconv"
)

func main() {
	N := int64(1000)
	D := 10
	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.ParseInt(flag.Arg(0), 0, 64)
	}
	if flag.NArg() >= 2 {
		D, _ = strconv.Atoi(flag.Arg(1))
	}

	r := sum(N)
	s := r.String()
	if D >= 0 && len(s) > D {
		s = s[len(s)-D:]
	}
	fmt.Println(s)
}

func sum(n int64) *big.Int {
	r := new(big.Int)
	for i := int64(1); i <= n; i++ {
		x := big.NewInt(i)
		p := big.NewInt(i)
		x.Exp(x, p, nil)
		r.Add(r, x)
	}
	return r
}

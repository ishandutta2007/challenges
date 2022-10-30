/*

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

*/

package main

import (
	"flag"
	"fmt"
	"math/big"
	"strconv"
)

func main() {
	N := 1000
	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.Atoi(flag.Arg(0))
	}
	x := big.NewInt(2)
	y := big.NewInt(int64(N))
	z := x.Exp(x, y, nil)

	v := 0
	s := z.String()
	for i := range s {
		v += int(s[i] - '0')
	}
	fmt.Println(z)
	fmt.Println()
	fmt.Println("sum is", v)
}

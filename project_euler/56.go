/*

A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(solve(100, 100))
}

func solve(a, b int64) int {
	m := 0
	for i := int64(2); i <= a; i++ {
		x := big.NewInt(i)
		for j := int64(2); j <= b; j++ {
			y := big.NewInt(j)
			z := new(big.Int)
			z.Exp(x, y, nil)

			n := 0
			p := z.String()
			for i := range p {
				n += int(p[i] - '0')
			}
			if n > m {
				m = n
			}
		}
	}
	return m
}

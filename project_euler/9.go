/*

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

package main

import (
	"flag"
	"fmt"
	"strconv"
)

func main() {
	N := 1000
	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.Atoi(flag.Arg(0))
	}

	for a := 1; a <= N; a++ {
		for b := 1; b <= N; b++ {
			for c := 1; c <= N; c++ {
				if a*a+b*b == c*c && a+b+c == N {
					fmt.Printf("%d + %d + %d = %d\n", a, b, c, a+b+c)
					fmt.Printf("%d * %d * %d = %d\n", a, b, c, a*b*c)
					return
				}
			}
		}
	}
}

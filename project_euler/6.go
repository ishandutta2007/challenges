/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
package main

import (
	"flag"
	"fmt"
	"strconv"
)

func main() {
	N := 100
	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.Atoi(flag.Arg(0))
	}
	fmt.Printf("%d - %d = %d\n", sos(N), soq(N), sos(N)-soq(N))
}

func soq(n int) int {
	s := 0
	for i := 1; i <= n; i++ {
		s += i * i
	}
	return s
}

func sos(n int) int {
	s := 0
	for i := 1; i <= n; i++ {
		s += i
	}
	return s * s
}

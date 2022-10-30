/*

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/
package main

import (
	"flag"
	"fmt"
	"strconv"
)

func main() {
	N := 20
	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.Atoi(flag.Arg(0))
	}

	lcmv(N)
}

func brute(n int) {
	for i := 1; ; i++ {
		if isdiv(i, n) {
			fmt.Println(i)
			break
		}
	}
}

func isdiv(x, n int) bool {
	for i := 2; i <= n; i++ {
		if x%i != 0 {
			return false
		}
	}
	return true
}

func lcmv(n int) {
	m := 1
	for i := 2; i <= n; i++ {
		m = lcm(m, i)
	}
	fmt.Println(m)
}

func gcd(a, b int) int {
	for a != b {
		if a > b {
			a -= b
		} else {
			b -= a
		}
	}

	return a
}

func lcm(a, b int) int {
	return abs(a*b) / gcd(a, b)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

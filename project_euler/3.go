/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/
package main

import (
	"flag"
	"fmt"
	"strconv"
)

func main() {
	N := 600851475143
	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.Atoi(flag.Arg(0))
	}
	f := factor(N)
	m := max(f)
	fmt.Println(f, m)
}

func factor(n int) (f []int) {
	if n == 1 {
		return []int{1}
	}
	for i := 2; i <= n; i++ {
		for n%i == 0 {
			n /= i
			f = append(f, i)
		}
	}
	return
}

func max(a []int) int {
	if len(a) == 0 {
		return 0
	}
	x := a[0]
	for _, y := range a[1:] {
		if y > x {
			x = y
		}
	}
	return x
}

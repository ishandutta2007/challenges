/*

Circular primes

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

*/

package main

import (
	"flag"
	"fmt"
	"strconv"
)

func main() {
	N := int(1e6)
	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.Atoi(flag.Arg(0))
	}

	p := sieve(N)
	c := 0
loop:
	for i := range p {
		if !p[i] {
			continue
		}

		l := ilog10(i)
		for j := 1; j <= l; j++ {
			r := rotr(i, j)
			if !p[r] {
				continue loop
			}
		}
		c++
	}
	fmt.Println(c)
}

func rotr(n, d int) int {
	if n < 10 {
		return n
	}

	l := ilog10(n)
	p := ipow10(l)
	d %= (l + 1)
	for i := 0; i < d; i++ {
		n = n/10 + (n%10)*p
	}
	return n
}

func ipow10(n int) int {
	p := 1
	for i := 0; i < n; i++ {
		p *= 10
	}
	return p
}

func ilog10(n int) int {
	if n == 0 {
		return 0
	}

	l := 0
	for ; n >= 10; n /= 10 {
		l++
	}
	return l
}

func sieve(n int) []bool {
	p := make([]bool, n+1)
	for i := 2; i < len(p); i++ {
		p[i] = true
	}

	for x := 2; x*x <= n; x++ {
		if p[x] {
			for i := x * 2; i < n+1; i += x {
				p[i] = false
			}
		}
	}

	return p
}

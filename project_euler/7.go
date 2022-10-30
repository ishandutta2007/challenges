/*

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/
package main

import (
	"flag"
	"fmt"
	"math"
	"strconv"
)

func main() {
	N := int(1e6)
	M := 10001

	flag.Parse()
	switch n := flag.NArg(); {
	case n >= 2:
		N, _ = strconv.Atoi(flag.Arg(1))
		fallthrough
	case n >= 1:
		M, _ = strconv.Atoi(flag.Arg(0))
	}

	prime := make([]bool, N+1)
	atkin(prime)
	m := 0
	for i := range prime {
		if prime[i] {
			if m++; m == M {
				fmt.Printf("prime #%d is %d\n", M, i)
				return
			}
		}
	}
	fmt.Printf("prime #%d is not within %d\n", M, N)
}

func atkin(prime []bool) {
	limit := len(prime) - 1
	switch limit {
	case 0, 1:
		return
	case 2:
		fmt.Println("2")
		return
	case 3:
		fmt.Println("2")
		fmt.Println("3")
		return
	}

	for i := 5; i <= limit; i++ {
		prime[i] = false
	}

	l := int(math.Sqrt(float64(limit)))
	for x := 1; x <= l; x++ {
		for y := 1; y <= l; y++ {
			n := 4*x*x + y*y
			m := n % 12
			if n <= limit && (m == 1 || m == 5) {
				prime[n] = !prime[n]
			}

			n = 3*x*x + y*y
			m = n % 12
			if n <= limit && m == 7 {
				prime[n] = !prime[n]
			}

			n = 3*x*x - y*y
			m = n % 12
			if x > y && n <= limit && m == 11 {
				prime[n] = !prime[n]
			}
		}
	}

	for n := 5; n <= l; n++ {
		if prime[n] {
			t := n * n
			for i, k := 2, t; k < limit; k, i = t*i, i+1 {
				prime[k] = false
			}
		}
	}

	prime[2] = true
	prime[3] = true
}

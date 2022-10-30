/*

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/
package main

import (
	"flag"
	"fmt"
	"math"
	"strconv"
)

func main() {
	N := int(2000000)

	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.Atoi(flag.Arg(0))
	}

	prime := make([]bool, N+1)
	atkin(prime)
	s := uint64(0)
	for i := range prime {
		if prime[i] && i != N {
			s += uint64(i)
		}
	}
	fmt.Printf("sum of primes less than %d is %d\n", N, s)
}

func atkin(prime []bool) {
	limit := len(prime) - 1
	switch limit {
	case 0, 1:
		return
	case 2:
		prime[2] = true
		return
	case 3:
		prime[2] = true
		prime[3] = true
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

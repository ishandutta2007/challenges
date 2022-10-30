/*

The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

     1: 1
     3: 1,3
     6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28

We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?

*/
package main

import (
	"flag"
	"fmt"
	"strconv"
)

func main() {
	N := 500
	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.Atoi(flag.Arg(0))
	}

	brute2(N)
}

// brute1 just figures out all the divisors
// in a triangular number N and then see if it is greater
// than 500, it is too slow due to the fact that the divisor
// function is too slow since it tries all values up until N
func brute1(n int) {
	m := 0
	for i := uint64(1); ; i++ {
		t := triangle(i)
		d := divisors(t)
		if len(d) > m {
			m = len(d)
			fmt.Println(i, t, m)
			if m > n {
				break
			}
		}
	}
}

// brute2 is much faster since the way we calculate the divisor
// is we get the prime decomposition of the triangular number N
// and then take all the exponents and multiply them together
// that will give the number of how many divisors a number has
func brute2(n int) {
	m := 0
	for i := uint64(1); ; i++ {
		t := triangle(i)
		f := factor(t)
		d := fdivisor(f)
		if d > m {
			m = d
			fmt.Println(i, t, m)
			if m > n {
				break
			}
		}
	}
}

func triangle(n uint64) uint64 {
	return n * (n + 1) / 2
}

func divisors(n uint64) (d []uint64) {
	for i := uint64(1); i <= n; i++ {
		if n%i == 0 {
			d = append(d, i)
		}
	}
	return
}

func factor(n uint64) (f []uint64) {
	if n == 1 {
		return []uint64{1}
	}
	for i := uint64(2); i <= n; i++ {
		for n%i == 0 {
			n /= i
			f = append(f, i)
		}
	}
	return
}

func fdivisor(f []uint64) int {
	d := 1
	for i := 0; i < len(f); {
		n := f[i]
		h := 1
		for j := i; j < len(f) && n == f[j]; j++ {
			h++
			i++
		}
		d *= h
	}
	return d
}

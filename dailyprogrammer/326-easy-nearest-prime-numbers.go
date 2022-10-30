/*

Description

A prime number is any integer greater than 1 which can only be evenly divided by 1 or itself. For this challenge, you will output two numbers: the nearest prime below the input, and the nearest prime above it.
Input Description

The input will be a number on each line, called n.
Output Description

The format of the output will be:

    p1 < n < p2

where p1 is the smaller prime, p2 is the larger prime and n is the input.

If n already is a prime, the output will be:

    n is prime.

Challenge Input

270
541
993
649

Challenge Output

269 < 270 < 271
541 is prime.
991 < 993 < 997
647 < 649 < 653

Bonus

Write the program to work for numbers with big gaps to the nearest nearestprimes. This requires a clever solution and cannot be efficiently bruteforced.

2010741
1425172824437700148

Credit

This challenge was suggested by user /u/tulanir, many thanks! If you have an idea for a challenge please share it on r/dailyprogrammer_ideas and there's a good chance we'll use it.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	assert(nearestprimes(xint("270")) == "269 < 270 < 271")
	assert(nearestprimes(xint("541")) == "541 is prime.")
	assert(nearestprimes(xint("993")) == "991 < 993 < 997")
	assert(nearestprimes(xint("649")) == "647 < 649 < 653")
	assert(nearestprimes(xint("2010741")) == "2010733 < 2010741 < 2010881")
	assert(nearestprimes(xint("1425172824437700148")) == "1425172824437699411 < 1425172824437700148 < 1425172824437700887")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func nearestprimes(n *big.Int) string {
	var (
		prob = 100
		one  = big.NewInt(1)
	)

	if n.ProbablyPrime(prob) {
		return fmt.Sprintf("%v is prime.", n)
	}

	x := new(big.Int)
	y := new(big.Int)
	x.Set(n)
	y.Set(n)

	for x.Cmp(one) >= 0 {
		x.Sub(x, one)
		if x.ProbablyPrime(prob) {
			break
		}
	}

	for {
		y.Add(y, one)
		if y.ProbablyPrime(prob) {
			break
		}
	}

	var r string
	if x.Cmp(one) > 0 {
		r = fmt.Sprintf("%v < ", x)
	}
	r += fmt.Sprintf("%v < %v", n, y)

	return r
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 10)
	return x
}

/*

You are playing a game called Martingale. The rules of the game are as follows:

1.  At the beginning of the game, you are given N as input.
2.  Set V=N, and set X=1
3.  Flip a fair coin.
3a.   If the coin lands on heads: Increase V by X, and then set X=1
3b.   If the coin lands on tails: Decrease V by X, and then set X=2X
4.  If V less than or equal to 0 or V greater than or equal to 2N
4a.   End the game.
5.  Proceed to step 3.
Given the initial value N, what is the expected number of turns (coin flips) you will play before ending the game?

Input:

Input consists of a single integer, N (with 1≤N≤1,000,000), the initial input to the game.

Output:

A single decimal number, containing the expected number of turns you will play this game before it ends.
Your output will be accepted if it is within 10^-6 absolute or relative error.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	test(1, 1)
	test(3, 3.9609375)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r float64) {
	p := expected(n, 1e7)
	fmt.Println(p, r)
}

func expected(n, t int) float64 {
	c := 0
	for i := 0; i < t; i++ {
		c += sim(n)
	}
	return float64(c) / float64(t)
}

func sim(n int) int {
	c := 0
	v := n
	x := 1
	for {
		switch rand.Intn(2) {
		case 0:
			v, x = v+x, 1
		case 1:
			v, x = v-x, 2*x
		}

		if c++; v <= 0 || v >= 2*n {
			break
		}
	}
	return c
}

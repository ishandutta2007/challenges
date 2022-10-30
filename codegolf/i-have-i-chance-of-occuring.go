/*

Design a random number generator where the i th number has i% chance of occurring for all 0 < i < 14. 0 should have exactly 9% chance of occurring.
The seed for the generator should be the system time. You cannot use a pre-defined function for random number generation.

Basically 1 has 1% chance of occurring, 2 has 2% chance and so on up to 13 having 13% chance of occurring. This is code-golf, so the shortest code wins.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i <= 14; i++ {
		test(i)
	}
}

func test(n int) {
	t := 10000000
	c := 0
	for i := 0; i < t; i++ {
		if gen(n) == n {
			c++
		}
	}
	fmt.Printf("%f\n", float64(c)/float64(t)*100)
}

func gen(n int) int {
	p := 0.09
	if n != 0 {
		p = float64(n) / 100
	}
	if rand.Float64() <= p {
		return n
	}
	return rand.Intn(n+1) + n + 1
}

/*

Challenge

Task

Given a number N, output 2 NxN squares; each line of each square is a random permutation of [0, N); the squares are separated by a newline
Rules

    Produce a randomised list of length N, separated by space
    Repeat this N*2 times
    Separate each output with a newline, with 2 newlines at the midpoint
    The value of n must be "obvious", you can get it via stdin; argument; whatever, but there must be a distinct value somewhere, so the value of n can't just be scattered across your program.

Example

Given n = 4, the output could be:

1 2 0 3
2 3 1 0
2 0 3 1
2 0 3 1

0 3 2 1
3 1 0 2
0 1 3 2
0 2 1 3

Lowest number of bytes wins

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	gen(4)
	gen(8)
	gen(10)
}

func gen(n int) {
	for i := 0; i < 2; i++ {
		for j := 0; j < n; j++ {
			fmt.Println(rand.Perm(n))
		}
		fmt.Println()
	}
}

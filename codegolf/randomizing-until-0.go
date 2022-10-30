/*

Challenge

Sandbox post

Given a positive integer (K) Output a uniformly-random integer (Y) between [0, K).

If Y > 0 Assume K = Y and repeat the process until Y = 0.

Rules

    Input must be printed at first
    Output format as you wish
    Your program must finish.
    0 must be the final output, Optionally an empty line instead 0

*/

package main

import (
	"crypto/rand"
	"fmt"
	"math/big"
)

func main() {
	randomize(10000)
}

func randomize(k int64) {
	z := big.NewInt(0)
	for {
		y, _ := rand.Int(rand.Reader, big.NewInt(k))
		fmt.Println(y)
		if y.Cmp(z) == 0 {
			break
		}
	}
}

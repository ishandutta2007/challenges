/*

Because there are not enough simple code-golf challenges:

Create an optionally unnamed program or function that, given (by any means) an integer 1 ≤ N ≤ 10000, outputs your language's True value with a pseudo-random probability of 1/N, False otherwise.

Please note that the requirement for naming has been removed. Feel free to edit answers and scores accordingly.

Some languages use 1 (or -1) and 0 for True and False, that is fine too.

Example:

Example input tests:

4 -> True
4 -> False
4 -> False
4 -> False
4 -> False
4 -> True
4 -> False
4 -> False

I.e. given 4; it returns True with a 25% chance and False with a 75% chance.

*/

package main

import (
	"crypto/rand"
	"fmt"
	"math/big"
)

func main() {
	test(4)
	test(8)
	test(10)
	test(50)
	test(1000)
}

func test(n uint64) {
	t := uint64(0)
	for i := uint64(0); i < n; i++ {
		if gen(n) {
			t++
		}
	}
	fmt.Printf("%d: %f%%\n", n, float64(t)/float64(n)*100)
}

func gen(n uint64) bool {
	x := new(big.Int)
	x.SetUint64(n)
	y, _ := rand.Int(rand.Reader, x)
	return y.Uint64() == 0
}

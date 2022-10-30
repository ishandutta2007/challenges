/*

Write a program which plays Russian Roulette!

If the program is started,

    there should be a 5 in 6 chance of it ending normally after printing "I survived!"
    there should be a 1 in 6 chance of the program crashing. (segmentation fault, etc.)

No input, and no other outputs are allowed.

The randomness must be fair: it must have a uniform probability distribution. This means an uninitialized variable (or a RNG without seed) MOD 6 will not be sufficient.

If the solution works with only one dedicated operating system / platform, you will receive a 6 byte penalty to the score.

Shortest code wins, not sooner than 10 days after first valid answer.

*/

package main

import (
	"fmt"
	"math/rand"
	"os"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	roulette(6)
}

func roulette(n int) {
	v := rand.Intn(n)
	if v == 0 {
		fmt.Println("I survived!")
	} else {
		os.Exit(v)
	}
}

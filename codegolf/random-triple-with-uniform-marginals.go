/*

Output a random triple (x,y,z)

of real numbers such that

    x+y+z=32

Each of x,y,z, taken alone, is uniformly distributed from 0 to 1.

Please explain in your answer what distribution your code produces and why it meets these conditions.
In particular, please include a demonstration that with many samples produced by running your code many times, the distribution of each variable alone is approximately uniform.

Allowances for precision

Since computers can't produce actual real numbers, you can approximate them by outputting any of:

    Floats
    Decimals
    Rationals

I've tried to make the rules here as friendly as possible.

Your outputs need to be accurate within ±10−3, that is 3 decimal digits. That means you can imagine that each real-number output from your true distribution has been fudged by at most ±10−3 in any way. It's fine if this makes x+y+z be a bit off from 32.

You may output rationals as (numerator, denominator) pairs of integers or similar. You may also choose to output just one denominator that applies to all three values, that is, output a,b,c
and d to represent ad,bd,cd. Rationals don't have to be in reduced form.

Randomness

You can assume any standard PRNG is in fact random. For instance, if it outputs random floats from 0 to 1, you can assume these are uniformly random reals that are independent from each other, and not worry about any endpoint issues.
It's also fine if your code fails in a probability-zero event.

To decide whether a pseudo-random source such as time or memory contents is sufficiently random, consider an empirical test where your code is run many times in sequence to check if the randomness varies sufficiently between runs.
You may have these runs be done within your language such as in a loop, or by repeatedly calling the code from outside like with a shell command. You may not assume any intentional time delay or other actions taken between runs.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 50; i++ {
		x, y, z := triple()
		fmt.Println(x, y, z, x+y+z)
	}
}

func triple() (x, y, z float64) {
	x = rand.Float64()
	y = x - 0.5
	if x < 0.5 {
		y = x + 0.5
	}
	z = 1.5 - (x + y)
	return
}

/*

The Objective

Build a random number generator whose range is [0,1)∩Q.

This is, build a random number generator that can produce any value that's:

    at least 0;
	not 1 or greater;
	and expressible as the ratio of two integers.

What's the fuss?

This RNG is weird. Its range is nowhere connected, but is dense in the interval!
The probability mass function

We define an ordering for all values that the RNG can return, such that each return value x
can be associated with an index i. Then, the probability of returning xi should be P(xi)=(12)i. Since
∑i=1∞(1/2)^i=1,
this yields a total probability of 1,

where the numbers earlier in the ordering are significantly more likely than numbers later in the ordering.

The ordering is:

    Start with the first value, 01.

Increment the numerator.

If the numerator equals the denominator, then:

    reset the numerator to 0;

    and

    increment the denominator.

Add the value to the ordering if it's not equivalent to a value already in the ordering.

    For example, 24 is constructed after 12, so it's not added to the ordering.
    Go back to Step (2).

For example, the first few values and their corresponding probabilities are:

1 2 3 4 5 6 7 8 9 10
0/1 1/2 1/3 2/3 1/4 3/4 1/5 2/5 3/5 4/5
1/2 1/4 1/8 1/16 1/32 1/64 1/128 1/256 1/512 1/1024

Rules

    There is no input. The RNG outputs a number upon invocation.

    You must use rational number arithmetic. In particular, X must be represented as a rational number. If your language doesn't natively support it, use a pair of integers. For example, in Haskell, Rational is a valid type.

    As long as the numerator and the denominator are distinguishable, the output format doesn't matter.

    As this is a code-golf, the shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"math/big"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 100; i++ {
		fmt.Println(randrat())
	}
}

func randrat() *big.Rat {
	d := rand.Int63()
	n := rand.Int63n(d)
	x := new(big.Rat)
	x.SetFrac64(n, d)
	return x
}

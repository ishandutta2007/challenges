/*

Task

Given a positive integer n less than 2^30 specified as input in any way you choose, your code should output a random integer between 0 and n, inclusive. The number you generate should be chosen uniformly at random. That is each value from 0 to n must occur with equal probability (see Rules and Caveats).

Rules and Caveats

Your code can assume that any random number generator built into your language or standard library that claims to be uniformly random is in fact uniform. That is you don't have to worry about the quality of the random source you are using. However,

    You do have to establish that if the random source you are using is uniform then your code correctly outputs a uniform random integer from 0 to n.
    Any arguments when calling a built in or library random function must be constant. That is they must be completely independent of the input value.
    Your code may terminate with probability 1 rather than being guaranteed to terminate.

Notes

    randInt(0,n) is not valid as it takes the input as an argument to a builtin or library function.
    rand()%n will not give a uniform random number in general. As an example given by betseg, if intmax == 15 and n = 10, then you will be much more likely to get 0-5 than 6-10.
    floor(randomfloat()*(n+1)) will also not give a uniform random number in general due to the finite number of different possible floating point values between 0 and 1.

*/

package main

import (
	"crypto/rand"
	"fmt"
	"math"
	"math/big"
)

func main() {
	for i := int64(1); i < math.MaxInt32; i++ {
		fmt.Println(i, randn(i))
	}
}

func randn(n int64) int64 {
	m := big.NewInt(n)
	x, err := rand.Int(rand.Reader, m)
	if err != nil {
		panic(err)
	}
	return x.Int64()
}

/*

A number is a Mersenne Prime if it is both prime and can be written in the form 2n-1, where n is a positive integer.

Your task is to, given any positive integer, determine whether or not it is a Mersenne prime.
You may submit either a function which returns a truthy/falsy value, or a full program which performs IO.

Rules:

    As this is code-golf, you should aim to do this in the shortest byte count possible. Builtins are allowed.
    Standard golfing loopholes apply - you cannot read the Mersenne primes from external files, or hardcode them into your program.
    Your program should work for values within your language's standard integer size.

Test Cases

For reference, a list of (known) Mersenne Primes can be found here. Some handy test cases are:

2  -> False
1  -> False
20 -> False
51 -> False
63 -> False

3    -> True
31   -> True
8191 -> True

Merry Christmas, everybody! Have a great holiday, whatever you celebrate :)

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	assert(mersenne(2) == false)
	assert(mersenne(1) == false)
	assert(mersenne(20) == false)
	assert(mersenne(51) == false)
	assert(mersenne(63) == false)
	assert(mersenne(2147483648) == false)

	assert(mersenne(3) == true)
	assert(mersenne(31) == true)
	assert(mersenne(8191) == true)
	assert(mersenne(2147483647) == true)
	assert(mersenne(2305843009213693951) == true)

	for i := int64(0); i < 1e6; i++ {
		if mersenne(i) {
			fmt.Println(i)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mersenne(n int64) bool {
	for i := int64(0); i < 64; i++ {
		p := int64(1<<i) - 1
		if p > n {
			break
		}

		if p == n {
			x := big.NewInt(n)
			return x.ProbablyPrime(2)
		}
	}
	return false
}

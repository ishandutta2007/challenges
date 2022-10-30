/*

As you may know, the typical binary floating point numbers in a computer language are quite different than the typical integer numbers in a computer language.
Floating point numbers can represent a much larger range, and can represent fractional amounts, however there is a trade-off that is frequently elided.

The distance between integers is constant, and in fact the value of that constant is one. The distance between floating point numbers, however, is variable, and increases the further one travels down the number line, away from the origin at 0.
At some point, that distance is so large that the floating point numbers start skipping over integers, and many integers that are technically less than the maximum value of the floating point numbers, cannot actually be represented by floating point numbers.

The challenge:

Write a program that when given the number n, will print out the first n positive integers that cannot be represented by a floating point number in your language of choice.

"First n positive integers" means, lowest in value, closest to the origin, and distinct from each other.

Infinite precision floating point numbers are not allowed.

It doesn't matter whether you choose 32 bit floats, 64 bits floats, or some other type of float, as long as it is a non-infinite precision floating point number in your language of choice, on your machine of choice.

Order of numbers does not matter

This is Code Goﬂ. Smallest number of characters wins.

Good luck and have fun

Example:

In Rust, using 32 bit floating point builtin type 'f32':

n=4, result = [16777217,16777219,16777221,16777223]
(updated - 1 order doesnt matter - 2 Golf->Goﬂ)

*/

package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	fmt.Println(gen(4, 32))
	fmt.Println(gen(10, 64))
}

func gen(n, b int) []int64 {
	r := []int64{}

	i := int64(0)
	switch b {
	case 32:
		i = 1 << 24
	case 64:
		i = 1 << 53
	default:
		panic("unsupported floating point bit size")
	}

	for x := new(big.Float); i < math.MaxInt64; i++ {
		if len(r) >= n {
			break
		}
		x.SetInt64(i)

		var acc big.Accuracy
		if b == 32 {
			_, acc = x.Float32()
		} else {
			_, acc = x.Float64()
		}

		if acc != big.Exact {
			r = append(r, i)
		}
	}

	return r
}

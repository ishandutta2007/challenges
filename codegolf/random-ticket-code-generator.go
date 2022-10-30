/*

A lottery company wants to generate a random lottery ticket number of length 10 characters.

Write a code in any language to create such a number in which every digit comes only once for example 9354716208 in this number all integers from 0 to 9 comes only once. This number should be a random number.

    The generated number should be shown on screen.
    It must be able to generate all permutations of all allowable characters.
    The code is required to be as small as possible (in bytes).

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 10; i++ {
		fmt.Printf("%010d\n", gen())
	}
}

func gen() uint64 {
	r := uint64(0)
	p := rand.Perm(10)
	for _, v := range p {
		r = (r * 10) + uint64(v)
	}
	return r
}

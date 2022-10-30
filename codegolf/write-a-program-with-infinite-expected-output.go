/*

Write a program that halts producing a random finite numerical output with probability 1. The expected value of the outputs of the program must be infinite.

For physical limits, you can assume your language and related functions use infinite precision numbers. E.g. for languages with random function providing range [0,1), it returns a real in [0,1).

(Anyway I need to choose from 1/rnd and while(rnd)print(1))

Inspired by St. Petersburg paradox.

Shortest code wins. Would be quite small for lots of language though.

There are two easy-seen ways to do this, both are accepted given the question: (in Javascript)

_=>1/Math.random() // ∫₀¹1/xdx=∞
_=>{c='1';while(Math.random()<.5)c+='1';return c} // Not golfed to easier get understood for other language user, at least I try to
    // 1/2+11/4+111/8+1111/16+...=∞

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(1 / rand.Float64())
}

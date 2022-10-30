/*

You are to write a program which generates random integers between 0 and 99 inclusive, outputting each integer in turn, until 0 is generated.
You may choose which single-order random distribution (uniform, binomial, Poisson etc.) you use so long as each integer has a non-zero chance of being generated and is chosen independently.
The output should always end with 0. As each integer must be chosen independently, the output cannot be some permutation of the integers {0,1,2,...,99} trimmed to end with 0.

You may follow another method to accomplish the same task, so long as the result is identical to the described method here (for example: you may generate a number K
geometrically distributed with parameter 1/99, then output K independent numbers with a uniform distribution on the set {1,2,...,99}, then output a 0).

The integers may be separated by any non-digit, non-empty separator (e.g. newlines, spaces etc.), and may be output in any consistent base. You may output in any convenient method or format.

This is code-golf so the shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	gen()
}

func gen() {
	rand.Seed(time.Now().UnixNano())
	for {
		v := rand.Intn(100)
		fmt.Println(v)
		if v == 0 {
			break
		}
	}
}

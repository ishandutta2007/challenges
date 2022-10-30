/*

Given an input string S, print S followed by a non-empty separator in the following way:

    Step 1: S has a 1/2 chance of being printed, and a 1/2 chance for the program to terminate.

    Step 2: S has a 2/3 chance of being printed, and a 1/3 chance for the program to terminate.

    Step 3: S has a 3/4 chance of being printed, and a 1/4 chance for the program to terminate.

    …

    Step n: S has a n/(n+1) chance of being printed, and a 1/(n+1) chance for the program to terminate.

Notes

    The input string will only consist of characters that are acceptable in your language's string type.

    Any non-empty separator can be used, as long as it is always the same. It is expected that the separator is printed after the last print of S before the program terminates.

    The program has a 1/2 chance of terminating before printing anything.

    A trailing new line is acceptable.

    Your answer must make a genuine attempt at respecting the probabilities described. Obviously, when n is big this will be less and less true. A proper explanation of how probabilities are computed in your answer (and why they respect the specs, disregarding pseudo-randomness and big numbers problems) is sufficient.

Scoring

This is code-golf, so the shortest answer in bytes wins.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	sim("Hello World")
}

func sim(s string) {
	for n := 2.0; ; n++ {
		fmt.Println(s)
		if rand.Float64() < 1/n {
			break
		}
	}
}

/*

Your task is to create a program or function which randomly errors. Specifically, there must be a nonzero probability of erroring, but also a nonzero probability of running without error.

An error is anything that causes a program to terminate abnormally, such as dividing by zero or using an uninitialized variable.
This also includes runtime errors, syntax errors and errors while compiling. Statements which manually throw an error, such as JavaScript's throw are allowed.

This program doesn't need to do anything if it doesn't error, other than exiting gracefully.

This is code-golf, so shortest answer per language wins.

Note: For this challenge, "randomly" follows the current consensus (so no using undefined behavior or uninitialized memory for randomness),
and the program must be capable of producing both outputs if run or compiled multiple times (so a random number with the same seed is not valid)

*/

package main

import (
	"math/rand"
	"os"
	"time"
)

func main() {
	exit(0)
}

func exit(status int) {
	rand.Seed(time.Now().UnixNano())

	if rand.Intn(10) == 0 {
		status++
	}
	os.Exit(status)
}

/*

Your challenge is to golf a program that mimics a data transmission stream. Your program should read input from stdin and output it directly to stdout. To make the problem more interesting, the output stream is 'faulty', and must meet several requirements:

There should be a 10% chance that each character is shifted +1 ascii code (ex 'a' becomes 'b', '9' becomes ':'), etc.
The input and output should only cover printable ascii values ('!' through '~', decimal 33 through decimal 126, inclusive). If the random +1 occurs on a '~' (decimal 126), a '!' (decimal 33) should be output instead.
If three characters are randomly shifted in a row, the program should output "ERROR CODE 4625: UNRECOVERABLE ERROR, PLEASE CONTACT YOUR SYSTEM ADMINISTRATOR" (trailing newline optional) and halt execution.
To simplify the problem, here are a few other criteria:

You can assume the input will always be valid; that is, it will only contain values '!' through '~'.
The program should continue on until three characters are randomly shifted in a row; it's safe to assume that EOF will never occur.
The randomness must differ across runs; if your random number generator needs to be seeded to get an unique result each run, then your code needs to seed it.
You must write a program, not a function.
You must take input from stdin and write output to stdout.
You may not use any external libraries or resources.
Your code must have a freely available and working intrepreter or compiler.
Standard code-golf rules apply. Winner is whoever has the shortest program posted two weeks from now (Thursday, Feb 20th, 2014).

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	sim()
}

func sim() {
	for c := 0; c < 3; {
		r := char()
		if rand.Intn(10) == 1 {
			r, c = inc(r), c+1
		} else {
			c = 0
		}
		fmt.Printf("%c", r)
	}

	fmt.Println()
	fmt.Println("ERROR CODE 4625: UNRECOVERABLE ERROR, PLEASE CONTACT YOUR SYSTEM ADMINISTRATOR")
}

func char() rune {
	return rune(32 + rand.Intn(94))
}

func inc(r rune) rune {
	if r++; r > 126 {
		r = 33
	}
	return r
}

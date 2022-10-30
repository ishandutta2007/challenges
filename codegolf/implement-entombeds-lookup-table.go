/*

Background

Entombed is an Atari 2600 game released in 1982, with the goal of navigating through a continuous mirrored maze as it scrolls upwards.
In recent times, the game has been subject to research — despite the strict hardware limitations of the Atari 2600, it somehow manages to create solvable mazes every time.
By disassembling the game's ROM, researchers discovered that this is done with the help of a mysterious lookup table.

When a tile X is to be generated, the game first looks at the states of 5 tiles A, B, C, D, and E which are around it:

xCDEABXx

These five values then index into the following 32-byte lookup table to determine what should appear at X — a wall, an empty space, or either a wall or an empty space, chosen at random:

A B C D E    X
0 0 0 0 0    1
0 0 0 0 1    1
0 0 0 1 0    1
0 0 0 1 1    R
0 0 1 0 0    0
0 0 1 0 1    0
0 0 1 1 0    R
0 0 1 1 1    R
0 1 0 0 0    1
0 1 0 0 1    1
0 1 0 1 0    1
0 1 0 1 1    1
0 1 1 0 0    R
0 1 1 0 1    0
0 1 1 1 0    0
0 1 1 1 1    0
1 0 0 0 0    1
1 0 0 0 1    1
1 0 0 1 0    1
1 0 0 1 1    R
1 0 1 0 0    0
1 0 1 0 1    0
1 0 1 1 0    0
1 0 1 1 1    0
1 1 0 0 0    R
1 1 0 0 1    0
1 1 0 1 0    1
1 1 0 1 1    R
1 1 1 0 0    R
1 1 1 0 1    0
1 1 1 1 0    0
1 1 1 1 1    0

Here R represents a value to be chosen randomly.
Task

Given values for A, B, C, D, and E as input, your program or function should output the correct value for X (either 0 or 1, depending on which row of the table the input corresponds to).
However, if the input corresponds to a row in the table with an X value of R, your program should output either 0 or 1 uniformly randomly.

Rules

    This is code-golf, so shortest answer in bytes wins.
    Your input can be given in any reasonable format, e.g. a list of values, a string with the values in it, an integer in the range [0..31], etc.
    When receiving input that corresponds to an X value of R in the table, your output has to be non-deterministic.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 32; i++ {
		fmt.Println(i, gen(i))
	}
}

func gen(n int) int {
	const bits = "111R00RR1111R000111R0000R01RR000"

	var r int
	switch p := bits[n&(len(bits)-1)]; p {
	case '0', '1':
		r = int(p - '0')
	case 'R':
		r = rand.Intn(2)
	}
	return r
}

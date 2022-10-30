/*

This challenge is loosely inspired by the unimplemented esolang Pada.

Consider an array of 8 bits, all initialised to zero. We'll introduce a very minimalistic instruction set to print arbitrary strings. There are two instructions, both of which take a parameter N which is the index of a bit:

    t N for toggle: This changes the value of bit N.
    p N for print: This interprets all 8 bits as a byte, starting from bit N and wrapping around the end. The character corresponding to this byte is printed to STDOUT.

Let's look an example. We want to print :=. Naively we achieve this as follows (0-based bit indices):

t 2    [0 0 1 0 0 0 0 0]
t 3    [0 0 1 1 0 0 0 0]
t 4    [0 0 1 1 1 0 0 0]
t 6    [0 0 1 1 1 0 1 0]
p 0    [0 0 1 1 1 0 1 0] == 58 == ':'
t 5    [0 0 1 1 1 1 1 0]
t 6    [0 0 1 1 1 1 0 0]
t 7    [0 0 1 1 1 1 0 1]
p 0    [0 0 1 1 1 1 0 1] == 61 == '='

But instead, we can make use of the cyclic feature of p and save two instructions:

t 2    [0 0 1 0 0 0 0 0]
t 3    [0 0 1 1 0 0 0 0]
t 4    [0 0 1 1 1 0 0 0]
t 6    [0 0 1 1 1 0 1 0]
p 0    [0 0 1 1 1 0 1 0] == 58 == ':'
t 1    [0 1 1 1 1 0 1 0]
p 7    [0 1 1 1 1 0 1 0] == [0 0 1 1 1 1 0 1] == 61 == '='
                      ^

So p 7 simply starts reading the byte value from the last bit instead of the first.
The Challenge

Given a non-empty string of printable ASCII characters (0x20 to 0x7E, inclusive), produce an optimal list of instructions (one line per instruction) to print that string with the above system. If there are multiple optimal solutions (which will almost always be the case), generate only one of them.

You may choose between 0-based and 1-based indexing for the bits, but please state your choice.

You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument and outputting the result via STDOUT (or closest alternative), function return value or function (out) parameter. If you don't print the result to STDOUT, it should still be a single newline-separated string.

This is code golf, so the shortest answer (in bytes) wins.
Test Cases

Each test case is a single line containing the input string, followed by the optimal number of instructions, followed by one possible solution.

You should not output the instruction count in your solution - this is only included here so you can check the correctness of your code if it prints a different instruction list.

?
7 instructions
t 2
t 3
t 4
t 5
t 6
t 7
p 0

:=
7 instructions
t 2
t 3
t 4
t 6
p 0
t 1
p 7

0123456789
26 instructions
t 2
t 3
p 0
t 7
p 0
t 6
t 7
p 0
t 7
p 0
t 5
t 6
t 7
p 0
t 7
p 0
t 6
t 7
p 0
t 7
p 0
t 2
t 3
p 3
t 2
p 3

9876543210
28 instructions
t 2
t 3
t 4
t 7
p 0
t 7
p 0
t 0
t 7
p 5
t 4
p 5
t 0
t 5
p 0
t 7
p 0
t 5
t 6
t 7
p 0
t 7
p 0
t 6
t 7
p 0
t 7
p 0

Hello, World!
39 instructions
t 1
t 4
p 0
t 3
t 7
p 2
t 1
t 6
p 2
p 2
t 0
t 1
p 2
t 0
t 1
t 3
p 2
t 6
t 7
p 2
t 0
t 2
t 6
t 7
p 1
t 0
t 1
t 5
p 0
t 2
t 7
p 3
t 2
t 6
p 0
t 4
p 0
t 1
p 3

The quick brown fox jumps over the lazy dog.
150 instructions
t 1
t 3
t 5
p 0
t 1
t 2
p 1
t 1
t 3
t 7
p 0
t 1
t 5
t 7
p 0
t 1
t 3
t 7
p 0
t 5
p 0
t 3
t 4
t 5
p 0
t 4
t 6
p 0
t 4
p 0
t 1
t 4
t 6
t 7
p 0
t 1
t 6
p 0
t 3
p 0
t 0
t 5
p 4
t 0
t 7
p 0
t 1
p 1
t 3
t 5
t 6
t 7
p 0
t 1
t 5
t 6
p 0
t 4
t 7
p 0
t 1
t 2
p 3
t 5
t 6
t 7
p 2
t 1
t 2
t 6
p 0
t 0
p 7
t 0
t 7
p 5
t 3
t 4
t 6
t 7
p 0
t 6
t 7
p 0
t 1
t 3
t 6
t 7
p 0
t 1
t 4
t 5
t 6
t 7
p 0
t 4
p 4
t 6
p 0
t 1
t 6
p 4
t 5
t 6
t 7
p 0
t 1
t 3
t 5
p 0
t 1
p 1
t 1
t 3
t 7
p 0
t 1
t 5
t 7
p 0
t 1
t 4
t 5
p 0
t 1
p 3
t 3
t 7
p 1
t 1
t 5
p 0
t 1
t 3
t 4
t 7
p 0
t 1
t 5
p 0
t 4
t 6
t 7
p 0
t 4
p 0
t 1
t 4
t 7
p 0

The test cases were generated with this CJam reference implementation.

*/

package main

import (
	"fmt"
	"math/bits"
)

func main() {
	interpret([]string{
		"t 2",
		"t 3",
		"t 4",
		"t 6",
		"p 0",
		"t 5",
		"t 6",
		"t 7",
		"p 0",
	})

	interpret([]string{
		"t 2",
		"t 3",
		"t 4",
		"t 6",
		"p 0",
		"t 1",
		"p 7",
	})

	interpret([]string{
		"t 2",
		"t 3",
		"t 4",
		"t 5",
		"t 6",
		"t 7",
		"p 0",
	})

	interpret([]string{
		"t 2",
		"t 3",
		"p 0",
		"t 7",
		"p 0",
		"t 6",
		"t 7",
		"p 0",
		"t 7",
		"p 0",
		"t 5",
		"t 6",
		"t 7",
		"p 0",
		"t 7",
		"p 0",
		"t 6",
		"t 7",
		"p 0",
		"t 7",
		"p 0",
		"t 2",
		"t 3",
		"p 3",
		"t 2",
		"p 3",
	})

	interpret([]string{
		"t 2",
		"t 3",
		"t 4",
		"t 7",
		"p 0",
		"t 7",
		"p 0",
		"t 0",
		"t 7",
		"p 5",
		"t 4",
		"p 5",
		"t 0",
		"t 5",
		"p 0",
		"t 7",
		"p 0",
		"t 5",
		"t 6",
		"t 7",
		"p 0",
		"t 7",
		"p 0",
		"t 6",
		"t 7",
		"p 0",
		"t 7",
		"p 0",
	})

	interpret([]string{
		"t 1",
		"t 4",
		"p 0",
		"t 3",
		"t 7",
		"p 2",
		"t 1",
		"t 6",
		"p 2",
		"p 2",
		"t 0",
		"t 1",
		"p 2",
		"t 0",
		"t 1",
		"t 3",
		"p 2",
		"t 6",
		"t 7",
		"p 2",
		"t 0",
		"t 2",
		"t 6",
		"t 7",
		"p 1",
		"t 0",
		"t 1",
		"t 5",
		"p 0",
		"t 2",
		"t 7",
		"p 3",
		"t 2",
		"t 6",
		"p 0",
		"t 4",
		"p 0",
		"t 1",
		"p 3",
	})

	interpret([]string{
		"t 1",
		"t 3",
		"t 5",
		"p 0",
		"t 1",
		"t 2",
		"p 1",
		"t 1",
		"t 3",
		"t 7",
		"p 0",
		"t 1",
		"t 5",
		"t 7",
		"p 0",
		"t 1",
		"t 3",
		"t 7",
		"p 0",
		"t 5",
		"p 0",
		"t 3",
		"t 4",
		"t 5",
		"p 0",
		"t 4",
		"t 6",
		"p 0",
		"t 4",
		"p 0",
		"t 1",
		"t 4",
		"t 6",
		"t 7",
		"p 0",
		"t 1",
		"t 6",
		"p 0",
		"t 3",
		"p 0",
		"t 0",
		"t 5",
		"p 4",
		"t 0",
		"t 7",
		"p 0",
		"t 1",
		"p 1",
		"t 3",
		"t 5",
		"t 6",
		"t 7",
		"p 0",
		"t 1",
		"t 5",
		"t 6",
		"p 0",
		"t 4",
		"t 7",
		"p 0",
		"t 1",
		"t 2",
		"p 3",
		"t 5",
		"t 6",
		"t 7",
		"p 2",
		"t 1",
		"t 2",
		"t 6",
		"p 0",
		"t 0",
		"p 7",
		"t 0",
		"t 7",
		"p 5",
		"t 3",
		"t 4",
		"t 6",
		"t 7",
		"p 0",
		"t 6",
		"t 7",
		"p 0",
		"t 1",
		"t 3",
		"t 6",
		"t 7",
		"p 0",
		"t 1",
		"t 4",
		"t 5",
		"t 6",
		"t 7",
		"p 0",
		"t 4",
		"p 4",
		"t 6",
		"p 0",
		"t 1",
		"t 6",
		"p 4",
		"t 5",
		"t 6",
		"t 7",
		"p 0",
		"t 1",
		"t 3",
		"t 5",
		"p 0",
		"t 1",
		"p 1",
		"t 1",
		"t 3",
		"t 7",
		"p 0",
		"t 1",
		"t 5",
		"t 7",
		"p 0",
		"t 1",
		"t 4",
		"t 5",
		"p 0",
		"t 1",
		"p 3",
		"t 3",
		"t 7",
		"p 1",
		"t 1",
		"t 5",
		"p 0",
		"t 1",
		"t 3",
		"t 4",
		"t 7",
		"p 0",
		"t 1",
		"t 5",
		"p 0",
		"t 4",
		"t 6",
		"t 7",
		"p 0",
		"t 4",
		"p 0",
		"t 1",
		"t 4",
		"t 7",
		"p 0",
	})
}

func interpret(inst []string) {
	var (
		op  rune
		bit uint
		acc uint
	)
	for _, in := range inst {
		n, _ := fmt.Sscanf(in, "%c %d", &op, &bit)
		if n != 2 || bit > 7 {
			continue
		}

		switch op {
		case 't':
			acc = toggle(acc, bit)
		case 'p':
			fmt.Printf("%c", getbits(acc, bit))
		}
	}
	fmt.Println()
}

func toggle(acc, bit uint) uint {
	val := uint(1 << bit)
	return acc ^ (val | (val << 8))
}

func getbits(acc, bit uint) uint8 {
	return bits.Reverse8(uint8(acc >> bit))
}

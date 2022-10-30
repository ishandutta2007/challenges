/*

Sometimes when writing brainfuck code, you feel the need to make it longer than needed to encourage debugging. You could do it by just plopping a >< in there, but what fun is that? You'll need something longer and less NOPey to confuse anybody reading your code.

Quick introduction to Brainfuck
Brainfuck is an esoteric programming language created in 1993 by Urban Müller, and notable for its extreme minimalism. (Wikipedia)

Brainfuck is a language based on eight commands: +-><,.[]. The code is run on something like a Turing machine: an infinite tape on which values can be changed. In this challenge, we'll focus on the first four:

+    increment the value at the pointer
-    decrement the value at the pointer
>    move the pointer right
<    move the pointer left
Brainfuck NOPs
A brainfuck NOP is a sequence of brainfuck characters that, when executed from any state, leads to no change in the state. They consist of the four characters mentioned above.

The Challenge
The challenge is to write a program or function that, when executed, generates a random brainfuck NOP of the given length.

Input
You will receive as input a nonnegative even integer n. (NOPs are impossible for odd n.)

Output
You will output a random brainfuck NOP of the length n.

Rules
The definition of NOP: when the output of the program is inserted at any point in a brainfuck program, the behavior of said program must not change in any way. In other words, it must not change the state of the interpreter.
Note that for example +>-< is incorrect, since it changes the values of the two cells without changing them back. Please test your solution for these before posting.
Also note that +>-<->+< is a NOP that can't be reduced to nothing just by removing >< <> +- -+. Thus, you can't use an algorithm that just inserts these inside each other.
Every valid NOP of the length n must have a nonzero chance of appearing in the output. The distribution does not have to be uniform, though.
The brainfuck interpreter in question has a doubly infinite tape of arbitrary precision cells. That is, you can go infinitely to the both directions, and increment/decrement each cell indefinitely.
The program must finish within 1 minute for n = 100 on my machine, so no generating all possible NOPs and picking one.
If given invalid input (non-integer, negative, odd, etc.) you may do anything you'd like, including crash.
Scoring
This is code-golf, so the shortest answer in bytes wins.

Examples
Here are all valid outputs for n = 4:

++--    +-+-    +--+    --++    -+-+    -++-
>><<    ><><    ><<>    <<>>    <><>    <>><
><+-    ><-+    <>+-    <>-+
>+-<    >-+<    <+->    <-+>
+><-    -><+    +<>-    -<>+
+-><    -+><    +-<>    -+<>
Here are a few possible outputs for n = 20:

+>>->+<->-<<<->>++<<
>+>-<+<->+-<>->+<-<+
+--+-++--++-+--+-++-
>>>>>>>>>+-<<<<<<<<<

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(gen(100))
}

func gen(n int) string {
	if n&1 != 0 {
		return ""
	}

	w := new(bytes.Buffer)
	for i := 0; i < n; i += 2 {
		switch rand.Intn(2) {
		case 0:
			w.WriteString("+-")
		case 1:
			w.WriteString("><")
		}
	}
	return w.String()
}

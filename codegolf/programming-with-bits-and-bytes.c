/*

In this challenge you are going to write an interpreter for a simple language I've made up. The language is based on a single accumulator A, which is exactly one byte in length. At the start of a program, A = 0. These are the languages instructions:

!: Inversion
This instruction simply inverts every bit of the accumulator. Every zero becomes a one and every one becomes a zero. Simple!

>: Shift Right
This instruction shifts every bit in A one place to the right. The leftmost bit becomes a zero and the rightmost bit is discarded.

<: Shift Left
This instruction shifts every bit in A one place to the left. The rightmost bit becomes a zero and the leftmost bit is discarded.

@: Swap Nybbles
This instruction swaps the top four bits of A with the bottom four bits. For example, If A is 01101010 and you execute @, A will be 10100110:

 ____________________
 |                  |
0110 1010    1010 0110
      |_______|
That's all the instructions! Simple, right?

Rules
Your program must accept input once at the beginning. This will be a line of code. This is not an interactive interpreter! You can only accept input once and do not have to loop back to the start once that line has been executed.
Your program must evaluate said input. Every character that is not mentioned above is ignored.
Your program should then print out the final value of the accumulator, in decimal.
Usual rules for valid programming languages apply.
Standard loopholes are disallowed.
This is code-golf, smallest byte count wins.
Here are some small programs to test out your submissions. Before the arrow is the code, after it is the expected result:

! -> 255
!>> -> 63
!<@ -> 239
!nop!&6*! -> 255
Enjoy!

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>

int
interpret(const char *s)
{
	uint8_t a;
	size_t i;

	a = 0;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case '!':
			a = ~a;
			break;
		case '>':
			a >>= 1;
			break;
		case '<':
			a <<= 1;
			break;
		case '@':
			a = (a >> 4) | (a << 4);
			break;
		}
	}
	return a;
}

int
main(void)
{
	assert(interpret("!") == 255);
	assert(interpret("!>>") == 63);
	assert(interpret("!<@") == 239);
	assert(interpret("!nop!&6*!") == 255);

	return 0;
}

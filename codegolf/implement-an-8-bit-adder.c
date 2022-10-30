/*

The Challenge

Implement a function which accepts two integers whose values range from 0 - 255 and returns the sum of those integers mod 256.
You may only use bitwise negation (~), bitwise or (|), bit shifting operators (>>,<<), and assignment (=).

Things you cannot use include (but are not limited to)

Addition, subtraction, multiplication, and division
Loops
Conditional statements
Function calls
Fewest uses of binary or, binary negation, and bit shift operations wins. In the event of a tie, the most popular solution wins. As always, standard loopholes apply.

Here is an example of a simple 2-bit adder. It uses 77 binary negations, 28 binary ors, and 2 bit-shifts for a total score of 107 (this can be seen by running the C preprocessor with gcc -E).
It could be made much more efficient by removing the #defines and simplifying the resulting expressions, but I've left them in for clarity.

#include <stdio.h>

#define and(a, b) (~((~a)|(~b)))
#define xor(a, b) (and(~a,b) | and(a,~b))

int adder(int a, int b)
{
    int x, carry;
    x = xor(and(a, 1), and(b, 1));
    carry = and(and(a, 1), and(b, 1));
    carry = xor(xor(and(a, 2), and(b, 2)), (carry << 1));
    x = x | carry;
    return x;
}

int main(int argc, char **argv)
{
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (adder(i, j) != (i + j) % 4) {
                printf("Failed on %d + %d = %d\n", i, j, adder(i, j));
            }
        }
    }
}

*/

#include <assert.h>
#include <stdio.h>

/*

https://en.wikipedia.org/wiki/NOR_logic
https://www.geeksforgeeks.org/difference-between-half-adder-and-full-adder

*/

int
bnor(int a, int b)
{
	return ~(a | b);
}

int
band(int a, int b)
{
	return bnor(bnor(a, a), bnor(b, b));
}

int
bor(int a, int b)
{
	return bnor(bnor(a, b), bnor(a, b));
}

int
bxor(int a, int b)
{
	return bnor(bnor(bnor(a, a), bnor(b, b)), bnor(a, b));
}

void
fadd(int a, int b, int c, int *S, int *C)
{
	*S = bxor(a, bxor(b, c));
	*C = bor(band(a, b), band(c, bxor(a, b)));
}

int
add8(int a, int b)
{
	int s, c;
	int x, y;
	int i;
	int r;

	r = 0;
	c = 0;
	for (i = 0; i < 8; i++) {
		x = (a >> i) & 1;
		y = (b >> i) & 1;
		fadd(x, y, c, &s, &c);
		r |= (s << i);
	}
	return r;
}

int
main(void)
{
	int a, b;
	int x, y;

	for (a = 0; a < 256; a++) {
		for (b = 0; b < 256; b++) {
			x = add8(a, b);
			y = (a + b) % 256;
			assert(x == y);
		}
	}
	return 0;
}

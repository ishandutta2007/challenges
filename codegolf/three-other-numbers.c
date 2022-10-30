/*

Given three distinct numbers from 1 to 7, output three other distinct numbers from 1 to 7, that is having no numbers in common with the original numbers.
Your code must produce a different output set for each possible input set. That is, no two inputs can produce the same output, treating both as unordered sets. Other than that, you can implement whatever mapping you want.

More mathematically, you're asked to give a bijection (one-to-one function) f:S→S where S consists of three-element subsets of {1,2,3,4,5,6,7}, such that f(s)∩s=∅ for every s∈S.
As a bijection, this mapping has to be invertible, though you don't have to provide the inverse function in your code.

Here are the 35 possible triples (written space-separated).

I/O

The format of the three-element sets is flexible. You can take the inputs in sorted order as three numbers or a three-element list/array/tuple, or as a set. You may not, however, require ordered inputs in a specific order other than sorted. You may zero index.

You may also use a sequence of seven bits of which three are on. This seven-bit sequence can also be represented as as a decimal number, byte, or character.

Output can be given in any of these formats, with the further allowance that ordered outputs don't have to be sorted.

*/

#include <assert.h>
#include <stdio.h>

int
gen(int x[3], int y[3])
{
	int b, i, j;

	b = 0;
	for (i = 0; i < 3; i++) {
		if (x[i] < 1 || x[i] > 7 || (b & (1 << x[i])))
			return -1;
		b |= (1 << x[i]);
	}

	j = 0;
	for (i = 1; i <= 7 && j < 3; i++) {
		if (!(b & (1 << i)))
			y[j++] = i;
	}

	return 0;
}

void
test(int x[3])
{
	int y[3];

	assert(gen(x, y) >= 0);
	printf("%d %d %d -> %d %d %d\n", x[0], x[1], x[2], y[0], y[1], y[2]);
}

int
main(void)
{
	int a, b, c;
	int x[3];

	for (a = 1; a <= 7; a++) {
		for (b = 1; b <= 7; b++) {
			for (c = 1; c <= 7; c++) {
				if (a != b && b != c && a != c) {
					x[0] = a;
					x[1] = b;
					x[2] = c;
					test(x);
				}
			}
		}
	}

	return 0;
}

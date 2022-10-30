/*

Create a function that takes a number (step) as an argument and returns the amount of boxes in that step of the sequence.

Box Sequence Image

    Step 0: Start with 0
    Step 1: Add 3
    Step 2: Subtract 1
    Repeat Step 1 & 2 ...

Notes

Step (the input) is always a positive integer (or zero).

*/

#include <stdio.h>

unsigned
boxseqi(unsigned n)
{
	unsigned i, r;

	r = 0;
	for (i = 1; i <= n; i++) {
		if (i & 1)
			r += 3;
		else
			r--;
	}
	return r;
}

unsigned
boxseqc(unsigned n)
{
	return n + ((n & 1) << 1);
}

int
main(void)
{
	unsigned i;

	for (i = 0; i < 10000; i++)
		printf("%u %u %u\n", i, boxseqi(i), boxseqc(i));
	return 0;
}

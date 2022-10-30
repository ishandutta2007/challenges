/*

Create a function that takes a number steps as an argument and returns the amount of rectangles you can count in a matrix.
Examples

rectangle(1) ➞ 1

rectangle(2) ➞ 9

rectangle(3) ➞ 36

Notes

    The input will always be an integer.
    Watch the video listed in the Resources tab to get three different formulas.

*/

#include <stdio.h>

// https://oeis.org/A000537
unsigned
rectangles(unsigned n)
{
	n = n * (n + 1) / 2;
	return n * n;
}

int
main(void)
{
	unsigned i;

	for (i = 0; i <= 100; i++)
		printf("%u %u\n", i, rectangles(i));
	return 0;
}

/*

What do the digits 0, 4, 6, 8, and 9 have in common? Well, they are whole numbers... and they are also hole numbers (not actually a thing until now). Hole numbers are numbers with holes in their shapes (8 is special in that it contains two holes).

14 is a hole number with one hole. 88 is a hole number with four holes.

Your task is to create a function with argument N that returns the sum of the holes for the integers n in the range of range 0 < n <= N.

To illustrate, sumOfHoles(14) returns 7, because there are 7 holes in 4, 6, 8, 9, 10 and 14.

Notes

    All test cases are positive real integers.
    Don't forget that 8 has two holes.

*/

#include <stdio.h>

unsigned
count(unsigned n)
{
	static const unsigned tab[] = {
		[0] = 1,
		[4] = 1,
		[6] = 1,
		[8] = 2,
		[9] = 1,
	};
	unsigned c;

	if (n == 0)
		return 0;

	for (c = 0; n; n /= 10)
		c += tab[n % 10];

	return c;
}

unsigned
holes(unsigned n)
{
	unsigned i, c;

	c = 0;
	for (i = 1; i <= n; i++)
		c += count(i);
	return c;
}

int
main(void)
{
	unsigned i;

	for (i = 1; i <= 15000; i++)
		printf("%u %u\n", i, holes(i));
	return 0;
}

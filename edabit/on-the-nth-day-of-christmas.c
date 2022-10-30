/*

Throughout the 12 days of Christmas, my true love gave me in total 364 items.

Create a function where given n days as an argument, return the total amount of items received throughout those days as an integer.

Notes

    You will only be given valid inputs.
    Remember to return as an integer.
    0 as input should return 0.
    Look the specific links into the Resources tab for more informations.

*/

#include <stdio.h>

unsigned
xmasitems(unsigned n)
{
	// https://www.intmath.com/blog/mathematics/the-twelve-days-of-christmas-how-many-presents-1686
	return n * (n + 1) * (n + 2) / 6;
}

int
main(void)
{
	unsigned i;

	for (i = 0; i <= 55; i++)
		printf("%u %u\n", i, xmasitems(i));

	return 0;
}

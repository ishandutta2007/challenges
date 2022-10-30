/*

Create a function that takes a number as an argument and returns the amount of digits it has.

*/

#include <assert.h>
#include <stdio.h>

int
numdigits(long n)
{
	int c;

	c = 0;
	do {
		c++;
		n /= 10;
	} while (n);

	return c;
}

int
main(void)
{
	assert(numdigits(123) == 3);
	assert(numdigits(56) == 2);
	assert(numdigits(7154) == 4);
	assert(numdigits(61217311514l) == 11);
	assert(numdigits(0) == 1);
	assert(numdigits(1) == 1);
	assert(numdigits(67) == 2);
	assert(numdigits(55551) == 5);
	assert(numdigits(96456431l) == 8);
	assert(numdigits(-96456431l) == 8);
	assert(numdigits(-1034) == 4);

	return 0;
}

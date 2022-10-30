/*

Your job is to create a function, that takes 3 numbers: a, b, c and returns true if the last digit
of (the last digit of a * the last digit of b) = the last digit of c. Check examples for explanation.

Notes

    If you still don't understand:
    The last digit of a = aa, the last digit of b = bb, and the last digit of c = cc.
    Return true if the last digit of aa*bb is equal to cc, and false otherwise.
    Numbers can be negative.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
lastdig(int a, int b, int c)
{
	int x, y, z;

	x = abs(a) % 10;
	y = abs(b) % 10;
	z = abs(c) % 10;
	return ((x * y) % 10) == z;
}

int
main(void)
{
	assert(lastdig(25, 21, 125) == 1);
	assert(lastdig(55, 226, 5190) == 1);
	assert(lastdig(12, 215, 2142) == 0);

	assert(lastdig(1, 1, 1) == 1);
	assert(lastdig(12, 15, 10) == 1);
	assert(lastdig(15228, 9209, 72162) == 1);
	assert(lastdig(15, 1, 1) == 0);
	assert(lastdig(123, 15, 10) == 0);
	assert(lastdig(5213, 99219, 6165) == 0);
	assert(lastdig(1523, 513, 512) == 0);
	assert(lastdig(-15, 1, 1) == 0);
	assert(lastdig(123, -15, 10) == 0);
	assert(lastdig(-12, 15, -10) == 1);
	assert(lastdig(15228, -9209, -72162) == 1);

	return 0;
}

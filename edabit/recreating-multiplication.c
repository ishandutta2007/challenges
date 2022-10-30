/*

Create a function that takes two numbers $n1 $n2 and multiplies them without using *.

Examples

multiply(3, 2) ➞ 6

multiply(4, 10) ➞ 40

multiply(-2, 4) ➞ -8

Notes

Do not use * for this challenge.

*/

#include <assert.h>
#include <stdio.h>

long
multiply(long a, long b)
{
	long r, s;

	s = (a < 0) ? 1 : -1;
	for (r = 0; a; a += s)
		r += b;
	return (s > 0) ? -r : r;
}

int
main(void)
{
	assert(multiply(3, 2) == 6);
	assert(multiply(4, 10) == 40);
	assert(multiply(-2, 4) == -8);
	assert(multiply(9, 1) == 9);
	assert(multiply(2, 2) == 4);
	assert(multiply(1, 1) == 1);
	assert(multiply(702, 392) == 275184l);
	assert(multiply(9, 9) == 81);
	assert(multiply(40, 31) == 1240);
	assert(multiply(4, 10) == 40);
	assert(multiply(-2, 4) == -8);
	assert(multiply(-3, -20) == 60);
	assert(multiply(40, -10) == -400);
	assert(multiply(0, 40) == 0);
	assert(multiply(-100, 0) == 0);

	return 0;
}

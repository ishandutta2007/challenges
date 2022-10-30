/*

Mubashir has written a mysterious function that takes two numbers a and b and returns multiplication?.
Solve the riddle of what Mubashir's function is by having a look at some of the examples below.

Examples

mubashirFunction(0, 1) ➞ 0

mubashirFunction(1, 2) ➞ 2

mubashirFunction(10, 10) ➞ 1

Notes

    Check the Tests tab for more examples.
    This isn't really a coding challenge, more of a fun riddle ;)

*/

#include <assert.h>

unsigned
mod9(unsigned x)
{
	x %= 9;
	if (x == 0)
		x = 9;
	return x;
}

unsigned
mubashir(unsigned a, unsigned b)
{
	if (a >= 10)
		a = mod9(a);
	if (b >= 10)
		b = mod9(b);
	return a * b;
}

int
main(void)
{
	assert(mubashir(0, 1) == 0);
	assert(mubashir(1, 2) == 2);
	assert(mubashir(5, 6) == 30);
	assert(mubashir(10, 10) == 1);
	assert(mubashir(200, 200) == 4);
	assert(mubashir(12, 34) == 21);
	assert(mubashir(123, 45) == 54);

	return 0;
}

/*

Create a function that returns how many times it's been called previously.
Do not use a global variable.

Examples

counter() ➞ 0

counter() ➞ 1

counter() ➞ 2

Notes

The first time it's called, the function should return 0.

*/

#include <assert.h>
#include <stdio.h>

unsigned
counter(void)
{
	static unsigned n;
	return n++;
}

int
main(void)
{
	unsigned i;
	for (i = 0; i < 10; i++)
		assert(counter() == i);
	return 0;
}

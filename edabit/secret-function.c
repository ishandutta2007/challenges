/*

Create a function based on the input and output. Look at the examples, there is a pattern.
Examples

secret(24) ➞ 8

secret(42) ➞ 8

secret(15) ➞ -4

secret(52) ➞ 15

Notes

    num >= 10 and num <= 52
    Math.pow, * and - can be helpful.

*/

#include <assert.h>
#include <stdio.h>

int
ipow(int x, int y)
{
	int i, p;

	if (y < 0)
		return 0;

	p = 1;
	for (i = 0; i < y; i++)
		p *= x;
	return p;
}

int
secret(int n)
{
	int x, y;

	x = (n / 10) % 10;
	y = n % 10;
	return ipow(x, y) - (x * y);
}

int
main(void)
{
	assert(secret(24) == 8);
	assert(secret(32) == 3);
	assert(secret(23) == 2);
	assert(secret(42) == 8);
	assert(secret(15) == -4);
	assert(secret(32) == 3);
	assert(secret(52) == 15);
	assert(secret(25) == 22);

	return 0;
}

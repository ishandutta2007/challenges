/*

The modulo operation can also be done by repetitive subtraction or addition. In this challenge, you're going to create a function that mimics such an operation and returns the modulo of the two given numbers by recursively subtracting or adding them.

Examples

modulo(100, 25) ➞ 0

modulo(-51, -4) ➞ -3

modulo(3, 9) ➞ 3

modulo(-21, 5) ➞ -1

modulo(1024, 7) ➞ 2

modulo(273, -6) ➞ 3

Notes

    There will be no zero-values for the modulo divisor.
    You're expected to solve this challenge using a recursive approach.
    You can read on more topics about recursion (see Resources tab) if you aren't familiar with it yet or haven't fully assumed the concept behind it before taking up this challenge.
    If you think recursion is fun, you can find a collection of those challenges here.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
modr(int x, int m)
{
	if (m == 0)
		return 0;
	if (x < m)
		return x;
	return modr(x - m, m);
}

int
mod(int x, int m)
{
	int r;

	r = modr(abs(x), abs(m));
	if (x < 0)
		r = -r;

	return r;
}

int
main(void)
{
	int i, j;

	assert(mod(100, 25) == 0);
	assert(mod(-51, -4) == -3);
	assert(mod(3, 9) == 3);
	assert(mod(-21, 5) == -1);
	assert(mod(1024, 7) == 2);
	assert(mod(273, -6) == 3);

	for (i = -10000; i <= 10000; i++) {
		for (j = -10000; j <= 10000; j++) {
			if (j == 0)
				continue;

			assert(mod(i, j) == (i % j));
		}
	}

	return 0;
}

/*

Create a function that takes an array consisting of dice rolls from 1-6. Return the sum of your rolls with the following conditions:

    If a 1 is rolled, that is bad luck. The next roll counts as 0.
    If a 6 is rolled, that is good luck. The next roll is multiplied by 2.
    The array length will always be 3 or higher.

Examples

rolls([1, 2, 3]) ➞ 4
// The second roll, 2, counts as 0 as a result of rolling 1.

rolls([2, 6, 2, 5]) ➞ 17
// The 2 following the 6 was multiplied by 2.

rolls([6, 1, 1]) ➞ 8
// The first roll makes the second roll worth 2, but the
// second roll was still 1 so the third roll doesn't count.

Notes

Even if a 6 is rolled after a 1, 6 isn't summed but the 6's "effect" still takes place.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
rolls(unsigned *a, size_t n)
{
	unsigned c, p;
	size_t i;

	c = 0;
	p = 1;
	for (i = 0; i < n; i++) {
		c += a[i] * p;
		if (a[i] == 1)
			p = 0;
		else if (a[i] == 6)
			p = 2;
		else
			p = 1;
	}
	return c;
}

int
main(void)
{
	unsigned a1[] = { 1, 2, 3 };
	unsigned a2[] = { 2, 6, 2, 5 };
	unsigned a3[] = { 6, 1, 1 };
	unsigned a4[] = { 5, 1, 6, 1, 6 };
	unsigned a5[] = { 1, 1, 1 };
	unsigned a6[] = { 1, 1, 3, 1, 1 };
	unsigned a7[] = { 1, 1, 1, 1, 1 };
	unsigned a8[] = { 6, 6, 6 };

	assert(rolls(a1, nelem(a1)) == 4);
	assert(rolls(a2, nelem(a2)) == 17);
	assert(rolls(a3, nelem(a3)) == 8);
	assert(rolls(a4, nelem(a4)) == 8);
	assert(rolls(a5, nelem(a5)) == 1);
	assert(rolls(a6, nelem(a6)) == 2);
	assert(rolls(a7, nelem(a7)) == 1);
	assert(rolls(a8, nelem(a8)) == 30);

	return 0;
}

/*

Create a function that takes a variable number of groups of items, and returns the number of ways the items can be arranged, with one item from each group. Order does not matter.
Examples

combinations(2, 3) ➞ 6

combinations(3, 7, 4) ➞ 84

combinations(2, 3, 4, 5) ➞ 120

Notes

Don't overthink this one.

*/

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>

unsigned long
combinations(size_t n, ...)
{
	unsigned long c, v;
	va_list ap;
	size_t i;

	va_start(ap, n);
	c = 1;
	for (i = 0; i < n; i++) {
		v = va_arg(ap, unsigned long);
		if (v)
			c *= v;
	}
	va_end(ap);

	return c;
}

int
main(void)
{
	assert(combinations(1, 2) == 2);
	assert(combinations(2, 2, 3) == 6);
	assert(combinations(2, 3, 5) == 15);
	assert(combinations(3, 5, 6, 7) == 210);
	assert(combinations(4, 5, 5, 5, 5) == 625);
	assert(combinations(3, 3, 6, 9) == 162);
	assert(combinations(9, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 3628800);
	assert(combinations(3, 4, 5, 6) == 120);
	assert(combinations(4, 5, 6, 7, 8) == 1680);
	assert(combinations(3, 6, 7, 0) == 42);
	assert(combinations(3, 3, 7, 4) == 84);

	return 0;
}

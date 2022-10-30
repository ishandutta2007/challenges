/*

This is a reverse coding challenge. Normally you're given explicit directions with how to create a function.
Here, you must generate your own function to satisfy the relationship between the inputs and outputs.

Your task is to create a function that, when fed the inputs below, produce the sample outputs shown.

Examples

832 ➞ 594

51 ➞ 36

7977 ➞ 198

1 ➞ 0

665 ➞ 99

149 ➞ 0

Notes

If you get stuck, see Comments for a hint.

Hint: Think about sorting the number by the order of the digits.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

size_t
digits(unsigned x, unsigned *d)
{
	size_t i;

	i = 0;
	do {
		d[i++] = x % 10;
		x /= 10;
	} while (x);

	return i;
}

unsigned
number(unsigned *d, size_t n)
{
	size_t i;
	unsigned r;

	r = 0;
	for (i = 0; i < n; i++)
		r = (r * 10) + d[i];
	return r;
}

int
cmp(const void *a, const void *b)
{
	unsigned x, y;

	x = *(unsigned *)a;
	y = *(unsigned *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

unsigned
mystery(unsigned x)
{
	unsigned d[sizeof(x) * CHAR_BIT];
	size_t n;

	n = digits(x, d);
	qsort(d, n, sizeof(*d), cmp);
	return x - number(d, n);
}

int
main(void)
{
	assert(mystery(832) == 594);
	assert(mystery(51) == 36);
	assert(mystery(7977) == 198);
	assert(mystery(1) == 0);
	assert(mystery(665) == 99);
	assert(mystery(149) == 0);

	return 0;
}

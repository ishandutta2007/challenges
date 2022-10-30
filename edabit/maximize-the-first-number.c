/*

Write a function that makes the first number as large as possible by swapping out its digits for digits in the second number.

To illustrate:

maxPossible(9328, 456) ➞ 9658
// 9658 is the largest possible number built from swaps from 456.
// 3 replaced with 6 and 2 replaced with 5.

Examples

maxPossible(523, 76) ➞ 763

maxPossible(9132, 5564) ➞ 9655

maxPossible(8732, 91255) ➞ 9755

Notes

    Each digit in the second number can only be used once.
    Zero to all digits in the second number may be used.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t
digits(unsigned long *d, unsigned long x)
{
	size_t n;

	n = 0;
	do {
		d[n++] = x % 10;
	} while ((x /= 10));
	return n;
}

int
cmp(const void *a, const void *b)
{
	unsigned long x, y;

	x = *(unsigned long *)a;
	y = *(unsigned long *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

unsigned long
maxpossible(unsigned long x, unsigned long y)
{
	unsigned long a[sizeof(x) * 8], b[sizeof(y) * 8];
	unsigned long p, v;
	size_t n, m;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	n = digits(a, x);
	m = digits(b, y);
	qsort(b, m, sizeof(y), cmp);

	v = 0;
	for (;;) {
		p = a[--n];
		if (m > 0 && p < b[m - 1])
			p = b[--m];

		v += p;
		if (n == 0)
			break;
		v *= 10;
	}

	return v;
}

int
main(void)
{
	assert(maxpossible(9328, 456) == 9658);
	assert(maxpossible(523, 76) == 763);
	assert(maxpossible(9132, 5564) == 9655);
	assert(maxpossible(8732, 91255ul) == 9755);
	assert(maxpossible(589, 777) == 789);
	assert(maxpossible(1, 0) == 1);
	assert(maxpossible(8, 9) == 9);
	assert(maxpossible(28, 19) == 98);
	assert(maxpossible(12345, 4) == 42345);
	assert(maxpossible(0, 29) == 9);

	return 0;
}

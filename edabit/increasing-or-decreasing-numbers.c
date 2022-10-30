/*

Mubashir needs your help to find out Increasing and Decreasing numbers for a given range.
Increasing Numbers

Numbers whose digits, when read from left to right, are never less than the previous digit. See below some examples of increasing numbers:

1111
123456
125788999

Decreasing Numbers

Numbers whose digits, when read from left to right, are never greater than the previous digit. See below some examples of decreasing numbers:

1111
654321
999887521

Create a function that takes a number n and returns total occurrences of all the increasing or decreasing numbers in range 10^n.

Examples

inc_or_dec(0) ➞ 1
# 10^0 = 1
# 1 is both increasing and decreasing.

inc_or_dec(1) ➞ 10
# 10^1 = 10
# [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] are both increasing and decreasing numbers.

inc_or_dec(3) ➞ 475

Notes

To make it even clear, the increasing or decreasing numbers in range 101-200 are:

110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 122, 123, 124, 125, 126, 127, 128, 129, 133, 134, 135, 136, 137, 138, 139, 144, 145, 146, 147, 148, 149, 155, 156, 157, 158, 159, 166, 167, 168, 169, 177, 178, 179, 188, 189, 199, 200

The total will be 47 in this case.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

size_t
digits(uvlong n, uvlong *d)
{
	size_t i;

	i = 0;
	do {
		d[i++] = n % 10;
	} while (n /= 10);

	return i;
}

int
monotone(uvlong n)
{
	uvlong d[sizeof(n) * CHAR_BIT];
	size_t l;
	int f;

	l = digits(n, d);
	for (f = 0; l > 1; l--) {
		if (d[l - 1] > d[l - 2])
			f |= 1;
		else if (d[l - 1] < d[l - 2])
			f |= 2;

		if ((f & 3) == 3)
			return 0;
	}
	return 1;
}

uvlong
incordec(uvlong n)
{
	uvlong i, r;

	r = 0;
	n = pow(10, n);
	for (i = 1; i <= n; i++)
		r += monotone(i);
	return r;
}

int
main(void)
{
	static const uvlong tab[] = {
	    1,
	    10,
	    100,
	    475,
	    1675,
	    4954,
	    12952,
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(incordec(i) == tab[i]);

	return 0;
}

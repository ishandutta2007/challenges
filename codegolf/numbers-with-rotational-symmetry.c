/*

Given an integer, output a truthy value if it is the same upside-down (rotated 180°) or a falsy value otherwise.

0, 1, and 8 have rotational symmetry. 6 becomes 9 and vice versa.

Sequence of numbers producing truthy results: OEIS A000787

0, 1, 8, 11, 69, 88, 96, 101, 111, 181, 609, 619, 689, 808, 818, 888, 906, 916, 986, 1001, 1111, 1691, 1881, 1961, 6009, 6119, 6699, 6889, 6969, 8008, 8118, 8698, 8888, 8968, 9006, 9116, 9696, 9886, 9966, 10001, 10101, 10801, 11011, 11111, 11811, 16091, ...
This question is inspired by my own reputation at the time of posting: 6009.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
digits(unsigned x, unsigned *d)
{
	size_t i;

	i = 0;
	do {
		d[i++] = x % 10;
	} while (x /= 10);

	return i;
}

bool
rotational(unsigned *d, size_t n)
{
	size_t i, j;

	for (i = 0; i <= n / 2; i++) {
		j = n - i - 1;
		if (d[i] == d[j] && (d[i] == 0 || d[i] == 1 || d[i] == 8))
			continue;

		if ((d[i] == 6 && d[j] == 9) || (d[i] == 9 && d[j] == 6))
			continue;

		return false;
	}
	return true;
}

bool
strobogrammatic(unsigned x)
{
	unsigned d[sizeof(x) * CHAR_BIT];
	size_t n;

	n = digits(x, d);
	return rotational(d, n);
}

int
main(void)
{
	static const unsigned tab[] = {
	    0,
	    1,
	    8,
	    11,
	    69,
	    88,
	    96,
	    101,
	    111,
	    181,
	    609,
	    619,
	    689,
	    808,
	    818,
	    888,
	    906,
	    916,
	    986,
	    1001,
	    1111,
	    1691,
	    1881,
	    1961,
	    6009,
	    6119,
	    6699,
	    6889,
	    6969,
	    8008,
	    8118,
	    8698,
	    8888,
	    8968,
	    9006,
	    9116,
	    9696,
	    9886,
	    9966,
	    10001,
	    10101,
	    10801,
	    11011,
	    11111,
	    11811,
	    16091,
	};

	size_t i;
	unsigned x;

	x = 0;
	for (i = 0; i < nelem(tab); i++) {
		while (!strobogrammatic(x))
			x++;

		printf("%u %u\n", x, tab[i]);
		assert(x == tab[i]);
		x++;
	}

	return 0;
}

/*

Given an array of n non-negative integers: A1, A2, …, AN. Your mission is finding a pair of integers Au, Av (1 ≤ u < v ≤ N) such that (Au and Av) is as large as possible.

And is a bit-wise operation which is corresponding to & in C++ and Java. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
maxand_slow(unsigned *a, size_t n)
{
	size_t i, j;
	unsigned m;

	m = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (m < (a[i] & a[j]))
				m = a[i] & a[j];
		}
	}
	return m;
}

size_t
countbits(unsigned p, unsigned *a, size_t n)
{
	size_t c, i;

	for (c = i = 0; i < n; i++) {
		if ((p & a[i]) == p) {
			if (++c >= 2)
				break;
		}
	}
	return c;
}

unsigned
maxand(unsigned *a, size_t n)
{
	static const int bits = sizeof(unsigned) * CHAR_BIT;
	unsigned r;
	size_t c;
	int i;

	r = 0;
	for (i = bits - 1; i >= 0; i--) {
		c = countbits(r | (1u << i), a, n);
		if (c >= 2)
			r |= (1u << i);
	}
	return r;
}

int
main(void)
{
	srand48(time(NULL));

	unsigned a[] = {4, 2, 4, 8, 10};
	printf("%u %u\n", maxand_slow(a, nelem(a)), maxand(a, nelem(a)));

	static unsigned b[65536];
	size_t i, n;
	for (n = 0; n < 100; n++) {
		for (i = 0; i < nelem(b); i++)
			b[i] = lrand48() % lrand48();
		printf("%u %u\n", maxand_slow(b, nelem(b)), maxand(b, nelem(b)));
	}
	return 0;
}

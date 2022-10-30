/*

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

*/

#include <stdio.h>

int
altbits(unsigned n)
{
	unsigned a, b;

	if (n < 2)
		return 0;

	b = 2;
	do {
		a = n & 1;
		if (b < 2 && a == b)
			return 0;
		b = a;
		n >>= 1;
	} while (n);

	return 1;
}

int
main(void)
{
	unsigned i;

	for (i = 0; i < 1u << 30; i++) {
		if (altbits(i))
			printf("%u %x\n", i, i);
	}
	return 0;
}

/*

Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.

If there aren't two consecutive 1's, return 0.

*/

#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
gap(unsigned n)
{
	int m, c, f;

	m = 0;
	f = 0;
	for (c = 0; n; n >>= 1) {
		if (n & 1) {
			m = max(m, c);
			f = 1;
			c = 0;
		}
		if (f)
			c++;
	}
	return m;
}

int
main(void)
{
	printf("%d\n", gap(22));
	printf("%d\n", gap(5));
	printf("%d\n", gap(6));
	printf("%d\n", gap(8));
	printf("%d\n", gap(0x80000000u));
	printf("%d\n", gap(0x80000001u));
	printf("%d\n", gap(0x8f000000u));
	printf("%d\n", gap(0x87000001u));
	return 0;
}

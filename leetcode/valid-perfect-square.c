/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

*/

#include <stdio.h>

// hacker delight's (ch 11)
int
isqrt(unsigned x)
{
	unsigned x1;
	int s, g0, g1;

	if (x <= 1)
		return x;

	s = 1;
	x1 = x - 1;
	if (x1 > 0xffff) {
		s += 8;
		x1 >>= 16;
	}
	if (x1 > 0xff) {
		s += 4;
		x1 >>= 8;
	}
	if (x1 > 0xf) {
		s += 2;
		x1 >>= 4;
	}
	if (x1 > 0x3)
		s++;

	g0 = 1 << s;
	g1 = (g0 + (x >> s)) >> 1;

	while (g1 < g0) {
		g0 = g1;
		g1 = (g0 + x / g0) >> 1;
	}
	return g0;
}

int
psq(unsigned n)
{
	unsigned s;

	s = isqrt(n);
	return s * s == n;
}

int
main(void)
{
	printf("%d\n", psq(16));
	printf("%d\n", psq(14));
	return 0;
}

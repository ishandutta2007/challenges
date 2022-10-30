/*

Given an integer, return its base 7 string representation.

Note: The input will be in range of [-1e7, 1e7].

*/

#include <stdio.h>

char *
base7(long x, char *b, size_t n)
{
	long s, p, v;

	if (x == 0) {
		snprintf(b, n, "0");
		return b;
	}

	v = 0;
	s = 1;
	p = 1;
	if (x < 0) {
		s = -1;
		x = -x;
	}
	while (x) {
		v += p * (x % 7);
		p *= 10;
		x /= 7;
	}

	snprintf(b, n, "%ld", v * s);
	return b;
}

int
main(void)
{
	char b[80];
	printf("%s\n", base7(100, b, sizeof(b)));
	printf("%s\n", base7(-7, b, sizeof(b)));
	for (long i = -100; i <= 100; i++)
		printf("%ld %s\n", i, base7(i, b, sizeof(b)));
	printf("%s\n", base7(10000000, b, sizeof(b)));
	return 0;
}

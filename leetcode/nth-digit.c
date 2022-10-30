/*

Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
nth_slow(unsigned n)
{
	unsigned i, j, k, v;
	char b[80];

	v = 0;
	j = 1;
	for (i = 0; i < n; j++) {
		k = snprintf(b, sizeof(b), "%u", j);
		if (n - k <= i)
			return b[n - i - 1] - '0';
		i += k;
	}
	return v;
}

unsigned
nth(unsigned n)
{
	// http://oeis.org/A033714
	static const unsigned long tab[] = {
	    1ul,
	    10ul,
	    190ul,
	    2890ul,
	    38890ul,
	    488890ul,
	    5888890ul,
	    68888890ul,
	    788888890ul,
	    8888888890ul,
	    98888888890ul,
	    1088888888890ul,
	    11888888888890ul,
	    128888888888890ul,
	    1388888888888890ul,
	    14888888888888890ul,
	    158888888888888890ul,
	    1688888888888888890ul,
	    17888888888888888890ul,
	};
	static const unsigned long p10[] = {
	    1ul,
	    10ul,
	    100ul,
	    1000ul,
	    10000ul,
	    100000ul,
	    1000000ul,
	    10000000ul,
	    100000000ul,
	    1000000000ul,
	    10000000000ul,
	    1000000000000ul,
	    100000000000000ul,
	    100000000000000ul,
	    1000000000000000ul,
	    10000000000000000ul,
	    100000000000000000ul,
	    1000000000000000000ul,
	    10000000000000000000ul,
	};
	unsigned long i, m, p;
	char b[80];

	if (n < 10)
		return n;

	for (i = 0; i < nelem(tab); i++) {
		if (tab[i] > n)
			break;
	}
	if (i == nelem(tab))
		return 10;

	p = p10[i - 1] + (n - tab[i - 1]) / i;
	m = (n - tab[i - 1]) % i;
	snprintf(b, sizeof(b), "%lu", p);
	return b[m] - '0';
}

int
main(void)
{
	unsigned i, x, y;
	for (i = 0; i <= 100000; i++) {
		x = nth_slow(i);
		y = nth(i);
		printf("%u %u %u\n", i, x, y);
		if (nth_slow(i) != nth(i)) {
			printf("MISMATCH\n");
			break;
		}
	}

	i = 1 << 31;
	printf("%u %u\n", i, nth(i));
	return 0;
}

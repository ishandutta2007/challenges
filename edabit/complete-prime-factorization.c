/*

Create a function that decomposes an integer into its prime factors, ordered from smallest to largest.

For instance:

completeFactorization(24) = [2, 2, 2, 3]
// Since 24 = 8 x 3 = 2^3 x 3 = 2 x 2 x 2 x 3

Examples

completeFactorization(10) ➞ [2, 5]

completeFactorization(9) ➞ [3, 3]

completeFactorization(72) ➞ [2, 2, 2, 3, 3]

Notes

1 is not considered a prime number, so omit it in your final array of prime factors.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned *
factorize(unsigned n, size_t *l)
{
	unsigned *p, *q, i;
	size_t c, m;

	p = NULL;
	m = c = 0;
	for (i = 2; i <= n; i++) {
		while (!(n % i)) {
			n /= i;
			if (c >= m) {
				m += 32;
				q = realloc(p, m * sizeof(*p));
				if (!q)
					goto error;
				p = q;
			}
			p[c++] = i;
		}
	}
	*l = c;

	if (0) {
	error:
		free(p);
		p = NULL;
		*l = 0;
	}

	return p;
}

void
test(unsigned n, unsigned *r, size_t nr)
{
	unsigned *p;
	size_t np;

	p = factorize(n, &np);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
	free(p);
}

int
main(void)
{
	unsigned p1[] = {2, 3, 5};
	unsigned p2[] = {2, 2, 3};
	unsigned p3[] = {3, 5};
	unsigned p4[] = {2, 2, 2, 2, 3};
	unsigned p5[] = {311};
	unsigned p6[] = {17};
	unsigned p7[] = {2, 2, 11};
	unsigned p8[] = {2, 5};
	unsigned p9[] = {3, 3};
	unsigned p10[] = {2, 2, 2, 3, 3};

	test(30, p1, nelem(p1));
	test(12, p2, nelem(p2));
	test(15, p3, nelem(p3));
	test(48, p4, nelem(p4));
	test(311, p5, nelem(p5));
	test(17, p6, nelem(p6));
	test(44, p7, nelem(p7));
	test(10, p8, nelem(p8));
	test(9, p9, nelem(p9));
	test(72, p10, nelem(p10));

	return 0;
}

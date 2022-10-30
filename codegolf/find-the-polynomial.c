/*

We know that f is a polynomial with non-negative integer coefficients.

Given f(1) and f(1+f(1)) return f. You may output f as a list of coefficients, an ASCII formatted polynomial, or similar.

Examples:

f(1)  f(1+f(1))  f
0     0          0
1     1          1
5     75         2x^2 + 3
30    3904800    4x^4 + 7x^3 + 2x^2 + 8x + 9
1     1073741824 x^30

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

/*

@Doorknob:

Since we know the polynomial has non-negative integer coefficients, f(b) can be interpreted as "the coefficients of the polynomial, taken as base b digits," by the definition of a base.
This is subject to the condition that none of the coefficients exceeds or is equal to b, but we know that, because b is one greater than the sum of the coefficients (which is f(1)).

*/

size_t
coeffs(uvlong a, uvlong b, uvlong *r)
{
	size_t i;

	i = 0;
	do {
		r[i++] = b % (a + 1);
		b /= a + 1;
	} while (b);

	return i;
}

void
test(uvlong a, uvlong b, uvlong *r, size_t n)
{
	uvlong c[128];
	uvlong m;

	m = coeffs(a, b, c);
	assert(n == m);
	assert(!memcmp(c, r, n * sizeof(*r)));
}

int
main(void)
{
	uvlong c1[] = {0};
	uvlong c2[] = {1};
	uvlong c3[] = {3, 0, 2};
	uvlong c4[] = {9, 8, 2, 7, 4};
	uvlong c5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	test(0, 0, c1, nelem(c1));
	test(1, 1, c2, nelem(c2));
	test(5, 75, c3, nelem(c3));
	test(30, 3904800ULL, c4, nelem(c4));
	test(1, 1073741824ULL, c5, nelem(c5));

	return 0;
}

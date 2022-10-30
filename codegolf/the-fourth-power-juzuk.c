/*

In 1939 Juzuk described a way to generate the fourth powers of natural numbers. Group the natural numbers like this:

1   2 3   4 5 6   7 8 9 10   11 12 13 14 15   ...

Scratch each second group:

1   4 5 6   11 12 13 14 15 ...

The sum of the n remaining groups is n**4.

    Input: none
    Task: print the fourth powers upto 100**4, using Juzuk's method.

    Output:

    0 (optional) 1 16 81 ... 100000000

*/

#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;

typedef struct {
	uvlong n;
	uvlong r;
} juzuk_t;

// https://oeis.org/A084849
uvlong
term(uvlong n)
{
	return 1 + n + 2 * n * n;
}

uvlong
termlen(uvlong n)
{
	return 2 * n + 1;
}

uvlong
juzuknext(juzuk_t *z)
{
	uvlong i, l, x;

	if (z->n == 0) {
		z->n = z->r = 1;
		return z->r;
	}

	x = term(z->n);
	l = termlen(z->n);
	for (i = 0; i < l; i++)
		z->r += x + i;

	z->n++;
	return z->r;
}

int
main(void)
{
	juzuk_t z;
	uvlong i;

	memset(&z, 0, sizeof(z));
	for (i = 0; i <= 100; i++) {
		printf("%llu %llu\n", z.n, z.r);
		juzuknext(&z);
	}

	return 0;
}

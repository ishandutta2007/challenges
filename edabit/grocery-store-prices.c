/*

You are given an array of strings consisting of grocery items, with prices in parentheses. Return an array of prices in float format.
Examples

getPrices(["ice cream ($5.99)", "banana ($0.20)", "sandwich ($8.50)", "soup ($1.99)"]) ➞ [5.99, 0.2, 8.50, 1.99]

getPrices(["salad ($4.99)"]) ➞ [4.99]

Notes

See if you can use RegExp to solve (but it's not necessary).

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double *
prices(const char **s, size_t n)
{
	double *p;
	char *b;
	size_t i;

	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	for (i = 0; i < n; i++) {
		if (!(b = strstr(s[i], "$")))
			continue;
		sscanf(b + 1, "%lf", &p[i]);
	}
	return p;
}

void
test(const char **s, size_t n, double *d)
{
	double *p;

	p = prices(s, n);
	assert(p && memcmp(p, d, n * sizeof(*d)) == 0);
	free(p);
}

int
main(void)
{
	const char *s1[] = {
		"ice cream ($5.99)",
		"banana ($0.20)",
		"sandwich ($8.50)",
		"soup ($1.99)",
	};
	double p1[] = { 5.99, 0.20, 8.50, 1.99 };

	const char *s2[] = {
		"salad ($4.99)",
	};
	double p2[] = { 4.99 };

	const char *s3[] = {
		"artichokes ($1.99)",
		"rotiserrie chicken ($5.99)",
		"gum ($0.75)",
	};
	double p3[] = { 1.99, 5.99, 0.75 };

	const char *s4[] = {
		"pizza ($2.99)",
		"shampoo ($15.75)",
		"trash bags ($15.00)",
	};
	double p4[] = { 2.99, 15.75, 15.00 };

	test(s1, nelem(s1), p1);
	test(s2, nelem(s2), p2);
	test(s3, nelem(s3), p3);
	test(s4, nelem(s4), p4);

	return 0;
}

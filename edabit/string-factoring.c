/*

Given the complete factorization of a number, create a function that converts this array of factors to a string.

To illustrate: 24's complete factorization is [2, 2, 2, 3], which should be converted to "2^3 x 3".
Examples

StringFactor(new int[] { 2, 2, 2, 3, 3 }) ➞ "2^3 x 3^2"

StringFactor(new int[] { 2, 7 }) ➞ "2 x 7"

StringFactor(new int[] { 2, 3, 3 }) ➞ "2 x 3^2"

Notes

    Factors should be joined with x (multiplication sign).
    Multiple instances of the same factor should be exponentiated.
    Factors raised to the 1 power should be left as is, i.e. write 7 instead of 7^1.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	unsigned x, y;

	x = *(unsigned *)a;
	y = *(unsigned *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

char *
strfac(unsigned *a, size_t n, char *b)
{
	size_t i, j, k, l;

	qsort(a, n, sizeof(*a), cmp);
	for (i = l = 0; i < n; i = j) {
		j = i + 1;
		while (j < n && a[j] == a[i])
			j++;

		k = j - i;
		l += sprintf(b + l, "%u", a[i]);
		if (k > 1)
			l += sprintf(b + l, "^%zu", k);
		if (j < n)
			l += sprintf(b + l, " x ");
	}
	return b;
}

void
test(unsigned *a, size_t n, const char *r)
{
	char b[128];

	strfac(a, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	unsigned a1[] = {2, 2, 2, 3, 3};
	unsigned a2[] = {2, 7};
	unsigned a3[] = {2, 3, 3};
	unsigned a4[] = {2, 2, 2, 2, 2};
	unsigned a5[] = {2, 3, 7};
	unsigned a6[] = {2, 2, 7, 11};
	unsigned a7[] = {11, 11, 11};

	test(a1, nelem(a1), "2^3 x 3^2");
	test(a2, nelem(a2), "2 x 7");
	test(a3, nelem(a3), "2 x 3^2");
	test(a4, nelem(a4), "2^5");
	test(a5, nelem(a5), "2 x 3 x 7");
	test(a6, nelem(a6), "2^2 x 7 x 11");
	test(a7, nelem(a7), "11^3");

	return 0;
}

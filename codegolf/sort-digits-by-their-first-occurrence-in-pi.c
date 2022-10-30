/*

Given a non-negative number n, sort the digits of n by their first occurrence in pi.

Input can be taken via function cli argument, or STDIN and as a string, char[] or integer.
You may output via return value, exit status or STDOUT.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
pisort(uvlong n)
{
	static const uvlong tab[] = {3, 1, 4, 5, 9, 2, 6, 8, 7, 0};

	uvlong d[10];
	uvlong i, j, r;

	memset(d, 0, sizeof(d));
	do {
		d[n % 10]++;
	} while (n /= 10);

	r = 0;
	for (i = 0; i < nelem(tab); i++) {
		for (j = tab[i]; d[j]; d[j]--)
			r = (r * 10) + j;
	}

	return r;
}

int
main(void)
{
	assert(pisort(1234567890ull) == 3145926870ull);
	assert(pisort(1234567890123456789ull) == 3311445599226688770ull);

	return 0;
}

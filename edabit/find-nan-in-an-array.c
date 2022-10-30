#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
findnan(double *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (isnan(a[i]))
			return i;
	}
	return -1;
}

int
main(void)
{
	double a1[] = { 1, 2, NAN, 3 };
	double a2[] = { 1, 2, 3, NAN, 3, 4, 5, 3 };
	double a3[] = { 1, 2, 3, 4, 5 };
	double a4[] = { NAN, 2, 3, 4 };
	double a5[] = { 1, 2, 3 };

	assert(findnan(a1, nelem(a1)) == 2);
	assert(findnan(a2, nelem(a2)) == 3);
	assert(findnan(a3, nelem(a3)) == -1);
	assert(findnan(a4, nelem(a4)) == 0);
	assert(findnan(a5, nelem(a5)) == -1);

	return 0;
}

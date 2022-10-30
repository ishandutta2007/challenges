/*

Given five positive integers, find the minimum and maximum values that can be calculated by summing
exactly four of the five integers.

Then print the respective minimum and maximum values as a single line of two space-separated long integers.

For example, arr=[1 3 5 7 9]. Our minimum sum is 16 and our maximum sum is 24.

We would print

16 24

*/
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void
minmaxsum(int64_t a[5])
{
	int64_t m, n, s;
	size_t i;

	m = a[0];
	n = a[0];
	s = 0;
	for (i = 0; i < 5; i++) {
		s += a[i];
		if (m > a[i])
			m = a[i];
		if (n < a[i])
			n = a[i];
	}

	printf("%" PRIi64 " %" PRIi64 "\n", s - n, s - m);
}

int
main(void)
{
	int64_t a[] = {1, 2, 3, 4, 5};
	minmaxsum(a);

	int64_t b[] = {1, 3, 5, 7, 9};
	minmaxsum(b);

	return 0;
}

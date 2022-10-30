/*

The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

The given array size will in the range [2, 10000].
The given array's numbers won't have any order.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
mismatch(int *a, size_t n, int r[2])
{
	size_t i;
	int t;

	r[0] = r[1] = -1;
	for (i = 0; i < n; i++) {
		t = abs(a[i]);
		if (a[t - 1] < 0)
			r[0] = t;
		else
			a[t - 1] = -a[t - 1];
	}

	for (i = 1; i < n; i++) {
		if (a[i] > 0)
			r[1] = i + 1;
		else
			a[i] = -a[i];
	}
}

void
test(int *a, size_t n)
{
	int r[2];

	mismatch(a, n, r);
	printf("[%d,%d]\n", r[0], r[1]);
}

int
main(void)
{
	int a1[] = {1, 2, 2, 4};
	int a2[] = {2, 3, 3, 4, 6, 5, 9, 8, 7, 1};

	test(a1, nelem(a1));
	test(a2, nelem(a2));
	return 0;
}

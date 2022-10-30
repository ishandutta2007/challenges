/*
Given an array of integers, find and print the maximum number of integers 
you can select from the array such that the absolute difference between any
two of the chosen integers is less than or equal to 1. 
For example, if your array is [1 1 2 2 4 4 5 5 5], you can create two subarrays meeting
the criterion: [1 1 2 2] and [4 4 5 5 5]. The maximum length subarray has 5 elements.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;

	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
print(int *a, size_t n)
{
	size_t i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

size_t
picksum(int *a, size_t n)
{
	size_t i, j, k, l;
	int *p, v;

	if (n < 2)
		return 0;

	p = malloc(n);
	if (p == NULL)
		return SIZE_MAX;

	for (i = 0; i < n; i++)
		p[i] = a[i];

	qsort(p, n, sizeof(*p), cmp);
	l = 1;
	j = 1;
	v = p[0];
	for (i = 1; i < n; i++) {
		if (abs(p[i] - v) > 1) {
			v = p[i];
			j = 1;

			for (k = i - 1;;) {
				if (abs(p[k] - v) <= 1)
					j++;

				if (k == 0)
					break;
				k--;
			}
		} else
			j++;

		if (l < j)
			l = j;
	}
	if (l < 2)
		l = 0;

	free(p);
	return l;
}

int
main(void)
{
	int a[] = {1, 1, 2, 2, 4, 4, 5, 5, 5};
	int b[] = {4, 6, 5, 3, 3, 1};
	int c[] = {1, 2, 2, 3, 1, 2};
	int d[] = {1, 2, 3, 3};
	print(a, nelem(a));
	printf("%zu\n\n", picksum(a, nelem(a)));

	print(b, nelem(b));
	printf("%zu\n\n", picksum(b, nelem(b)));

	print(c, nelem(c));
	printf("%zu\n\n", picksum(c, nelem(c)));

	print(d, nelem(d));
	printf("%zu\n\n", picksum(d, nelem(d)));
	return 0;
}

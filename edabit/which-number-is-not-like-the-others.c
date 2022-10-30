/*

Create a function that takes an array of numbers and return the number that's unique.
Examples

unique([3, 3, 3, 7, 3, 3]) ➞ 7

unique([0, 0, 0.77, 0, 0]) ➞ 0.77

unique([0, 1, 1, 1, 1, 1, 1, 1]) ➞ 0

Notes

Test cases will always have exactly one unique number while all others are the same.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
unique(double *a, size_t n)
{
	size_t i, j, k, l;

	if (n == 0)
		return 0;
	if (n <= 2)
		return a[0];

	for (i = 0; i < n - 1; i++) {
		if (a[i] != a[i + 1])
			break;
	}

	for (j = k = l = 0; j < n; j++) {
		if (a[i] == a[j])
			k++;
		if (a[i + 1] == a[j])
			l++;
		if (k > 1)
			return a[i + 1];
		if (l > 1)
			return a[i];
	}
	return 0;
}

int
main(void)
{
	double a1[] = { 3, 3, 3, 7, 3, 3 };
	double a2[] = { 0, 0, 0.77, 0, 0 };
	double a3[] = { 0, 1, 1, 1, 1, 1, 1, 1 };
	double a4[] = { -4, -4, -4, 4 };
	double a5[] = { 8, 8, 8, 8, 8, 8, 8, 0.5 };
	double a6[] = { 2, 1, 2, 2, 2, 2, 2, 2 };

	assert(unique(a1, nelem(a1)) == 7);
	assert(unique(a2, nelem(a2)) == 0.77);
	assert(unique(a3, nelem(a3)) == 0);
	assert(unique(a4, nelem(a4)) == 4);
	assert(unique(a5, nelem(a5)) == 0.5);
	assert(unique(a6, nelem(a6)) == 1);

	return 0;
}

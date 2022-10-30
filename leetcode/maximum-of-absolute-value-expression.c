/*

Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.



Constraints:

    2 <= arr1.length == arr2.length <= 40000
    -10^6 <= arr1[i], arr2[i] <= 10^6

Use the idea that abs(A) + abs(B) = max(A+B, A-B, -A+B, -A-B).

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
min(int a, int b)
{
	return (a < b) ? a : b;
}

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

int
dist(int *a, int *b, size_t n, int x, int y)
{
	size_t i;
	int p, q;

	p = INT_MAX;
	q = INT_MIN;
	for (i = 0; i < n; i++) {
		q = max(q, x * a[i] + y * b[i] + i);
		p = min(p, x * a[i] + y * b[i] + i);
	}
	return q - p;
}

int
maxabs(int *a, int *b, size_t n)
{
	static const int tab[][2] = {
		{ +1, +1 },
		{ +1, -1 },
		{ -1, +1 },
		{ -1, -1 },
	};

	size_t i;
	int r;

	r = INT_MIN;
	for (i = 0; i < nelem(tab); i++)
		r = max(r, dist(a, b, n, tab[i][0], tab[i][1]));
	return r;
}

int
main(void)
{
	int a1[] = { 1, 2, 3, 4 };
	int a2[] = { -1, 4, 5, 6 };

	int a3[] = { 1, -2, -5, 0, 10 };
	int a4[] = { 0, -2, -1, -7, -4 };

	assert(maxabs(a1, a2, nelem(a1)) == 13);
	assert(maxabs(a3, a4, nelem(a3)) == 20);

	return 0;
}

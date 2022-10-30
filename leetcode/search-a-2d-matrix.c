/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
findrow(size_t m, size_t n, int a[m][n], int v)
{
	size_t lo, hi, mid;

	if (n == 0)
		return SIZE_MAX;

	lo = 0;
	hi = m - 1;
	if (a[lo][0] <= v && v <= a[lo][n - 1])
		return lo;
	if (a[hi][0] <= v && v <= a[hi][n - 1])
		return hi;
	while (hi - lo != 1) {
		mid = lo + (hi - lo) / 2;
		if (a[mid][0] <= v && v <= a[mid][n - 1])
			return mid;

		if (a[mid][n - 1] < v)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

size_t
findcol(size_t m, size_t n, int a[m][n], size_t r, int v)
{
	size_t lo, hi, mid;

	if (n == 0)
		return SIZE_MAX;

	lo = 0;
	hi = n - 1;
	if (v <= a[r][lo])
		return lo;
	if (v > a[r][hi])
		return hi;
	while (hi - lo != 1) {
		mid = lo + (hi - lo) / 2;
		if (a[r][mid] < v)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

int
find(size_t m, size_t n, int a[m][n], int v, size_t *r, size_t *c)
{
	*r = findrow(m, n, a, v);
	if (*r == SIZE_MAX)
		return 0;

	*c = findcol(m, n, a, *r, v);
	if (*c == SIZE_MAX)
		return 0;

	return a[*r][*c] == v;
}

int
main(void)
{
	size_t r, c;
	int f;

	int m1[3][4] = {
	    {1, 3, 5, 7},
	    {10, 11, 16, 20},
	    {23, 30, 34, 50},
	};
	f = find(nelem(m1), nelem(m1[0]), m1, 3, &r, &c);
	printf("%d %zu %zu\n", f, r, c);

	f = find(nelem(m1), nelem(m1[0]), m1, 13, &r, &c);
	printf("%d %zu %zu\n", f, r, c);

	return 0;
}

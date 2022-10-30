/*

Write two functions:

    One that returns the maximum product of three numbers in a list.
    One that returns the minimum product of three numbers in a list.

Examples

max_product([-8, -9, 1, 2, 7]) ➞ 504

max_product([-8, 1, 2, 7, 9]) ➞ 126

min_product([1, -1, 1, 1]) ➞ -1

min_product([-5, -3, -1, 0, 4]) ➞ -15

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

#define minproduct(a, n) product(a, n, 0)
#define maxproduct(a, n) product(a, n, 1)

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
product(int *a, size_t n, int d)
{
	if (n < 3)
		return 0;

	qsort(a, n, sizeof(*a), cmp);
	if (d == 0)
		return min(a[0] * a[1] * a[2], a[0] * a[n - 1] * a[n - 2]);
	return max(a[n - 1] * a[n - 2] * a[n - 3], a[n - 1] * a[0] * a[1]);
}

int
main(void)
{
	int a1[] = {1, -1, 1};
	int a2[] = {1, -1, 1, 1};
	int a3[] = {-8, -9, 1, 2, 7};
	int a4[] = {-8, 1, 2, 7, 9};
	int a5[] = {1, 1, 5, 1, 1, -10, -1};
	int a6[] = {-8, -7, -6, -5};
	int a7[] = {-8, -7, -6, -5, 1};
	int a8[] = {1, 0, 1, 0, 0};
	int a9[] = {-5, 1, 10, 0, 0};
	int a10[] = {-5, -1, -1, 0, 0};
	int a11[] = {-5, 1, -1, 0, 0};
	int a12[] = {-5, -3, -1, 0, 4};
	int a13[] = {5, 3, -1, 0, -4, 7, 7, 9};

	assert(maxproduct(a1, nelem(a1)) == -1);
	assert(maxproduct(a2, nelem(a2)) == 1);
	assert(maxproduct(a3, nelem(a3)) == 504);
	assert(maxproduct(a4, nelem(a4)) == 126);
	assert(maxproduct(a5, nelem(a5)) == 50);
	assert(maxproduct(a6, nelem(a6)) == -210);
	assert(maxproduct(a7, nelem(a7)) == 56);
	assert(maxproduct(a8, nelem(a8)) == 0);
	assert(maxproduct(a9, nelem(a9)) == 0);
	assert(maxproduct(a10, nelem(a10)) == 0);
	assert(maxproduct(a11, nelem(a11)) == 5);
	assert(maxproduct(a12, nelem(a12)) == 60);
	assert(maxproduct(a13, nelem(a13)) == 441);

	assert(minproduct(a1, nelem(a1)) == -1);
	assert(minproduct(a2, nelem(a2)) == -1);
	assert(minproduct(a3, nelem(a3)) == -126);
	assert(minproduct(a4, nelem(a4)) == -504);
	assert(minproduct(a5, nelem(a5)) == -50);
	assert(minproduct(a6, nelem(a6)) == -336);
	assert(minproduct(a7, nelem(a7)) == -336);
	assert(minproduct(a8, nelem(a8)) == 0);
	assert(minproduct(a9, nelem(a9)) == -50);
	assert(minproduct(a10, nelem(a10)) == -5);
	assert(minproduct(a11, nelem(a11)) == 0);
	assert(minproduct(a12, nelem(a12)) == -15);
	assert(minproduct(a13, nelem(a13)) == -252);

	return 0;
}

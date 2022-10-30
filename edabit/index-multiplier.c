/*

Return the sum of all items in an array, where each item is multiplied by its index (zero-based).
For empty arrays, return 0.

Notes

All items in the array will be integers.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
indexmul(int *a, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++)
		r += i * a[i];
	return r;
}

int
main(void)
{
	int a1[] = {9, 3, 7, -7};
	int a2[] = {3, 8, 6, -4};
	int a3[] = {10, -9, -2, 0, 2};
	int a4[] = {4, 4, 2, 2, -4};
	int a5[] = {9, 4, 7, 5, -1, -3};
	int a6[] = {-9, 5, 9, 5, -7, 7};
	int a7[] = {7, 10, -5, -4, 6, 2};
	int a8[] = {0, 1, 0, 1, 0, 1, 0, 1};
	int a9[] = {-2, 5, -7, -23, 0, 14};
	int a10[] = {53, -43, 39, -2, -11, 3};
	int a11[] = {40, 32, -18, 48, -15};
	int a12[] = {1, -20, -11, 4, -12, 38, -30, 34};
	int a13[] = {-21, 30, 20, 6, -16};
	int a14[] = {8, -24, -8, -23, 20, 32, -29, -20};

	printf("%d\n", indexmul(a1, nelem(a1)));
	printf("%d\n", indexmul(a2, nelem(a2)));
	printf("%d\n", indexmul(a3, nelem(a3)));
	printf("%d\n", indexmul(a4, nelem(a4)));
	printf("%d\n", indexmul(a5, nelem(a5)));
	printf("%d\n", indexmul(a6, nelem(a6)));
	printf("%d\n", indexmul(a7, nelem(a7)));
	printf("%d\n", indexmul(a8, nelem(a8)));
	printf("%d\n", indexmul(a9, nelem(a9)));
	printf("%d\n", indexmul(a10, nelem(a10)));
	printf("%d\n", indexmul(a11, nelem(a11)));
	printf("%d\n", indexmul(a12, nelem(a12)));
	printf("%d\n", indexmul(a13, nelem(a13)));
	printf("%d\n", indexmul(a14, nelem(a14)));
	printf("%d\n", indexmul(a14, 0));
	return 0;
}

/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
binsearch(int a[], size_t n, int v)
{
	size_t lo, hi, mid;

	lo = 0;
	hi = n - 1;
	if (v <= a[lo])
		return lo;
	if (v > a[hi])
		return hi + 1;
	while (hi - lo != 1) {
		mid = lo + (hi - lo) / 2;
		if (a[mid] < v)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

int
main(void)
{
	int a1[] = {1, 3, 5, 6};
	printf("%zu\n", binsearch(a1, nelem(a1), 5));
	printf("%zu\n", binsearch(a1, nelem(a1), 2));
	printf("%zu\n", binsearch(a1, nelem(a1), 7));
	printf("%zu\n", binsearch(a1, nelem(a1), 0));
	printf("%zu\n", binsearch(a1, nelem(a1), -13));
	printf("%zu\n", binsearch(a1, nelem(a1), -425));
	printf("%zu\n", binsearch(a1, nelem(a1), -3));
	return 0;
}

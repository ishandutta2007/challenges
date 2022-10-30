/*

Create a function that searches for the index of a given item in an array. If the item is present, it should return the index, otherwise, it should return -1.
Examples

search([1, 2, 3, 4], 3) ➞ 2

search([2, 4, 6, 8, 10], 8) ➞ 3

search([1, 3, 5, 7, 9], 11) ➞ -1

Notes

    If the item is not present, return -1.
    The given array is ordered.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
search(int a[], ssize_t n, int v)
{
	ssize_t lo, hi, mid;

	if (n <= 0)
		return -1;

	lo = 0;
	hi = n - 1;
	if (v <= a[lo])
		return (a[lo] == v) ? lo : -1;
	if (v > a[hi])
		return -1;

	while (hi - lo != 1) {
		mid = lo + (hi - lo) / 2;
		if (a[mid] < v)
			lo = mid;
		else
			hi = mid;
	}

	return (a[hi] == v) ? hi : -1;
}

int
main(void)
{
	int a1[] = { 1, 2, 3, 4 };
	int a2[] = { 2, 4, 6, 8, 10 };
	int a3[] = { 1, 3, 5, 7, 9 };
	int a4[] = { 1, 5, 7, 11, 25, 100, 200, 350 };

	assert(search(a1, nelem(a1), 3) == 2);
	assert(search(a2, nelem(a2), 8) == 3);
	assert(search(a3, nelem(a3), 11) == -1);
	assert(search(a4, nelem(a4), 5) == 1);
	assert(search(a4, 0, 5) == -1);
	assert(search(a4, 1, 5) == -1);
	assert(search(a4, 2, 5) == 1);

	return 0;
}

/*

Create a function that returns true if an input array can be completely sorted by only sorting within the bounds [0, n] (inclusive),
where n is smaller than or equal to the array's length, and false otherwise.

Examples

boundSort([1, 6, 5, 3, 8, 9], [0, 3]) ➞ true
// If [1, 6, 5, 3] is sorted to [1, 3, 5, 6], the array is completely sorted.

boundSort([1, 6, 5, 3, 8, 9], [0, 2]) ➞ false
// Even if [1, 6, 5] is sorted to [1, 5, 6], the array is still not completely sorted.

boundSort([1, 9, 2, 5, 7], [0, 4]) ➞ true

boundSort([1, 9, 2, 5, 7], [0, 3]) ➞ false
// Sorting from [0, 3] gives us [1, 2, 5, 9, 7], array still not completely sorted.

Notes

    Numbers in array will be unique.
    The lower index of the bound will always be 0.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
boundsort(int *a, size_t n, size_t b[2])
{
	size_t i;
	int m;

	if (n == 0)
		return true;

	m = a[b[0]];
	for (i = b[0] + 1; i <= b[1]; i++) {
		if (m < a[i])
			m = a[i];
	}

	for (; i < n; i++) {
		if (m > a[i] || (i + 1 < n && a[i] > a[i + 1]))
			return false;
	}

	return true;
}

int
main(void)
{
	int a1[] = {1, 6, 5, 3, 8, 9};
	int a2[] = {1, 6, 5, 3, 8, 9};
	int a3[] = {1, 9, 2, 5, 7};
	int a4[] = {1, 9, 2, 5, 7};
	int a5[] = {1, 2, 3, 4, 5, 8, 9};
	int a6[] = {1, 2, 3, 5, 4, 8, 9};
	int a7[] = {1, 2, 3, 5, 4, 8, 9};

	assert(boundsort(a1, nelem(a1), (size_t[]){0, 3}) == true);
	assert(boundsort(a2, nelem(a2), (size_t[]){0, 2}) == false);
	assert(boundsort(a3, nelem(a3), (size_t[]){0, 4}) == true);
	assert(boundsort(a4, nelem(a4), (size_t[]){0, 3}) == false);
	assert(boundsort(a5, nelem(a5), (size_t[]){0, 1}) == true);
	assert(boundsort(a6, nelem(a6), (size_t[]){0, 4}) == true);
	assert(boundsort(a7, nelem(a7), (size_t[]){0, 3}) == false);

	return 0;
}

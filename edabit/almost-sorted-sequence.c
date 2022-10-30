/*

An almost-sorted sequence is a sequence that is strictly increasing or strictly decreasing if you remove a single element from the array (no more, no less).
Write a function that returns true if an array is almost-sorted, and false otherwise.

For example, if you remove 80 from the first example, it is perfectly sorted in ascending order.
Similarly, if you remove 7 from the second example, it is perfectly sorted in descending order.

Examples

almostSorted([1, 3, 5, 9, 11, 80, 15, 33, 37, 41] ) ➞ true

almostSorted([6, 5, 4, 7, 3]) ➞ true

almostSorted([6, 4, 2, 0]) ➞ false
// Sequence is already sorted.

almostSorted([7, 8, 9, 3, 10, 11, 12, 2]) ➞ false
// Requires removal of more than 1 item.

Notes

    Completely sorted arrays should return false.
    Arrays will always be > 3 in length (to remove ambiguity).
    Numbers in each input array will be unique - don't worry about "ties".

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

bool
cmp(int op, int x, int y)
{
	switch (op) {
	case '>':
		return x > y;
	case '<':
		return x < y;
	}
	return false;
}

ssize_t
badpair(int *a, ssize_t n, ssize_t k, int op)
{
	ssize_t i;

	if (0 < k && k < n - 1) {
		if (cmp(op, a[k - 1], a[k + 1]))
			return k - 1;
	}
	for (i = k + 1; i < n - 1; i++) {
		if (cmp(op, a[i], a[i + 1]))
			return i;
	}
	return -1;
}

bool
almost_monotonic(int *a, ssize_t n, int op)
{
	ssize_t j;

	j = badpair(a, n, -1, op);
	if (j == -1)
		return false;
	if (badpair(a, n, j, op) == -1)
		return true;
	if (badpair(a, n, j + 1, op) == -1)
		return true;
	return false;
}

// https://stackoverflow.com/questions/43017251/solve-almostincreasingsequence-codefights
bool
almost_sorted(int *a, ssize_t n)
{
	if (n < 3)
		return false;
	return almost_monotonic(a, n, '<') || almost_monotonic(a, n, '>');
}

int
main(void)
{
	int a1[] = {1, 3, 5, 9, 11, 80, 15, 33, 37, 41};
	int a2[] = {6, 5, 4, 7, 3};
	int a3[] = {6, 4, 2, 0};
	int a4[] = {7, 8, 9, 3, 10, 11, 12, 2};
	int a5[] = {9, 1, 8, 2};
	int a6[] = {1, 3, 9, 44, 15, 17, 33};
	int a7[] = {5, 4, 3, 2, -1, 0};
	int a8[] = {5, 2, 3, 4};
	int a9[] = {8, 3, 7, 4, 9};
	int a10[] = {-3, -4, -5, -7};
	int a11[] = {5, 6, 7, 8};
	int a12[] = {9, 1, 8, 2, 7, 3};

	assert(almost_sorted(a1, nelem(a1)) == true);
	assert(almost_sorted(a2, nelem(a2)) == true);
	assert(almost_sorted(a3, nelem(a3)) == false);
	assert(almost_sorted(a4, nelem(a4)) == false);
	assert(almost_sorted(a5, nelem(a5)) == true);
	assert(almost_sorted(a6, nelem(a6)) == true);
	assert(almost_sorted(a7, nelem(a7)) == true);
	assert(almost_sorted(a8, nelem(a8)) == true);
	assert(almost_sorted(a9, nelem(a9)) == false);
	assert(almost_sorted(a10, nelem(a10)) == false);
	assert(almost_sorted(a11, nelem(a11)) == false);
	assert(almost_sorted(a12, nelem(a12)) == false);

	return 0;
}

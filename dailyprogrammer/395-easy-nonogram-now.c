/*

This challenge is inspired by nonogram puzzles, but you don't need to be familiar with these puzzles in order to complete the challenge.

A binary array is an array consisting of only the values 0 and 1. Given a binary array of any length, return an array of positive integers that represent the lengths of the sets of consecutive 1's in the input array, in order from left to right.

nonogramrow([]) => []
nonogramrow([0,0,0,0,0]) => []
nonogramrow([1,1,1,1,1]) => [5]
nonogramrow([0,1,1,1,1,1,0,1,1,1,1]) => [5,4]
nonogramrow([1,1,0,1,0,0,1,1,1,0,0]) => [2,1,3]
nonogramrow([0,0,0,0,1,1,0,0,1,0,1,1,1]) => [2,1,3]
nonogramrow([1,0,1,0,1,0,1,0,1,0,1,0,1,0,1]) => [1,1,1,1,1,1,1,1]

As a special case, nonogram puzzles usually represent the empty output ([]) as [0]. If you prefer to do it this way, that's fine, but 0 should not appear in the output in any other case.

(This challenge is based on Challenge #59 [intermediate], originally posted by u/oskar_s in June 2012. Nonograms have been featured multiple times on r/dailyprogrammer since then (search).)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
nonogram(int *a, size_t n, size_t *p)
{
	size_t i, j, k;

	for (i = k = 0; i < n; i = j) {
		j = i + 1;
		while (j < n && a[i] == a[j])
			j++;

		if (a[i] == 1)
			p[k++] = j - i;
	}
	return k;
}

void
test(int *a, size_t n, size_t *r, size_t nr)
{
	size_t p[128], np;

	np = nonogram(a, n, p);
	assert(np == nr);
	assert(!memcmp(p, r, nr * sizeof(*r)));
}

int
main(void)
{
	int a1[] = {0, 0, 0, 0, 0};

	int a2[] = {1, 1, 1, 1, 1};
	size_t r2[] = {5};

	int a3[] = {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1};
	size_t r3[] = {5, 4};

	int a4[] = {1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0};
	size_t r4[] = {2, 1, 3};

	int a5[] = {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1};
	size_t r5[] = {2, 1, 3};

	int a6[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
	size_t r6[] = {1, 1, 1, 1, 1, 1, 1, 1};

	test(NULL, 0, NULL, 0);
	test(a1, nelem(a1), NULL, 0);
	test(a2, nelem(a2), r2, nelem(r2));
	test(a3, nelem(a3), r3, nelem(r3));
	test(a4, nelem(a4), r4, nelem(r4));
	test(a5, nelem(a5), r5, nelem(r5));
	test(a6, nelem(a6), r6, nelem(r6));

	return 0;
}

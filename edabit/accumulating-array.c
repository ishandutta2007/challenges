/*

Create a function that takes in an array and returns an array of the accumulating sum.
Examples

accumulatingArray([1, 2, 3, 4]) ➞ [1, 3, 6, 10]
// [1, 3, 6, 10] can be written as  [1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4]

accumulatingArray([1, 5, 7]) ➞ [1, 6, 13]

accumulatingArray([1, 0, 1, 0, 1]) ➞ [1, 1, 2, 2, 3]

accumulatingArray([]) ➞ []

Notes

An empty array input should return an empty array [].

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int *
accumulate(int *a, size_t n)
{
	size_t i;

	for (i = 1; i < n; i++)
		a[i] += a[i - 1];
	return a;
}

void
test(int *a, size_t n, int *b)
{
	accumulate(a, n);
	assert(memcmp(a, b, sizeof(*b) * n) == 0);
}

int
main(void)
{
	int a1[] = { 1, 2, 3, 4 };
	int b1[] = { 1, 3, 6, 10 };

	int a2[] = { 1, 5, 7 };
	int b2[] = { 1, 6, 13 };

	int a3[] = { 1, 0, 1, 0, 1 };
	int b3[] = { 1, 1, 2, 2, 3 };

	int a4[] = { 1, 1, 1, 1, 1 };
	int b4[] = { 1, 2, 3, 4, 5 };

	int a5[] = { 1, 0, 1, 0, 1 };
	int b5[] = { 1, 1, 2, 2, 3 };

	int a6[] = { 1, 2, 3, 0, 0, 1 };
	int b6[] = { 1, 3, 6, 6, 6, 7 };

	test(a1, nelem(a1), b1);
	test(a2, nelem(a2), b2);
	test(a3, nelem(a3), b3);
	test(a3, 0, b3);
	test(a4, nelem(a4), b4);
	test(a5, nelem(a5), b5);
	test(a6, nelem(a6), b6);

	return 0;
}

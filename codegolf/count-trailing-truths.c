/*

Inspired by, and in memory of, my dear friend and colleague,

Dan Baronet, 1956 – 2016. R.I.P.

He found the shortest possible APL solution to this task:
Task

Given a Boolean list, count the number of trailing truth values.
Example cases

{} → 0

{0} → 0

{1} → 1

{0, 1, 1, 0, 0} → 0

{1, 1, 1, 0, 1} → 1

{1, 1, 0, 1, 1} → 2

{0, 0, 1, 1, 1} → 3

{1, 1, 1, 1, 1, 1} → 6

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
truths(int *a, size_t n)
{
	size_t i, r;

	r = 0;
	for (i = n; i > 0 && a[i - 1]; i--)
		r++;
	return r;
}

int
main(void)
{
	int a1[] = {0};
	int a2[] = {1};
	int a3[] = {0, 1, 1, 0, 0};
	int a4[] = {1, 1, 1, 0, 1};
	int a5[] = {1, 1, 0, 1, 1};
	int a6[] = {0, 0, 1, 1, 1};
	int a7[] = {1, 1, 1, 1, 1, 1};

	assert(truths(NULL, 0) == 0);
	assert(truths(a1, nelem(a1)) == 0);
	assert(truths(a2, nelem(a2)) == 1);
	assert(truths(a3, nelem(a3)) == 0);
	assert(truths(a4, nelem(a4)) == 1);
	assert(truths(a5, nelem(a5)) == 2);
	assert(truths(a6, nelem(a6)) == 3);
	assert(truths(a7, nelem(a7)) == 6);

	return 0;
}

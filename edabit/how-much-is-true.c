/*

Create a function which returns the number of true values there are in an array.
Examples

countTrue([true, false, false, true, false]) ➞ 2

countTrue([false, false, false, false]) ➞ 0

countTrue([]) ➞ 0

Notes

    Return 0 if given an empty array.
    All array items are of the type bool (true or false).

*/

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
truths(bool *b, size_t n)
{
	size_t i, c;

	for (i = c = 0; i < n; i++)
		c += b[i];
	return c;
}

int
main(void)
{
	bool a1[] = { true, false, false, true, false };
	bool a2[] = { false, false, false, false };
	bool a3[] = { false, false, true, true, false, false, false, true, true, true, true, false, true, true, false };
	bool a4[] = { true, false, true, true, false, false, false, false, false };
	bool a5[] = { false, true, true, false, true, true, false, true, false, true, false, true, false, true, false };
	bool a6[] = { true, false, true, true, true, false, true, true, false, false };
	bool a7[] = { false, false, false, false, true, false, true, false, true, false, false };
	bool a8[] = { true, false, false, false, true, false, false, true, false, false, false };
	bool a9[] = { true, true, false, true, false, false, false, false, true, false };
	bool a10[] = { true, false, true, true, false, true, true, true, true, false, true, false, true, false };
	bool a11[] = { true, false, true, true, true, true, false, true, true, false, true, false, false, false, false };
	bool a12[] = { true, true, false, false, false, false, true, false, true, true, false, true };

	assert(truths(a1, nelem(a1)) == 2);
	assert(truths(a2, nelem(a2)) == 0);
	assert(truths(a2, 0) == 0);
	assert(truths(a3, nelem(a3)) == 8);
	assert(truths(a4, nelem(a4)) == 3);
	assert(truths(a5, nelem(a5)) == 8);
	assert(truths(a6, nelem(a6)) == 6);
	assert(truths(a7, nelem(a7)) == 3);
	assert(truths(a8, nelem(a8)) == 3);
	assert(truths(a9, nelem(a9)) == 4);
	assert(truths(a10, nelem(a10)) == 9);
	assert(truths(a11, nelem(a11)) == 8);
	assert(truths(a12, nelem(a12)) == 6);

	return 0;
}

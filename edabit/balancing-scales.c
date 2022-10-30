/*

Given an array with an odd number of elements, return whether the scale will tip "left" or "right" based on the sum of the numbers. The scale will tip on the direction of the largest total. If both sides are equal, return "balanced".
Examples

scaleTip([0, 0, "I", 1, 1]) ➞ "right"
// 0 < 2 so it will tip right

scaleTip([1, 2, 3, "I", 4, 0, 0]) ➞ "left"
// 6 > 4 so it will tip left

scaleTip([5, 5, 5, 0, "I", 10, 2, 2, 1]) ➞ "balanced"
// 15 = 15 so it will stay balanced

Notes

    The middle element will always be "I" so you can just ignore it.
    Assume the numbers all represent the same unit.
    Both sides will have the same number of elements.
    There are no such things as negative weights in both real life and the tests!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
scaletip(unsigned *a, size_t n)
{
	size_t i;
	unsigned l, r;

	if ((n & 1) == 0)
		return NULL;

	l = r = 0;
	for (i = 0; i < n / 2; i++) {
		l += a[i];
		r += a[n - i - 1];
	}

	if (l < r)
		return "right";
	if (l == r)
		return "balanced";
	return "left";
}

int
main(void)
{
	unsigned a1[] = { 0, 0, 'I', 1, 1 };
	unsigned a2[] = { 1, 2, 3, 'I', 4, 0, 0 };
	unsigned a3[] = { 5, 5, 5, 0, 'I', 10, 2, 2, 1 };
	unsigned a4[] = { 2, 3, 1, 'I', 6, 0, 0 };
	unsigned a5[] = { 500, 0, 0, 'I', 32, 53, 12 };
	unsigned a6[] = { 500, 0, 0, 'I', 302, 53, 12 };
	unsigned a7[] = { 50, 0, 0, 'I', 32, 53, 12 };
	unsigned a8[] = { 5, 'I', 3 };
	unsigned a9[] = { 500, 0, 0, 'I', 500, 0, 0 };
	unsigned a10[] = { 500, 0, 0, 0, 0, 0, 'I', 32, 53, 12, 0, 0, 0 };
	unsigned a11[] = { 1, 300, 'I', 300, 1 };
	unsigned a12[] = { 1, 300, 'I', 300, 2 };

	assert(strcmp(scaletip(a1, nelem(a1)), "right") == 0);
	assert(strcmp(scaletip(a2, nelem(a2)), "left") == 0);
	assert(strcmp(scaletip(a3, nelem(a3)), "balanced") == 0);
	assert(strcmp(scaletip(a4, nelem(a4)), "balanced") == 0);
	assert(strcmp(scaletip(a5, nelem(a5)), "left") == 0);
	assert(strcmp(scaletip(a6, nelem(a6)), "left") == 0);
	assert(strcmp(scaletip(a7, nelem(a7)), "right") == 0);
	assert(strcmp(scaletip(a8, nelem(a8)), "left") == 0);
	assert(strcmp(scaletip(a9, nelem(a9)), "balanced") == 0);
	assert(strcmp(scaletip(a10, nelem(a10)), "left") == 0);
	assert(strcmp(scaletip(a11, nelem(a11)), "balanced") == 0);
	assert(strcmp(scaletip(a12, nelem(a12)), "right") == 0);

	return 0;
}

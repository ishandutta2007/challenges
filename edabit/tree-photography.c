/*

Heading off to the Tree Arboretum of Various Heights, I bring along my camera to snap up a few photos.
Ideally, I'd want to take a picture of as many trees as possible, but the taller trees may cover up the shorter trees behind it.

A tree is hidden if it is shorter or the same height as the tree in front.

Given an array of tree heights, create a function which returns "left" or "right", depending on which side allows me to see as many trees as possible.

Worked Example

treePhotography([1, 3, 6, 5]) ➞ "left"
// If I stand on the left, I can see trees of heights 1, 3 and 6.
// If I stand on the right, I can see trees of heights 5 and 6.
// Return "left" because I would see more trees.

Examples

treePhotography([5, 6, 5, 4]) ➞ "right"

treePhotography([1, 2, 3, 3, 3, 3, 3]) ➞ "left"

treePhotography([3, 1, 4, 1, 5, 9, 2, 6]) ➞ "left"

Notes

There will always be a best side.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

const char *
trees(int *a, size_t n)
{
	size_t i, l, r;
	int x, y;

	if (n == 0)
		return "left";

	l = r = 1;
	x = a[0];
	y = a[n - 1];
	for (i = 1; i < n; i++) {
		l += (a[i] > x);
		r += (a[n - i - 1] > y);
		x = max(x, a[i]);
		y = max(y, a[n - i - 1]);
	}
	return (l >= r) ? "left" : "right";
}

void
test(int *a, size_t n, const char *r)
{
	const char *p;

	p = trees(a, n);
	assert(!strcmp(p, r));
}

int
main(void)
{
	int a1[] = {1, 3, 6, 5};
	int a2[] = {5, 6, 5, 4};
	int a3[] = {1, 2, 3, 3, 3, 3, 3};
	int a4[] = {3, 1, 4, 1, 5, 9, 2, 6};
	int a5[] = {1, 2, 3, 6, 5};
	int a6[] = {5, 6, 5, 4};
	int a7[] = {1, 1, 2, 2, 2, 2, 3};
	int a8[] = {1, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2};
	int a9[] = {3, 3, 3, 3, 2};
	int a10[] = {4, 3, 2, 3, 3, 3, 1};
	int a11[] = {3, 1, 4, 5, 2, 5, 1};
	int a12[] = {4, 3, 3, 4, 3, 1, 3};
	int a13[] = {5, 1, 2};
	int a14[] = {1, 2, 4, 1, 5, 3, 1};
	int a15[] = {1, 1, 1, 4, 1, 3, 5};
	int a16[] = {3, 1, 4, 1, 5, 9, 2, 6};

	test(a1, nelem(a1), "left");
	test(a2, nelem(a2), "right");
	test(a3, nelem(a3), "left");
	test(a4, nelem(a4), "left");
	test(a5, nelem(a5), "left");
	test(a6, nelem(a6), "right");
	test(a7, nelem(a7), "left");
	test(a8, nelem(a8), "left");
	test(a9, nelem(a9), "right");
	test(a10, nelem(a10), "right");
	test(a11, nelem(a11), "left");
	test(a12, nelem(a12), "right");
	test(a13, nelem(a13), "right");
	test(a14, nelem(a14), "left");
	test(a15, nelem(a15), "left");
	test(a16, nelem(a16), "left");

	return 0;
}

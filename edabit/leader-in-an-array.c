/*

Create a function that finds each number in the given array that is greater than every number that comes after it. Your solution should return an array of the number(s) that meet these criteria.
Examples

leader([2, 3, 20, 15, 8, 3]) ➞ [20, 15, 8, 3]
// Note that 20 is greater than all the elements to it's
// right side, similarly 15 and so on.

leader([2, 3, 20, 15, 8, 25, 3]) ➞ [25, 3]
// Note that 20 cannot be added because it is not greater than 25.

leader([1, 2, 3, 4, 5]) ➞ [5]
// 5 is technically greater than the (zero) remaining items.

leader([8, 7, 1, 2, 10, 3, 5]) ➞[10, 5]
// 10 is greater than all items to the right of it, so include.
// 3 is not greater than all items to the right of it, so exclude.
// 5 is greater than the remaining items, so include.

Notes
Add elements in the new array in the same order they occur in the input array.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
rev(int *p, size_t n)
{
	size_t i;
	int t;

	for (i = 0; i < n / 2; i++) {
		t = p[i];
		p[i] = p[n - i - 1];
		p[n - i - 1] = t;
	}
}

int *
leader(int *a, size_t n, size_t *l)
{
	size_t i, j;
	int *p, v;

	*l = 0;
	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	v = INT_MIN;
	for (i = j = 0; i < n; i++) {
		if (v < a[n - i - 1] || i == 0)
			p[j++] = v = a[n - i - 1];
	}
	*l = j;

	rev(p, *l);

	return p;
}

void
test(int *a, size_t na, int *b, size_t nb)
{
	size_t np;
	int *p;

	p = leader(a, na, &np);
	assert(np == nb && memcmp(p, b, nb * sizeof(*b)) == 0);
	free(p);
}

int
main(void)
{
	int a1[] = {2, 3, 20, 15, 8, 3};
	int b1[] = {20, 15, 8, 3};

	int a2[] = {2, 3, 20, 15, 8, 25, 3};
	int b2[] = {25, 3};

	int a3[] = {1, 2, 3, 4, 5};
	int b3[] = {5};

	int a4[] = {8, 7, 1, 2, 10, 3, 5};
	int b4[] = {10, 5};

	int a5[] = {2, 3, 20, 15, 26, 3};
	int b5[] = {26, 3};

	int a6[] = {1, 2, 3, 4, 3, 10};
	int b6[] = {10};

	int a7[] = {500, 400, 300, 200, 100, 50, 10, 5};
	int b7[] = {500, 400, 300, 200, 100, 50, 10, 5};

	test(a1, nelem(a1), b1, nelem(b1));
	test(a2, nelem(a2), b2, nelem(b2));
	test(a3, nelem(a3), b3, nelem(b3));
	test(a4, nelem(a4), b4, nelem(b4));
	test(a5, nelem(a5), b5, nelem(b5));
	test(a6, nelem(a6), b6, nelem(b6));
	test(a7, nelem(a7), b7, nelem(b7));

	return 0;
}

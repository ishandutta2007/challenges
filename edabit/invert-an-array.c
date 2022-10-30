/*

Create a function which takes an array of number arr and returns inverted array.
Examples

invertArray([1, 2, 3, 4, 5])) ➞ [-1, -2, -3, -4, -5]

invertArray([1, -2, 3, -4, 5] ➞ [-1, 2, -3, 4, -5]

invertArray([]) ➞ []

Notes

    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
invert(int *a, int *b, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		b[i] = -a[i];
}

void
test(int *a, int *b, size_t n)
{
	int c[n];

	invert(a, c, n);
	assert(!memcmp(c, b, sizeof(*b) * n));
}

int
main(void)
{
	int a1[] = {1, 2, 3, 4, 5};
	int b1[] = {-1, -2, -3, -4, -5};

	int a2[] = {1, -2, 3, -4, 5};
	int b2[] = {-1, 2, -3, 4, -5};

	int a3[] = {0};
	int b3[] = {0};

	test(a1, b1, nelem(a1));
	test(a2, b2, nelem(a2));
	test(NULL, NULL, 0);
	test(a3, b3, nelem(a3));

	return 0;
}

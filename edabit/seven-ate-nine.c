/*

A number can eat the number to the right of it if it's smaller than itself. After eating that number, it becomes the sum of itself and that number. Your job is to create a function that returns the final array after the leftmost element has finished "eating".
Examples

[5, 3, 7] ➞ [8, 7] ➞ [15]

// 5 eats 3 to become 8
// 8 eats 7 to become 15

[5, 3, 9] ➞ [8, 9]

// 5 eats 3 to become 8
// 8 cannot eat 9, since 8 < 9

nomNom([1, 2, 3]) ➞ [1, 2, 3]

nomNom([2, 1, 3]) ➞ [3, 3]

nomNom([8, 5, 9]) ➞ [22]

Notes

Test input contains only an array of numbers.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int *
nomnom(int *a, size_t n, size_t *l)
{
	size_t i, j;
	int *p;

	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	j = 0;
	p[j] = a[0];
	for (i = 1; i < n; i++) {
		if (p[j] > a[i])
			p[j] += a[i];
		else
			p[++j] = a[i];
	}

	*l = j + 1;
	return p;
}

void
test(int *a, size_t na, int *b, size_t nb)
{
	int *c;
	size_t nc;

	c = nomnom(a, na, &nc);
	assert(c && nc == nb && memcmp(c, b, sizeof(*b) * nb) == 0);
	free(c);
}

int
main(void)
{
	int a1[] = { 1, 2, 3 };
	int b1[] = { 1, 2, 3 };

	int a2[] = { 2, 1, 3 };
	int b2[] = { 3, 3 };

	int a3[] = { 8, 5, 9 };
	int b3[] = { 22 };

	int a4[] = { 5, 3, 7 };
	int b4[] = { 15 };

	int a5[] = { 5, 3, 9 };
	int b5[] = { 8, 9 };

	int a6[] = { 6, 5, 6, 100 };
	int b6[] = { 17, 100 };

	test(a1, nelem(a1), b1, nelem(b1));
	test(a2, nelem(a2), b2, nelem(b2));
	test(a3, nelem(a3), b3, nelem(b3));
	test(a4, nelem(a4), b4, nelem(b4));
	test(a5, nelem(a5), b5, nelem(b5));
	test(a6, nelem(a6), b6, nelem(b6));

	return 0;
}

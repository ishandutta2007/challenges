/*

A museum wants to get rid of some exhibitions. Vanya, the interior architect, comes up with a plan to remove the most boring exhibitions. She gives them a rating, and removes the one with the lowest rating. Just as she finishes rating the exhibitions, she's called off to an important meeting. She asks you to write a program that tells her the ratings of the items after the lowest one is removed.

Create a function that takes an array of integers and removes the smallest value.

Notes

    Don't change the order of the left over items.
    If you get an empty array, return an empty array: [] ➞ [].
    If there are multiple items with the same value, remove item with lower index (3rd example).

*/
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
rmdull(int *a, size_t n)
{
	size_t i, j;
	int v;

	if (n == 0)
		return 0;

	v = a[0];
	j = 0;
	for (i = 1; i < n; i++) {
		if (v > a[i]) {
			v = a[i];
			j = i;
		}
	}
	memmove(&a[j], &a[j + 1], sizeof(*a) * (n - j));
	return n - 1;
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
test(int *a, size_t n)
{
	n = rmdull(a, n);
	print(a, n);
}

int
main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	test(a, nelem(a));

	int b[] = {5, 3, 2, 1, 4};
	test(b, nelem(b));

	int c[] = {2, 2, 1, 2, 1};
	test(c, nelem(c));

	int d[] = {3, 1, 6, 7, 3, 7, 6};
	test(d, nelem(d));

	int e[] = {4, 4, 4, 1};
	test(e, nelem(e));

	int g[] = {5, 4, 5, 3, 1, 1};
	test(g, nelem(g));

	test(g, 0);

	int h[] = {6, 2, 5, 4, 8, 6, 3, 2, 7};
	test(h, nelem(h));

	int i[] = {3};
	test(i, nelem(i));

	return 0;
}

/*

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

This is a really easy problem if you decide to use additional memory.
For those trying to write an initial solution using additional memory, think counters!

However, the trick really is to not use any additional space than what is already available to use.
Sometimes, multiple passes over the input array help find the solution. However, there's an interesting piece of
information in this problem that makes it easy to re-use the input array itself for the solution.

The problem specifies that the numbers in the array will be in the range [1, n] where n is the number of elements in the array.
Can we use this information and modify the array in-place somehow to find what we need?

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int *
findmiss(int *a, size_t n, size_t *m)
{
	size_t i, j;
	int *p;

	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	for (i = 0; i < n; i++)
		p[i] = i + 1;

	for (i = 0; i < n; i++) {
		if (p[a[i] - 1] > 0)
			p[a[i] - 1] = -p[a[i] - 1];
	}

	for (i = j = 0; i < n; i++) {
		if (p[i] > 0)
			p[j++] = p[i];
	}

	*m = j;
	return p;
}

void
print(int *a, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i + 1 < n)
			printf(",");
	}
	printf("]\n");
}

void
test(int *a, size_t n)
{
	int *p;
	size_t m;

	p = findmiss(a, n, &m);
	if (p)
		print(p, m);
	free(p);
}

int
main(void)
{
	int a1[] = {4, 3, 2, 7, 8, 2, 3, 1};

	test(a1, nelem(a1));

	return 0;
}

/*

Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Note that the order of elements can be arbitrary.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

size_t
del(int *a, size_t n, int v)
{
	size_t i;

	for (i = 0; i < n; i++) {
		while (a[i] == v && n > i)
			swap(&a[i], &a[--n]);
	}
	return n;
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
main(void)
{
	int a[] = {3, 2, 2, 3};
	size_t n = del(a, nelem(a), 3);
	print(a, n);
	n = del(a, n, 2);
	print(a, n);

	int b[] = {0, 1, 2, 2, 3, 0, 4, 2};
	n = del(b, nelem(b), 2);
	print(b, n);
	n = del(b, n, 0);
	print(b, n);
	n = del(b, n, 1);
	print(b, n);
	n = del(b, n, 3);
	print(b, n);
	n = del(b, n, 4);
	print(b, n);

	return 0;
}

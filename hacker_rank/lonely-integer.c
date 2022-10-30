/*

You will be given an array of integers. All of the integers except one occur twice. That one is unique in the array.

Given an array of integers, find and print the unique element. 

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
lone(int *a, size_t n)
{
	size_t i;
	int v;

	v = 0;
	for (i = 0; i < n; i++)
		v ^= a[i];
	return v;
}

int
main(void)
{
	int a[] = {1, 2, 3, 4, 3, 2, 1};
	printf("%d\n", lone(a, nelem(a)));

	int b[] = {1};
	printf("%d\n", lone(b, nelem(b)));

	int c[] = {1, 1, 2};
	printf("%d\n", lone(c, nelem(c)));

	int d[] = {0, 0, 1, 2, 1};
	printf("%d\n", lone(d, nelem(d)));

	return 0;
}

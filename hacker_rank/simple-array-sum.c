// Given an array of integers, find the sum of its elements.
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
sum(int *a, size_t n)
{
	size_t i;
	int s;

	s = 0;
	for (i = 0; i < n; i++)
		s += a[i];
	return s;
}

int
main(void)
{
	int a[] = {1, 2, 3};
	printf("%d\n", sum(a, nelem(a)));

	int b[] = {1, 2, 3, 4, 10, 11};
	printf("%d\n", sum(b, nelem(b)));

	return 0;
}

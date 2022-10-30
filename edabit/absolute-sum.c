/*

Take an array of integers (positive or negative or both) and return the sum of the absolute value of each element.

Notes

The term "absolute value" means to remove any negative sign in front of a number, and to think of all numbers as positive (or zero).

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
abssum(int *a, size_t n)
{
	unsigned s;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++)
		s += abs(a[i]);
	return s;
}

int
main(void)
{
	int a1[] = {2, -1, 4, 8, 10};
	int a2[] = {-3, -4, -10, -2, -3};
	int a3[] = {2, 4, 6, 8, 10};
	int a4[] = {-1};
	int a5[] = {2, -1, -3, 4, 8};
	int a6[] = {-1, -3, -5, -4, -10, 0};
	int a7[] = {8, 9, 10, 32, 101, -10};
	int a8[] = {500};

	printf("%u\n", abssum(a1, nelem(a1)));
	printf("%u\n", abssum(a2, nelem(a2)));
	printf("%u\n", abssum(a3, nelem(a3)));
	printf("%u\n", abssum(a4, nelem(a4)));
	printf("%u\n", abssum(a5, nelem(a5)));
	printf("%u\n", abssum(a6, nelem(a6)));
	printf("%u\n", abssum(a7, nelem(a7)));
	printf("%u\n", abssum(a8, nelem(a8)));

	return 0;
}

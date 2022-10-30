/*

Create a function that takes an array and returns the first element.

Notes

The first element in an array always has an index of 0.

*/

#include <stdio.h>

int
first(int *a)
{
	return a[0];
}

int
main(void)
{
	int a1[] = { 1, 2, 3 };
	int a2[] = { 80, 5, 100 };
	int a3[] = { -500, 0, 50 };
	int a4[] = { 5, 2, 3 };
	int a5[] = { 75675, 5, 100 };
	int a6[] = { -52320, 0, 50 };

	printf("%d\n", first(a1));
	printf("%d\n", first(a2));
	printf("%d\n", first(a3));
	printf("%d\n", first(a4));
	printf("%d\n", first(a5));
	printf("%d\n", first(a6));

	return 0;
}

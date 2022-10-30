/*

Given two lines, determine whether or not they are parallel.

Lines are represented by an array [a, b, c], which corresponds to the line ax+by=c.

Notes

All the test cases use valid input (so no arrays of the wrong size, for example).
All the coefficients will be integers (whole numbers).

*/

#include <stdio.h>
#include <math.h>

int
islineparallel(int a[3], int b[3])
{
	// 2 lines are parallel if they have the same slope or they are both vertical
	// this implies a1/a2 = b1/b2
	// we can do some algebra to get the equation into a form
	// a1*b2 = b1*a2 to get rid of the floating point division
	return a[0] * b[1] == b[0] * a[1];
}

int
main(void)
{
	int a1[] = {1, 2, 3};
	int b1[] = {1, 2, 4};

	int a2[] = {2, 4, 1};
	int b2[] = {4, 2, 1};

	int a3[] = {0, 1, 5};
	int b3[] = {0, 1, 5};

	int a4[] = {2, 5, 0};
	int b4[] = {20, 50, 10};

	int a5[] = {2, 5, 0};
	int b5[] = {-200, -500, 10};

	int a6[] = {400000, 1, 0};
	int b6[] = {400000, 2, 0};

	int a7[] = {800, 20, 0};
	int b7[] = {40, 20, 0};

	int a8[] = {400000, 1, 0};
	int b8[] = {800000, 2, 100000};

	int a9[] = {-5, 7, 100000};
	int b9[] = {5, -7, -200000};

	printf("%d\n", islineparallel(a1, b1));
	printf("%d\n", islineparallel(a2, b2));
	printf("%d\n", islineparallel(a3, b3));
	printf("%d\n", islineparallel(a4, b4));
	printf("%d\n", islineparallel(a5, b5));
	printf("%d\n", islineparallel(a6, b6));
	printf("%d\n", islineparallel(a7, b7));
	printf("%d\n", islineparallel(a8, b8));
	printf("%d\n", islineparallel(a9, b9));

	return 0;
}

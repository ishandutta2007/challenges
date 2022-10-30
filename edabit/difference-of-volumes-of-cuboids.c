/*

Create a program that will take two arrays of integers, a and b. Each array will consist of 3 positive integers, representing the dimensions of cuboids a and b.
Find the difference of the cuboids' volumes.

For example, if the parameters passed are ([2, 2, 3], [5, 4, 1]), the volume of a is 12 and the volume of b is 20. Therefore, the function should return 8.
Examples

findDifference([ 28, 16, 29 ], [ 7, 8, 17 ]) ➞ 12040

findDifference([ 9, 22, 18 ], [ 16, 24, 10 ]) ➞ 276

findDifference([ 1, 9, 25 ], [ 10, 7, 9 ]) ➞ 405

findDifference([ 7, 6, 16 ], [ 26, 9, 26 ]) ➞ 5412

Notes

Each array element is greater than 0.

*/

#include <assert.h>
#include <stdio.h>

unsigned long
voldiff(unsigned long a[3], unsigned long b[3])
{
	unsigned long x, y;

	x = a[0] * a[1] * a[2];
	y = b[0] * b[1] * b[2];
	return (x < y) ? y - x : x - y;
}

int
main(void)
{
	unsigned long a1[] = {28, 16, 29};
	unsigned long b1[] = {7, 8, 17};

	unsigned long a2[] = {9, 22, 18};
	unsigned long b2[] = {16, 24, 10};

	unsigned long a3[] = {1, 9, 25};
	unsigned long b3[] = {10, 7, 9};

	unsigned long a4[] = {7, 6, 16};
	unsigned long b4[] = {26, 9, 26};

	unsigned long a5[] = {20, 19, 8};
	unsigned long b5[] = {5, 29, 1};

	unsigned long a6[] = {21, 6, 7};
	unsigned long b6[] = {25, 14, 17};

	unsigned long a7[] = {18, 29, 12};
	unsigned long b7[] = {24, 22, 4};

	unsigned long a8[] = {1, 16, 11};
	unsigned long b8[] = {26, 10, 17};

	unsigned long a9[] = {27, 11, 7};
	unsigned long b9[] = {2, 8, 26};

	unsigned long a10[] = {20, 17, 30};
	unsigned long b10[] = {20, 1, 13};

	unsigned long a11[] = {15, 7, 28};
	unsigned long b11[] = {3, 12, 11};

	unsigned long a12[] = {16, 17, 25};
	unsigned long b12[] = {18, 14, 28};

	unsigned long a13[] = {1, 3, 22};
	unsigned long b13[] = {12, 23, 16};

	unsigned long a14[] = {3, 29, 12};
	unsigned long b14[] = {4, 9, 6};

	unsigned long a15[] = {5, 18, 15};
	unsigned long b15[] = {16, 14, 26};

	unsigned long a16[] = {6, 14, 18};
	unsigned long b16[] = {30, 12, 22};

	assert(voldiff(a1, b1) == 12040);
	assert(voldiff(a2, b2) == 276);
	assert(voldiff(a3, b3) == 405);
	assert(voldiff(a4, b4) == 5412);
	assert(voldiff(a5, b5) == 2895);
	assert(voldiff(a6, b6) == 5068);
	assert(voldiff(a7, b7) == 4152);
	assert(voldiff(a8, b8) == 4244);
	assert(voldiff(a9, b9) == 1663);
	assert(voldiff(a10, b10) == 9940);
	assert(voldiff(a11, b11) == 2544);
	assert(voldiff(a12, b12) == 256);
	assert(voldiff(a13, b13) == 4350);
	assert(voldiff(a14, b14) == 828);
	assert(voldiff(a15, b15) == 4474);
	assert(voldiff(a16, b16) == 6408);

	return 0;
}

/*

Given an array of boxes, create a function that returns the total volume of all those boxes combined together. A box is represented by an array with three elements: length, width and height.

For instance, totalVolume([2, 3, 2], [6, 6, 7], [1, 2, 1]) should return 266 since (2 x 3 x 2) + (6 x 6 x 7) + (1 x 2 x 1) = 12 + 252 + 2 = 266.

Notes

    You will be given at least one box.
    Each box will always have three dimensions included.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
volume(unsigned a[][3], size_t n)
{
	size_t i;
	unsigned v;

	v = 0;
	for (i = 0; i < n; i++)
		v += a[i][0] * a[i][1] * a[i][2];
	return v;
}

int
main(void)
{
	unsigned v1[][3] = {
		{ 4, 2, 4 },
		{ 3, 3, 3 },
		{ 1, 1, 2 },
		{ 2, 1, 1 },
	};

	unsigned v2[][3] = {
		{ 2, 2, 2 },
		{ 2, 1, 1 },
	};

	unsigned v3[][3] = {
		{ 1, 1, 1 },
	};

	unsigned v4[][3] = {
		{ 5, 1, 10 },
		{ 1, 9, 2 },
	};

	unsigned v5[][3] = {
		{ 1, 1, 5 },
		{ 3, 3, 1 },
	};

	unsigned v6[][3] = {
		{ 2, 3, 2 },
		{ 6, 6, 7 },
		{ 1, 2, 1 },
	};

	printf("%u\n", volume(v1, nelem(v1)));
	printf("%u\n", volume(v2, nelem(v2)));
	printf("%u\n", volume(v3, nelem(v3)));
	printf("%u\n", volume(v4, nelem(v4)));
	printf("%u\n", volume(v5, nelem(v5)));
	printf("%u\n", volume(v6, nelem(v6)));

	return 0;
}

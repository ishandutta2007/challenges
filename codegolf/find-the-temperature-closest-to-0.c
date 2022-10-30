/*

In this exercise, you have to analyze records of temperature to find the closest to zero.

Write a program that prints the temperature closest to 0 among input data.

Input

N, the number of temperatures to analyse (optional). This will be nonzero.

The N temperatures expressed as integers ranging from -273 to 5526.

Output

Output the temperature closest to 0. If two temperatures are equally close, take the positive one. For instance, if the temperatures are -5 and 5, output 5.

Example

Input

    5
    1 -2 -8 4 5

Output

    1

This challenge is similar to this one on CodinGame, you can view the problem statement source here. Some modifications have been made to the text.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
nearestzero(int *a, size_t n)
{
	size_t i;
	int u, v;
	int r;

	r = INT_MAX;
	for (i = 0; i < n; i++) {
		u = abs(a[i]);
		v = abs(r);
		if (u < v || (u == v && a[i] > 0))
			r = a[i];
	}
	return r;
}

int
main(void)
{
	int a1[] = {1, -2, -8, 4, 5};
	int a2[] = {-5, 5, 10, 5, -5};
	int a3[] = {1, -2, 3, -4, 5, -6, 0};

	assert(nearestzero(a1, nelem(a1)) == 1);
	assert(nearestzero(a2, nelem(a2)) == 5);
	assert(nearestzero(a3, nelem(a3)) == 0);

	return 0;
}

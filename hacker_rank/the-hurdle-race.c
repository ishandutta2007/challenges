/*

Dan is playing a video game in which his character competes in a hurdle race.
Hurdles are of varying heights, and Dan has a maximum height he can jump.
There is a magic potion he can take that will increase his maximum height by 1 unit for each dose.
How many doses of the potion must he take to be able to jump all of the hurdles.

Given an array of hurdle heights height, and an initial maximum height Dan can jump k,
determine the minimum number of doses Dan must take to be able to clear all the hurdles in the race.

*/
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
hurdle(int *a, size_t n, int k)
{
	size_t i;
	int m, h;

	m = INT_MIN;
	for (i = 0; i < n; i++) {
		if (m < a[i])
			m = a[i];
	}

	h = 0;
	if (m > k)
		h = m - k;
	return h;
}

int
main(void)
{
	int a[] = {1, 2, 3, 3, 2};
	printf("%d\n", hurdle(a, nelem(a), 1));

	int b[] = {1, 6, 3, 5, 2};
	printf("%d\n", hurdle(b, nelem(b), 4));

	int c[] = {2, 5, 4, 5, 2};
	printf("%d\n", hurdle(c, nelem(c), 7));

	return 0;
}

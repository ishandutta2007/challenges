/*

Given a 6x6 2D array arr,
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

We define an hourglass in arr to be a subset of values with indices falling in this pattern in 's graphical representation:

a b c
  d
e f g

There are 16 hourglasses in arr, and an hourglass sum is the sum of an hourglass values.
Calculate the hourglass sum for every hourglass in arr, then print the maximum hourglass sum.

*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int
at(int a[6][6], int i, int j, bool *v)
{
	if (i < 0 || j < 0 || i >= 6 || j >= 6) {
		*v = false;
		return 0;
	}
	return a[i][j];
}

int
sum(int a[6][6], int i, int j, bool *v)
{
	int s;

	*v = true;
	s = at(a, i - 1, j - 1, v);
	s += at(a, i - 1, j, v);
	s += at(a, i - 1, j + 1, v);
	s += at(a, i, j, v);
	s += at(a, i + 1, j - 1, v);
	s += at(a, i + 1, j, v);
	s += at(a, i + 1, j + 1, v);
	return s;
}

int
hourglass(int a[6][6])
{
	int i, j, s, m;
	bool v;

	m = INT_MIN;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			s = sum(a, i, j, &v);
			if (v && m < s)
				m = s;
		}
	}
	return m;
}

int
main(void)
{
	int a[6][6] = {
	    {-9, -9, -9, 1, 1, 1},
	    {0, -9, 0, 4, 3, 2},
	    {-9, -9, -9, 1, 2, 3},
	    {0, 0, 8, 6, 6, 0},
	    {0, 0, 0, -2, 0, 0},
	    {0, 0, 1, 2, 4, 0},
	};
	printf("%d\n", hourglass(a));

	int b[6][6] = {
	    {1, 1, 1, 0, 0, 0},
	    {0, 1, 0, 0, 0, 0},
	    {1, 1, 1, 0, 0, 0},
	    {0, 0, 2, 4, 4, 0},
	    {0, 0, 0, 2, 0, 0},
	    {0, 0, 1, 2, 4, 0},
	};
	printf("%d\n", hourglass(b));

	return 0;
}

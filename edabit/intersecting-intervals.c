/*

Create a function that takes in a list of intervals and returns how many intervals overlap with a given point.

An interval overlaps a particular point if the point exists inside the interval, or on the interval's boundary. For example the point 3 overlaps with the interval [2, 4] (it is inside) and [2, 3] (it is on the boundary).

To illustrate:

count_overlapping([[1, 2], [2, 3], [1, 3], [4, 5], [0, 1]], 2) ➞ 3
# Since [1, 2], [2, 3] and [1, 3] all overlap with point 2

Notes

    Each interval is represented as a list with a start point and an endpoint.
    Intervals count as intersecting even if they only intersect at one point, i.e. [2, 3] and [3, 4] both intersect at point 3.
    If it's helpful, you can draw these intervals on a line on a piece of paper.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
overlaps(int r[][2], size_t n, int v)
{
	size_t i, c;

	for (i = c = 0; i < n; i++)
		c += (r[i][0] <= v && v <= r[i][1]);
	return c;
}

int
main(void)
{
	int r1[][2] = {{1, 2}, {2, 3}, {3, 4}};
	int r2[][2] = {{1, 2}, {5, 6}, {5, 7}};
	int r3[][2] = {{1, 2}, {5, 8}, {6, 9}};
	int r4[][2] = {{1, 5}, {2, 5}, {3, 6}, {4, 5}, {5, 6}};

	assert(overlaps(r1, nelem(r1), 5) == 0);
	assert(overlaps(r2, nelem(r2), 5) == 2);
	assert(overlaps(r3, nelem(r3), 7) == 2);
	assert(overlaps(r4, nelem(r4), 5) == 5);
	assert(overlaps(r4, nelem(r4), 6) == 2);
	assert(overlaps(r4, nelem(r4), 2) == 2);
	assert(overlaps(r4, nelem(r4), 1) == 1);

	return 0;
}

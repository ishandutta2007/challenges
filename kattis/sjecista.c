/*

Consider a convex polygon with N vertices, with the additional property that no three diagonals intersect in a single point. Find the number of intersections between pairs of diagonals in such a polygon.

The figure below shows one such polygon with 6 vertices.

Note that a polygon is convex if all of its interior angles are less than 180 degrees.

Input

The first and only line of input contains a single integer N,3≤N≤100 denoting the number of vertices.

Output

Output the number of intersections on a single line.

*/

#include <assert.h>
#include <stdio.h>

// https://oeis.org/A000332
int
intersections(int n)
{
	return n * (n - 1) * (n - 2) * (n - 3) / 24;
}

int
main(void)
{
	assert(intersections(3) == 0);
	assert(intersections(4) == 1);
	assert(intersections(6) == 15);

	return 0;
}

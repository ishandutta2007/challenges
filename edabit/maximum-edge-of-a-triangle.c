/*

Create a function that finds the maximum range of a triangle's third edge.

Notes

    (side1 + side2) - 1 = maximum range of third edge.
    The given triangles have side lengths that are positive integers.
    Don't forget to return the result.

*/

#include <stdio.h>

int
nextedge(int s1, int s2)
{
	return s1 + s2 - 1;
}

int
main(void)
{
	printf("%d\n", nextedge(8, 10));
	printf("%d\n", nextedge(5, 7));
	printf("%d\n", nextedge(9, 2));
	printf("%d\n", nextedge(5, 4));
	printf("%d\n", nextedge(8, 3));
	printf("%d\n", nextedge(7, 9));
	printf("%d\n", nextedge(10, 4));
	printf("%d\n", nextedge(7, 2));
	return 0;
}

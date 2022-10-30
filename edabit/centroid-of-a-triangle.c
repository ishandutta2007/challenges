/*

If you have a triangular shape cut from a piece of cardboard, the centroid of the triangle would be the spot where it balances on the point of a pencil.
The location of the centroid is easy to calculate if you know the x, y coordinates of the vertices:

    The x coordinate of the centroid is at (x1 + x2 + x3) / 3
    The y coordinate of the centroid is at (y1 + y2 + y3) / 3

x1, y1, x2, y2, x3, y3 are the coordinates of the three vertices.

Create a function that calculates the position of the centroid given the coordinates of the vertices. Round the answers to two decimal places.
If the three points given do not form a triangle, return False.

Notes

    The arguments are given in the order shown above: x1, y1, x2, y2, x3, y3.
    If the three points do not form a triangle, they must lie in a straight line.

*/

#include <stdio.h>

int
collinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) == 0;
}

int
centroid(int x1, int y1, int x2, int y2, int x3, int y3, double *xc, double *yc)
{
	if (collinear(x1, y1, x2, y2, x3, y3))
		return 0;
	*xc = (x1 + x2 + x3) / 3.0;
	*yc = (y1 + y2 + y3) / 3.0;
	return 1;
}

void
test(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double xc, yc;

	if (centroid(x1, y1, x2, y2, x3, y3, &xc, &yc))
		printf("(%.2f, %.2f)\n", xc, yc);
	else
		printf("False\n");
}

int
main(void)
{
	test(0, 0, 3, 0, 3, 3);
	test(5, 3, -3, -2, -1, 4);
	test(2, 2, 8, -2, 0, -3);
	test(5, 3, 5, -1, -4, 1);
	test(-1, -3, 1, 3, 2, 6);
	test(3, 0, 0, 3, 6, 3);
	test(1, 1, 2, 2, 3, 3);

	return 0;
}

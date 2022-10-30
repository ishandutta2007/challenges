/*

Create a function that returns True if three points belong to the same line, and False otherwise. Each point is represented by a list consisting of an x- and y-coordinate.

Examples

same_line([[0, 0], [1, 1], [3, 3]]) ➞ True

same_line([[-2, -1], [2, 1], [0, 0]]) ➞ True

same_line([[-2, 0], [-10, 0], [-8, 0]]) ➞ True

same_line([[0, 0], [1, 1], [1, 2]]) ➞ False

same_line([[3, 4], [3, 5], [6, 6]]) ➞ False

Notes

Note the special case of a vertical line.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

int
det3x3(int m[3][3])
{
	int d;
	int c00, c01, c02;
	int m00, m01, m02, m10, m11, m12, m20, m21, m22;

	m00 = m[0][0];
	m01 = m[0][1];
	m02 = m[0][2];
	m10 = m[1][0];
	m11 = m[1][1];
	m12 = m[1][2];
	m20 = m[2][0];
	m21 = m[2][1];
	m22 = m[2][2];
	c00 = m11 * m22 - m12 * m21;
	c01 = m12 * m20 - m10 * m22;
	c02 = m10 * m21 - m11 * m20;
	d = m00 * c00 + m01 * c01 + m02 * c02;
	return d;
}

int
collinear(Point p[3])
{
	int m[3][3] = {
	    {p[0].x, p[0].y, 1},
	    {p[1].x, p[1].y, 1},
	    {p[2].x, p[2].y, 1},
	};
	return det3x3(m) == 0;
}

int
main(void)
{
	Point p1[] = {{0, 0}, {1, 1}, {3, 3}};
	Point p2[] = {{-2, -1}, {2, 1}, {0, 0}};
	Point p3[] = {{-2, 0}, {-10, 0}, {-8, 0}};
	Point p4[] = {{0, 0}, {0, 5}, {0, 7}};
	Point p5[] = {{9, 9}, {8, 8}, {6, 6}};
	Point p6[] = {{0, 0}, {1, 1}, {1, 2}};
	Point p7[] = {{3, 4}, {3, 5}, {6, 6}};
	Point p8[] = {{9, 8}, {8, 8}, {6, 6}};

	assert(collinear(p1) == true);
	assert(collinear(p2) == true);
	assert(collinear(p3) == true);
	assert(collinear(p4) == true);
	assert(collinear(p5) == true);
	assert(collinear(p6) == false);
	assert(collinear(p7) == false);
	assert(collinear(p8) == false);

	return 0;
}

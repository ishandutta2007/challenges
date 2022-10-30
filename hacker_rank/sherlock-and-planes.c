/*

Watson gives four 3-dimensional points to Sherlock and asks him if they all lie in the same plane. Your task here is to help Sherlock.

Input Format
First line contains T, the number of testcases.
Each test case consists of four lines. Each line contains three integers, denoting xi yi zi.

Output Format
For each test case, print YES or NO whether all four points lie in same plane or not, respectively.

Constraints
1 ≤ T ≤ 104
-103 ≤ xi,yi,zi ≤ 103

Sample Input

1
1 2 0
2 3 0
4 0 0
0 0 0

Sample Output

YES

Explanation

All points have zi = 0, hence they lie in the same plane, and output is YES

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int x, y, z;
} Point;

Point
sub(Point a, Point b)
{
	return (Point){a.x - b.x, a.y - b.y, a.z - b.z};
}

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

// https://math.stackexchange.com/questions/1557144/how-to-prove-four-points-belong-to-the-same-plane
const char *
planar(Point p[4])
{
	Point a = sub(p[1], p[0]);
	Point b = sub(p[2], p[0]);
	Point c = sub(p[3], p[0]);
	int m[3][3] = {
	    {a.x, a.y, a.z},
	    {b.x, b.y, b.z},
	    {c.x, c.y, c.z},
	};
	return (det3x3(m) == 0) ? "YES" : "NO";
}

int
main(void)
{
	Point p1[] = {
	    {1, 2, 0},
	    {2, 3, 0},
	    {4, 0, 0},
	    {0, 0, 0},
	};
	Point p2[] = {
	    {1, 3, 4},
	    {5, 6, 1},
	    {3, 5, 100},
	    {49, 5, 6},
	};
	Point p3[] = {
	    {5, 5, 5},
	    {5, 5, 5},
	    {5, 5, 5},
	    {5, 5, 5},
	};

	assert(!strcmp(planar(p1), "YES"));
	assert(!strcmp(planar(p2), "NO"));
	assert(!strcmp(planar(p3), "YES"));

	return 0;
}

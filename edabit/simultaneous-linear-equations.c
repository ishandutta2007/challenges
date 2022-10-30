/*

Given two simultaneous linear equations in this form: a*x + b*y = c, d*x + e*y = f, devise a function that returns the values of x and y as (x, y).
The numbers a through f are non-zero integers. If there is not a unique solution or if there is no solution at all, return False.
Input is given as: [[a, b, c], [d, e, f]]. Solutions, if they exist, will be integers.

Notes

Can you do this without using numpy?

*/

#include <stdio.h>

int
det2(int m[2][2])
{
	return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

void
transform2(int m[2][2], int v[2], int r[2])
{
	r[0] = m[0][0] * v[0] + m[0][1] * v[1];
	r[1] = m[1][0] * v[0] + m[1][1] * v[1];
}

void
shrink2(int v[2], int d)
{
	v[0] /= d;
	v[1] /= d;
}

int
sle(int l[2][3], int r[2])
{
	int A[2][2] = {
	    {l[0][0], l[0][1]},
	    {l[1][0], l[1][1]},
	};
	int AI[2][2] = {
	    {l[1][1], -l[0][1]},
	    {-l[1][0], l[0][0]},
	};
	int b[2] = {l[0][2], l[1][2]};
	int d;

	d = det2(A);
	if (d == 0)
		return 0;
	transform2(AI, b, r);
	shrink2(r, d);

	return 1;
}

void
test(int l[2][3])
{
	int r[2];

	if (sle(l, r))
		printf("(%d, %d)\n", r[0], r[1]);
	else
		printf("False\n");
}

int
main(void)
{
	int l1[2][3] = {
	    {1, 2, -1},
	    {2, -3, 5},
	};
	int l2[2][3] = {
	    {3, -4, 1},
	    {2, 3, 12},
	};
	int l3[2][3] = {
	    {1, -4, 12},
	    {3, -12, 36},
	};
	int l4[2][3] = {
	    {3, 2, -4},
	    {2, 5, 1},
	};
	int l5[2][3] = {
	    {5, 3, -11},
	    {2, 4, -10},
	};
	int l6[2][3] = {
	    {3, 1, 38},
	    {3, 1, 83},
	};
	int l7[2][3] = {
	    {3, 4, 19},
	    {2, -1, 9},
	};
	int l8[2][3] = {
	    {3, 2, -2},
	    {2, 5, -5},
	};
	int l9[2][3] = {
	    {4, -3, 18},
	    {8, -6, 36},
	};
	int l10[2][3] = {
	    {2, 3, 13},
	    {5, -1, 7},
	};
	int l11[2][3] = {
	    {1, 2, 4},
	    {3, -5, 1},
	};

	test(l1);
	test(l2);
	test(l3);
	test(l4);
	test(l5);
	test(l6);
	test(l7);
	test(l8);
	test(l9);
	test(l10);
	test(l11);

	return 0;
}

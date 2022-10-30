/*

Inspired by this question

Another way to unroll a 2D image into a 1D string is to use an Hilbert Curve.

There are many version of this curve, depending on the number of iterations used while computing it. Below follow example of Hilbert Curves from first order to fifth order.

enter image description here

The way of computing this curve is the following. First we define the first order Hilbert Curve as the one shown in figure (the one for n = 1), so that it fits in a 1x1 square.
We than make four copies of this curve, spacing them in a 4x4 square, so that they all present the "concavity" towards the left side.
We then flip the two leftmost order 1 curves, so that the top one concavity faces toward the top, while the bottom's faces the bottom.
We finally connect the the corners of the adjacent Hilbert Curves. If wanting to obtain a (n+1)-order Curve, we just need to repeat the process with four n-order Curves.
We can see a visualisation of the process here (I will also add an image detailing the process soon)

Your task in this challenge is to unroll a matrix of integers along the lowest order Hilbert Curve for that matrix.

For simplicity's sake, we will have the curve starting from the top left corner of the matrix.

You can receive the input either as a list of list of integers, where each sub-list represents a row of the matrix.

You can assume that the input will be a square matrix (n*n).

For example:

Input:

[[ 1, 2,]
 [ 3, 4 ]]

Output:

[ 1, 2, 4, 3 ]

Since we are using the first order Hilbert Curve shown in figure

Input:

[[ 1, 2, 3, 4,    ]
 [ 5, 6, 7, 8,    ]
 [ 9, 10, 11, 12, ]
 [ 13, 14, 15, 16 ]]

Output:

[ 1, 5, 6, 2, 3, 4, 8, 7, 11, 12, 16, 15, 14, 10, 9, 13 ]

Using the second order Hilbert Curve

As usual, standard loopholes are not permitted.

*/

#include <stdio.h>

void
swap(int *x, int *y)
{
	int t;

	t = *y;
	*y = *x;
	*x = t;
}

void
rot(int n, int *x, int *y, int rx, int ry)
{
	if (ry == 0) {
		if (rx == 1) {
			*x = n - 1 - *x;
			*y = n - 1 - *y;
		}
		swap(x, y);
	}
}

int
xy2d(int n, int x, int y)
{
	int rx, ry, s, d;

	d = 0;
	for (s = n / 2; s > 0; s /= 2) {
		rx = (x & s) > 0;
		ry = (y & s) > 0;
		d += s * s * ((3 * rx) ^ ry);
		rot(n, &x, &y, rx, ry);
	}
	return d;
}

void
d2xy(int n, int d, int *x, int *y)
{
	int rx, ry, s, t;

	t = d;
	*x = *y = 0;
	for (s = 1; s < n; s *= 2) {
		rx = 1 & (t / 2);
		ry = 1 & (t ^ rx);
		rot(s, x, y, rx, ry);
		*x += s * rx;
		*y += s * ry;
		t /= 4;
	}
}

// https://en.wikipedia.org/wiki/Hilbert_curve
// this version goes from top left, bottom left, bottom right, top right
void
hilbert(int n, int m[n][n])
{
	int i, x, y;

	for (i = 0; i < n * n; i++) {
		d2xy(n, i, &x, &y);
		printf("%d ", m[y][x]);
	}
	printf("\n");
}

int
main(void)
{
	int m1[2][2] = {
	    {1, 2},
	    {3, 4},
	};
	int m2[4][4] = {
	    {1, 2, 3, 4},
	    {5, 6, 7, 8},
	    {9, 10, 11, 12},
	    {13, 14, 15, 16},
	};
	int m3[8][8] = {
	    {1, 2, 3, 4, 5, 6, 7, 8},
	    {9, 10, 11, 12, 13, 14, 15, 16},
	    {17, 18, 19, 20, 21, 22, 23, 24},
	    {25, 26, 27, 28, 29, 30, 31, 32},
	    {33, 34, 35, 36, 37, 38, 39, 40},
	    {41, 42, 43, 44, 45, 46, 47, 48},
	    {49, 50, 51, 52, 53, 54, 55, 56},
	    {57, 58, 59, 60, 61, 62, 63, 64},
	};

	hilbert(2, m1);
	hilbert(4, m2);
	hilbert(8, m3);

	return 0;
}

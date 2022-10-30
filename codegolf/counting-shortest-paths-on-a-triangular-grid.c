/*

Background

An Eisenstein integer is a complex number of the form z=a+bω where a,b are integers and ω is the third root of unity 1−3√i2.

The Eisenstein integers can be viewed as the triangular lattice points, as shown in the image below (from Wikipedia):

enter image description here

Following the triangular grid, one step of movement can be done in six directions:

Direction Step
E    1
NE   1 + w
NW   w
W   -1
SW  -1 - w
SE  -w

Task

Given an Eisenstein integer z, count all shortest paths from the origin (0) to the point equivalent to z

on the triangular grid.

Since z=a+bω can be represented by two integers a,b, you can take the input as two integers a,b

in any consistent order and structure of your choice.

One way to compute this is (thanks to @xnor):

Take the absolute values of [a, b, a-b], and call it L
Calculate binomial(max(L), any other value in L)

Test cases

 a  b  ans
 0  0    1
 2  0    1
 5  3   10
 4  4    1
 2  3    3
 0  2    1
-2  2    6
-4  0    1
-5 -3   10
-1 -1    1
-3 -5   10
 0 -3    1
 4 -1    5
-4 -9  126
 7 -4  330
 8  1    8
 3 -3   20

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

long
binomial(long n, long k)
{
	long i, c;

	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	k = min(k, n - k);
	c = 1;
	for (i = 0; i < k; i++)
		c = c * (n - i) / (i + 1);
	return c;
}

long
paths(long a, long b)
{
	long x, y, z;
	long n, k;

	x = labs(a);
	y = labs(b);
	z = labs(a - b);

	n = max(x, max(y, z));
	k = min(x, min(y, z));

	return binomial(n, k);
}

int
main(void)
{
	static long tab[][3] = {
	    {0, 0, 1},
	    {2, 0, 1},
	    {5, 3, 10},
	    {4, 4, 1},
	    {2, 3, 3},
	    {0, 2, 1},
	    {-2, 2, 6},
	    {-4, 0, 1},
	    {-5, -3, 10},
	    {-1, -1, 1},
	    {-3, -5, 10},
	    {0, -3, 1},
	    {4, -1, 5},
	    {-4, -9, 126},
	    {7, -4, 330},
	    {8, 1, 8},
	    {3, -3, 20},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(paths(tab[i][0], tab[i][1]) == tab[i][2]);

	return 0;
}

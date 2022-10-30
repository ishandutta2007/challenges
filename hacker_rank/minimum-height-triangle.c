/*

Given integers b and a, find the smallest integer h, such that there exists a triangle of height h, base b, having an area of at least a.

Example
b = 4
a = 6

The minimum height is 3. One example is a triangle formed at points (0, 0), (4, 0), (2, 3).

Function Description

Complete the lowestTriangle function in the editor below.

lowestTriangle has the following parameters:

int b: the base of the triangle
int a: the minimum area of the triangle

Returns

int: the minimum integer height to form a triangle with an area of at least
Input Format

There are two space-separated integers b and a, on a single line.

Constraints
1 <= b <= 10^6
1 <= a <= 10^6

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
minheight(int b, int a)
{
	return ceil(2.0 * a / b);
}

int
main(void)
{
	assert(minheight(2, 2) == 2);
	assert(minheight(17, 100) == 12);

	return 0;
}

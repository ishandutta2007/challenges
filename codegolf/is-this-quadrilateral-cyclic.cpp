/*

In mathematics, a cyclic quadrilateral is one whose vertices all lie on the same circle. In other words, every vertex is on the circumcircle of the other three. For more information, see the MathWorld article.

Examples

These quadrilaterals are cyclic:

Cyclic quadrilaterals

This trapezoid is not cyclic.

Trapezoid

(Images from Wikipedia)

Objective
Given the coordinates of four vertices in counterclockwise order which form a convex quadrilateral, determine if the quadrilateral is cyclic.

Coordinates will be integers (note, however, that the circumcenter coordinates and circumradius are not necessarily integers.) As implied by the previous paragraph, no three points will be co-linear and no two coincident.

I/O

You may take input using any reasonable format. In particular, [[x1,x2,x3,x4],[y1,y2,y3,y4]], [[x1,y1],[x2,y2],[x3,y3],[x4,y4]] and complex numbers are all fine.

Output using any different consistent values for true and false.

Test cases
True:

[0,0], [314,0], [314,1], [0,1]
[-5,5], [5,-5], [1337,42], [42,1337]
[104, -233], [109, -232], [112, -231], [123, -224]
False:

[0,0], [314,0], [314,100], [0,99]
[31,41],[59,26],[53,58],[0,314]

*/

#include <cassert>
#include <ccomplex>

using namespace std;

typedef complex<double> c128;

/*

https://en.wikipedia.org/wiki/Ptolemy%27s_theorem
In a quadrilateral, if the sum of the products of its two pairs of opposite sides is equal to the product of its diagonals,
then the quadrilateral can be inscribed in a circle.

*/
bool cyclic(c128 a, c128 b, c128 c, c128 d)
{
	auto ac = abs(a - c);
	auto bd = abs(b - d);
	auto ab = abs(a - b);
	auto cd = abs(c - d);
	auto bc = abs(b - c);
	auto ad = abs(a - d);
	return abs((ac * bd) - (ab * cd) - (bc * ad)) < 1e-8;
}

int main()
{
	assert(cyclic({ 0, 0 }, { 314, 0 }, { 314, 1 }, { 0, 1 }) == true);
	assert(cyclic({ -5, 5 }, { 5, -5 }, { 1337, 42 }, { 42, 1337 }) == true);
	assert(cyclic({ 104, -233 }, { 109, -232 }, { 112, -231 }, { 123, -224 }) == true);

	assert(cyclic({ 0, 0 }, { 314, 0 }, { 314, 100 }, { 0, 99 }) == false);
	assert(cyclic({ 31, 41 }, { 59, 26 }, { 53, 58 }, { 0, 314 }) == false);

	return 0;
}

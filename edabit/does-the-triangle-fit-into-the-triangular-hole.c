/*

Create a function that takes the dimensions of two triangles (as arrays) and checks if the first triangle fits into the second one.
Examples

doesTriangleFit([1, 1, 1], [1, 1, 1]) ➞ true

doesTriangleFit([1, 1, 1], [2, 2, 2]) ➞ true

doesTriangleFit([1, 2, 3], [1, 2, 2]) ➞ false

doesTriangleFit([1, 2, 4], [1, 2, 6]) ➞ false

Notes

    Triangle fits if it has the same or smaller size as the hole.
    The function should return false if the triangle with that dimensions is not possible.

*/

#include <assert.h>

double
area2(int s[3])
{
	double p;

	p = (s[0] + s[1] + s[2]) / 2.0;
	return p * (p - s[0]) * (p - s[1]) * (p - s[2]);
}

int
fit(int a[3], int b[3])
{
	double p, q;

	p = area2(a);
	q = area2(b);
	if (p <= 0 || q <= 0)
		return 0;
	return p <= q;
}

int
main(void)
{
	assert(fit((int[]){ 1, 1, 1 }, (int[]){ 1, 1, 1 }) == 1);
	assert(fit((int[]){ 1, 1, 1 }, (int[]){ 2, 2, 2 }) == 1);
	assert(fit((int[]){ 1, 2, 3 }, (int[]){ 1, 2, 2 }) == 0);
	assert(fit((int[]){ 1, 2, 4 }, (int[]){ 1, 2, 6 }) == 0);
	assert(fit((int[]){ 1, 6, 8 }, (int[]){ 1, 6, 8 }) == 0);
	assert(fit((int[]){ 12, 63, 42 }, (int[]){ 1, 6, 8 }) == 0);
	assert(fit((int[]){ 3, 6, 8 }, (int[]){ 23, 63, 42 }) == 1);
	assert(fit((int[]){ 3, 6, 8 }, (int[]){ 1, 10, 8 }) == 0);

	return 0;
}

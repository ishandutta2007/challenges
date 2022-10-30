/*

The left shift operation is similar to multiplication by powers of two, thus, the process is repetitive and can be done recursively.

Sample calculation using the left shift operator (<<):

10 << 3 = 10 * 2^3 = 10 * 8 = 80
-32 << 2 = -32 * 2^2 = -32 * 4 = -128
5 << 2 = 5 * 2^2 = 5 * 4 = 20

Write a recursive function that mimics (without the use of <<) the left shift operator and returns the result from the two given integers.
Examples

shiftToLeft(5, 2) ➞ 20

shiftToLeft(10, 3) ➞ 80

shiftToLeft(-32, 2) ➞ -128

shiftToLeft(-6, 5) ➞ -192

shiftToLeft(12, 4) ➞ 192

shiftToLeft(46, 6) ➞ 2944

Notes

There will be no negative values for the second parameter y.
This challenge is more like recreating of the left shift operation, thus, the use of the operator directly is prohibited.
You are expected to solve this challenge via recursion.
An iterative version of this challenge can be found via this link.
A collection of challenges in recursion can be found via this link.

*/

#include <assert.h>
#include <stdio.h>

int
shiftleft(int x, unsigned p)
{
	if (p == 0)
		return x;
	return shiftleft(x * 2, p - 1);
}

int
main(void)
{
	assert(shiftleft(5, 2) == 20);
	assert(shiftleft(10, 3) == 80);
	assert(shiftleft(-32, 2) == -128);
	assert(shiftleft(-6, 5) == -192);
	assert(shiftleft(12, 4) == 192);
	assert(shiftleft(46, 6) == 2944);
	assert(shiftleft(57, 0) == 57);
	assert(shiftleft(79, 1) == 158);

	return 0;
}

/*

Mubashir needs your help in a simple task. Create a function which takes two positive integers a and b.
These numbers are simultaneously decreased by 1 until the smaller one reaches 0.

During this process, the greater number can be divisible by the smaller one.
Your task is to count how many times it will happen.

Example 1

a = 3, b = 5  // 5 is not divisible by 3
a = 2, b = 4  // decreased by 1, 4 is divisible by 2
a = 1, b = 3  // decreased by 1, 3 is divisible by 1
a = 0, b = 2  // decreased by 1, the smaller number is 0, End

The result should be 2

Example 2

a = 8, b = 4  // 8 is divisible by 4
a = 7, b = 3  // decreased by 1, 7 is not divisible by 3
a = 6, b = 2  // decreased by 1, 6 is divisible by 2
a = 5, b = 1  // decreased by 1, 5 is divisible by 1
a = 4, b = 0  // decreased by 1, the smaller number is 0, End

The result should be 3

Examples

simpleCheck(3, 5) ➞ 2

simpleCheck(8, 4) ➞ 3

simpleCheck(54, 17) ➞ 1

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef unsigned long ulong;

ulong
crossings(ulong a, ulong b)
{
	ulong x, y, r;

	x = min(a, b);
	y = max(a, b);
	r = 0;
	while (x) {
		r += (y % x) == 0;
		x--;
		y--;
	}
	return r;
}

int
main(void)
{
	assert(crossings(3, 5) == 2);
	assert(crossings(10, 1) == 1);
	assert(crossings(7, 7) == 7);
	assert(crossings(16, 32) == 5);
	assert(crossings(42, 21) == 4);
	assert(crossings(54, 17) == 1);
	assert(crossings(150080ul, 150032ul) == 10);
	assert(crossings(8, 4) == 3);

	return 0;
}

/*

Write a function that takes an array of two numbers and determines if the sum of the digits in each number are equal to each other.

Examples

isEqual([105, 42]) ➞ true
# 1 + 0 + 5 = 6
# 4 + 2 = 6

isEqual([21, 35]) ➞ false

isEqual([0, 0]) ➞ true

Notes

N/A

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

unsigned long
count(unsigned long x)
{
	unsigned long r;

	for (r = 0; x; x /= 10)
		r += x % 10;
	return r;
}

bool
equal(unsigned long x, unsigned long y)
{
	return count(x) == count(y);
}

int
main(void)
{
	assert(equal(105, 42) == true);
	assert(equal(21, 35) == false);
	assert(equal(0, 0) == true);
	assert(equal(11, 20) == true);
	assert(equal(14, 21) == false);
	assert(equal(01, 10) == true);
	assert(equal(101, 201) == false);
	assert(equal(111111ul, 222) == true);
	assert(equal(23456ul, 5555) == true);

	return 0;
}

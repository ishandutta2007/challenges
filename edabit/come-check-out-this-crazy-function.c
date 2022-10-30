/*

You are given two numbers, a and b.
Write a function which uses an expression to return the expected output.
I am not going to tell you what the expression is because that will spoil the fun! :)

Examples

crazyfunction(10, 20) ➞ 30

crazyfunction(17, 35) ➞ 50

crazyfunction(61, 233) ➞ 212

Notes

Hint: Notice the tags?

*/

#include <assert.h>
#include <stdio.h>

unsigned long
crazy(unsigned long x, unsigned long y)
{
	return x ^ y;
}

int
main(void)
{
	assert(crazy(10, 20) == 30);
	assert(crazy(17, 35) == 50);
	assert(crazy(61, 233) == 212);
	assert(crazy(33, 47) == 14);
	assert(crazy(18, 209) == 195);
	assert(crazy(91, 54) == 109);
	assert(crazy(88, 123) == 35);
	assert(crazy(11, 8) == 3);
	assert(crazy(56, 80) == 104);
	assert(crazy(8, 45) == 37);
	assert(crazy(99, 201) == 170);
	assert(crazy(11, 78) == 69);
	assert(crazy(49, 139) == 186);
	assert(crazy(31, 50) == 45);
	assert(crazy(102, 113) == 23);
	assert(crazy(90, 500768ul) == 500858ul);

	return 0;
}

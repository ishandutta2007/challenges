/*

Create a function that takes an array of two numbers and checks if the square root of the first number is equal to the cube root of the second number.
Examples

checkSquareAndCube([4, 8]) ➞ true

checkSquareAndCube([16, 48]) ➞ false

checkSquareAndCube([9, 27]) ➞ true

Notes

    Remember to return either true or false.
    All arrays contain two positive numbers.

*/

#include <assert.h>
#include <stdbool.h>

bool
sac(int a[2])
{
	return a[0] * a[0] * a[0] == a[1] * a[1];
}

int
main(void)
{
	int a1[] = { 4, 8 };
	int a2[] = { 5, 12 };
	int a3[] = { 9, 27 };
	int a4[] = { 25, 120 };
	int a5[] = { 25, 125 };
	int a6[] = { 36, 215 };
	int a7[] = { 36, 217 };
	int a8[] = { 144, 1728 };
	int a9[] = { 1, 1 };
	int a10[] = { 676, 17576 };

	assert(sac(a1) == true);
	assert(sac(a2) == false);
	assert(sac(a3) == true);
	assert(sac(a4) == false);
	assert(sac(a5) == true);
	assert(sac(a6) == false);
	assert(sac(a7) == false);
	assert(sac(a8) == true);
	assert(sac(a9) == true);
	assert(sac(a10) == true);

	return 0;
}

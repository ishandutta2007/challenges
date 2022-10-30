/*

Write a function that takes a positive integer and calculates how many dots exist in a pentagonal shape around the center dot on the Nth iteration.

In the image below you can see the first iteration is only a single dot. On the second, there are 6 dots. On the third, there are 16 dots, and on the fourth there are 31 dots.

alt text

Return the number of dots that exist in the whole pentagon on the Nth iteration.
Examples

pentagonal(1) ➞ 1

pentagonal(2) ➞ 6

pentagonal(3) ➞ 16

pentagonal(8) ➞ 141

*/

#include <assert.h>
#include <stdio.h>

unsigned
pentagonal(unsigned n)
{
	return (5 * n * n - 5 * n + 2) / 2;
}

int
main(void)
{
	assert(pentagonal(1) == 1u);
	assert(pentagonal(3) == 16u);
	assert(pentagonal(8) == 141u);
	assert(pentagonal(10) == 226u);
	assert(pentagonal(15) == 526u);
	assert(pentagonal(33) == 2641u);
	assert(pentagonal(43) == 4516u);
	assert(pentagonal(13) == 391u);
	assert(pentagonal(50) == 6126u);
	assert(pentagonal(62) == 9456u);
	assert(pentagonal(21) == 1051u);

	return 0;
}

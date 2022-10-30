/*

Create a function that returns the mean of all digits.
Examples

mean(42) ➞ 3

mean(12345) ➞ 3

mean(666) ➞ 6

Notes

    The mean of all digits is the sum of digits / how many digits there are (e.g. mean of digits in 512 is (5+1+2)/3(number of digits) = 8/3=2).
    The mean will always be an integer.

*/

#include <assert.h>
#include <stdio.h>

unsigned
mean(unsigned x)
{
	int s, c;

	s = 0;
	c = 0;
	while (x) {
		s += x % 10;
		x /= 10;
		c++;
	}
	return (c) ? s / c : 0;
}

int
main(void)
{
	assert(mean(0) == 0);
	assert(mean(42) == 3);
	assert(mean(666) == 6);
	assert(mean(80) == 4);
	assert(mean(789) == 8);
	assert(mean(417) == 4);
	assert(mean(1357) == 4);
	assert(mean(42) == 3);
	assert(mean(12345) == 3);
	assert(mean(512) == 2);

	return 0;
}

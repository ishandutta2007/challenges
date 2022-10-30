/*

A number is considered slidey if for every digit in the number, the next digit from that has an absolute difference of one. Check the examples below.
Examples

is_slidey(123454321) ➞ true

is_slidey(54345) ➞ true

is_slidey(987654321) ➞ true

is_slidey(1123) ➞ false

is_slidey(1357) ➞ false

Notes

    A number cannot slide properly if there is a "flat surface" (example #4), or has gaps (example #5).
    All single digit numbers can be considered slidey numbers!

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool
slidey(unsigned long long n)
{
	int x, y;

	for (x = n % 10; n /= 10; x = y) {
		y = n % 10;
		if (abs(x - y) != 1)
			return false;
	}
	return true;
}

int
main(void)
{
	assert(slidey(123454321ull) == true);
	assert(slidey(54345ull) == true);
	assert(slidey(987654321ull) == true);
	assert(slidey(1123ull) == false);
	assert(slidey(1357ull) == false);
	assert(slidey(1ull) == true);
	assert(slidey(0ull) == true);
	assert(slidey(13578987ull) == false);
	assert(slidey(232323232ull) == true);
	assert(slidey(2323232322ull) == false);
	assert(slidey(2343456567878ull) == true);
	assert(slidey(999999999999ull) == false);
	assert(slidey(223322332233ull) == false);
	assert(slidey(7766554433ull) == false);
	assert(slidey(32ull) == true);
	assert(slidey(456ull) == true);
	assert(slidey(1045ull) == false);

	return 0;
}

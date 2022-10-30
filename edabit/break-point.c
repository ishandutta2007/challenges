/*

A number has a breakpoint if it can be split in a way where the digits on the left side and the digits on the right side sum to the same number.

For instance, the number 35190 can be sliced between the digits 351 and 90, since 3 + 5 + 1 = 9 and 9 + 0 = 9. On the other hand, the number 555 does not have a breakpoint (you must split between digits).

Create a function that returns true if a number has a breakpoint, and false otherwise.

Examples

BreakPoint(159780) ➞ true

BreakPoint(112) ➞ true

BreakPoint(1034) ➞ true

BreakPoint(10) ➞ false

BreakPoint(343) ➞ false

Notes

    Read each digit as only one number.
    Check the Resources tab for a hint.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned long long uvlong;

bool
breakpoint(uvlong v)
{
	int d[sizeof(v) * CHAR_BIT];
	int i, n, x, y, z;

	for (n = z = 0; v; v /= 10) {
		d[n] = v % 10;
		z += d[n++];
	}
	if (z & 1 || n < 2)
		return false;

	z /= 2;
	for (i = x = 0; i < n && x < z; i++)
		x += d[i];
	for (y = 0; i < n; i++)
		y += d[i];

	return x == z && y == z;
}

int
main(void)
{
	assert(breakpoint(35190ull) == true);
	assert(breakpoint(159780ull) == true);
	assert(breakpoint(112ull) == true);
	assert(breakpoint(1034ull) == true);
	assert(breakpoint(10ull) == false);
	assert(breakpoint(343ull) == false);
	assert(breakpoint(1119444ull) == true);
	assert(breakpoint(6666ull) == true);
	assert(breakpoint(9777771ull) == false);
	assert(breakpoint(3ull) == false);
	assert(breakpoint(6ull) == false);
	assert(breakpoint(0ull) == false);

	return 0;
}

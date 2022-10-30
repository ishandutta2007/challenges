/*

Deleted questions on Stack Overflow sometimes make for great golf material.

Write a function that takes a nonnegative integer as input, and returns true if all the digits in the base 10 representation of that number are unique. Example:

48778584 -> false
17308459 -> true

Character count includes only the function.

If you choose to answer in C or C++: no macros, no undefined behaviour; implementation-defined behaviour and compiler warnings are fine.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;

bool
uniq(uvlong n)
{
	uvlong d[10];

	memset(d, 0, sizeof(d));
	do {
		if (++d[n % 10] > 1)
			return false;
	} while (n /= 10);
	return true;
}

int
main(void)
{
	assert(uniq(48778584ull) == false);
	assert(uniq(17308459ull) == true);

	return 0;
}

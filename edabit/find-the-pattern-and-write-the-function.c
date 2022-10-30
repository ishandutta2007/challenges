/*

By looking at the inputs and outputs below, try to figure out the pattern and write a function to execute it for any number.

Examples

func(3456) ➞ 2

func(89265) ➞ 5

func(97) ➞ 12

func(2113) ➞ -9

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long uvlong;

long
func(uvlong x)
{
	char b[sizeof(x) * CHAR_BIT];
	int i, n;
	long r;

	r = 0;
	n = snprintf(b, sizeof(b), "%llu", x);
	for (i = 0; i < n; i++)
		r += (b[i] - '0') - n;
	return r;
}

int
main(void)
{
	assert(func(3456ull) == 2);
	assert(func(89265ull) == 5);
	assert(func(97ull) == 12);
	assert(func(2113ull) == -9);
	assert(func(55ull) == 6);
	assert(func(785428ull) == -2);
	assert(func(439ull) == 7);
	assert(func(55654ull) == 0);

	return 0;
}

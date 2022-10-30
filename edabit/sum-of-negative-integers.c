/*

Create a function that takes a string containing integers as well as other characters and return the sum of the negative integers only.

Examples

negative_sum("-12 13%14&-11") ➞ -23
# -12 + -11 = -23

negative_sum("22 13%14&-11-22 13 12") ➞ -33
# -11 + -22 = -33

Notes

There is at least one negative integer.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

long
negativesum(const char *s)
{
	char *ep;
	size_t i;
	long r, v;

	r = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '-') {
			errno = 0;
			v = strtol(s + i, &ep, 10);
			if ((errno == ERANGE && (v == LONG_MAX || v == LONG_MIN)) || (errno != 0 && v == 0))
				return 1;

			if (ep > s + i) {
				r += v;
				i = ep - s - 1;
			}
		}
	}
	return r;
}

int
main(void)
{
	assert(negativesum("-12 13%14&-11") == -23);
	assert(negativesum("-12 13%14&-2 0 12 -4") == -18);
	assert(negativesum("33%14&-1 12 a 21 -2 b c") == -3);
	assert(negativesum("22 13%14&-11-22 13 12") == -33);
	assert(negativesum("-12 -8") == -20);
	assert(negativesum("12 |||8*$!)8") == 0);

	return 0;
}

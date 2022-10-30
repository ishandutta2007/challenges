/*

Create a function that calculates the chance of being an imposter.
The formula for the chances of being an imposter is 100 × (i / p) where i is the imposter count and p is the player count.
Make sure to round the value to the nearest integer and return the value as a percentage.

Examples

imposterFormula(1, 10) ➞ "10%"

imposterFormula(2, 5) ➞ "40%"

imposterFormula(1, 8) ➞ "13%"

Notes

The player limit is 10 and the imposter count can only go up to 3.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
imposter(unsigned i, unsigned p, char *b, size_t n)
{
	snprintf(b, n, "%.0f%%", round(100.0 * i / p));
	return b;
}

void
test(unsigned i, unsigned p, const char *r)
{
	char b[128];

	imposter(i, p, b, sizeof(b));
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, 10, "10%");
	test(2, 5, "40%");
	test(1, 8, "13%");
	test(2, 10, "20%");
	test(3, 7, "43%");

	return 0;
}

/*

Lets assume for the purposes of this challenge that for every layer of fabric you wear when it's cold outside (coats, cardigans, etc), the temperature increases by a tenth of the total.

Given n number of layers and a given temperature, return the temperature inside of all those warm fuzzy layers. Round to the nearest tenth of a degree.

calcBundledTemp(2, "10*C") ➞ "12.1*C"
// 10 * 1.1 = 11
// 11 * 1.1 = 12.1

Examples

calcBundledTemp(1, "2*C") ➞ "2.2*C"

calcBundledTemp(4, "6*C") ➞ "8.8*C"

calcBundledTemp(20, "4*C") ➞ "26.9*C"

Notes

    The temperature will be given in celsius and as a string.
    Note that the degrees sign is given as an asterisk.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char *
bundle(unsigned n, const char *s, char *b)
{
	double r;

	r = pow(1.1, n) * atof(s);
	sprintf(b, "%.1f*C", r);
	return b;
}

void
test(unsigned n, const char *s, const char *r)
{
	char b[128];

	bundle(n, s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(2, "10*C", "12.1*C");
	test(1, "2*C", "2.2*C");
	test(4, "6*C", "8.8*C");
	test(20, "4*C", "26.9*C");
	test(5, "20*C", "32.2*C");
	test(20, "3*C", "20.2*C");
	test(5, "18*C", "29.0*C");
	test(4, "5*C", "7.3*C");
	test(16, "17*C", "78.1*C");
	test(15, "2*C", "8.4*C");
	test(14, "10*C", "38.0*C");

	return 0;
}

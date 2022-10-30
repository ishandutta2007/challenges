/*

Create a function that determines if the temp of the water is considered boiling or not.
temp will be measured in fahrenheit and celsius.

Examples

isBoiling("212F") ➞ true

isBoiling("100C") ➞ true

isBoiling("0F") ➞ false

Notes

The boiling point of water is 212F in fahrenheit and 100C in celsius.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool
isboiling(const char *s)
{
	double v;
	char *ep;

	v = strtod(s, &ep);
	if (ep) {
		if (!strcmp(ep, "F"))
			return v >= 212;
		if (!strcmp(ep, "C"))
			return v >= 100;
	}
	return false;
}

int
main(void)
{
	assert(isboiling("212F") == true);
	assert(isboiling("100C") == true);
	assert(isboiling("0F") == false);
	assert(isboiling("-1F") == false);
	assert(isboiling("213F") == true);
	assert(isboiling("104C") == true);
	assert(isboiling("-10F") == false);

	return 0;
}

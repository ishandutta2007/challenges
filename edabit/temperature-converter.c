/*

Create a function that converts Celsius to Fahrenheit and vice versa.
Examples

convert("35*C") ➞ "95*F"

convert("19*F") ➞ "-7*C"

convert("33") ➞ "Error"

Notes

    Round to the nearest integer.
    If the input is incorrect, return "Error".
    For the formulae to convert back and forth, check the Resources tab.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
convert(const char *s, char *b, size_t n)
{
	int v, r;
	char u;

	r = sscanf(s, "%d*%c", &v, &u);
	if (r != 2 || (u != 'C' && u != 'F')) {
		snprintf(b, n, "Error");
		return b;
	}

	if (u == 'C')
		snprintf(b, n, "%ld*F", lrint(v * 9.0 / 5 + 32));
	else
		snprintf(b, n, "%ld*C", lrint((v - 32) * 5.0 / 9));

	return b;
}

void
test(const char *s, const char *t)
{
	char b[80];

	convert(s, b, sizeof(b));
	assert(strcmp(b, t) == 0);
}

int
main(void)
{
	test("35*C", "95*F");
	test("18*C", "64*F");
	test("0*F", "-18*C");
	test("100*C", "212*F");
	test("69*F", "21*C");
	test("159*C", "318*F");
	test("-40*C", "-40*F");
	test("16*C", "61*F");
	test("500*C", "932*F");
	test("33", "Error");
	test("19*F", "-7*C");
	test("85*C", "185*F");
	test("0*C", "32*F");
	test("1777*F", "969*C");
	test("-90*C", "-130*F");
	test("-9*C", "16*F");
	test("180*C", "356*F");
	test("7K", "Error");
	test("100*F", "38*C");

	return 0;
}

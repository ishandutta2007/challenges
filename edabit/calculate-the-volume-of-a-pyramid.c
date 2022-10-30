/*

Create a function that takes the length, width, height (in meters) and output unit and returns the volume of a pyramid to three decimal places in the correct unit.
Examples

pyramidVolume(4, 6, 20, "centimeters") ➞ "160000000.000 cubic centimeters"

pyramidVolume(1843, 1823, 923, "kilometers") ➞ "1.034 cubic kilometers"

pyramidVolume(18, 412, 93, "millimeters") ➞ "229896000000000.000 cubic millimeters"

Notes

The units used are limited to: millimeters, centimeters, meters and kilometers.
Ensure you return the answer and add the correct unit in the format cubic <unit>.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
pydvol(double l, double w, double h, const char *u, char *b)
{
	double v;

	v = l * w * h / 3;
	if (!strcmp(u, "millimeters"))
		v *= 1e9;
	else if (!strcmp(u, "centimeters"))
		v *= 1e6;
	else if (!strcmp(u, "kilometers"))
		v /= 1e9;
	sprintf(b, "%.3f cubic %s", v, u);
	return b;
}

void
test(double l, double w, double h, const char *u, const char *r)
{
	char b[128];

	pydvol(l, w, h, u, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(4, 6, 20, "centimeters", "160000000.000 cubic centimeters");
	test(1843, 1823, 923, "kilometers", "1.034 cubic kilometers");
	test(18, 412, 93, "millimeters", "229896000000000.000 cubic millimeters");
	test(10, 14, 6, "meters", "280.000 cubic meters");
	test(8, 12, 2, "centimeters", "64000000.000 cubic centimeters");
	test(92, 1245, 1923, "kilometers", "0.073 cubic kilometers");
	test(19, 254, 21, "millimeters", "33782000000000.000 cubic millimeters");
	test(13.6, 62.2, 6, "meters", "1691.840 cubic meters");
	test(4230, 923, 1932, "kilometers", "2.514 cubic kilometers");

	return 0;
}

/*

In electronics, a digital-to-analog converter (DAC, D/A, or D-to-A) is a system that converts a binary representation of that signal into an analog output.
An 8 bit converter can represent a maximum of 2^8 different values, with each successive value differing by 1/256 of the full scale value,
this becomes the system resolution and would be approximately 0.25% of the full range.

Create a function that takes a binary output reading and returns the analog voltage level that would create that DAC reading.

This DAC has 10 bits of resolution and the DAC reference is at 5.00 volts.
Examples

adc(11111111) ➞ 5

adc(00000000) ➞ 0

adc(0110010000) ➞ 1.96

Notes

You should return your value rounded to two decimal places.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
adc(unsigned n)
{
	return n / 1023.0 * 5;
}

void
eq(double x, double y)
{
	assert(fabs(x - y) < 1e-2);
}

int
main(void)
{
	eq(adc(1023), 5);
	eq(adc(0), 0);
	eq(adc(500), 2.44);
	eq(adc(400), 1.96);
	eq(adc(850), 4.15);

	return 0;
}

/*

Given a pH value, return whether that value is 'alkaline', 'acidic', or 'neutral'.
Return 'invalid' if the value given is less than 0 or greater than 14.

Notes

Values such as 6.9999 and 7.00001 should return 'acidic' and 'alkaline' respectively.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
phname(double x)
{
	if (x < 0 || x > 14)
		return "invalid";
	if (x < 7)
		return "acidic";
	if (x > 7)
		return "alkaline";
	return "neutral";
}

int
main(void)
{
	assert(!strcmp(phname(7.0), "neutral"));
	assert(!strcmp(phname(7), "neutral"));
	assert(!strcmp(phname(13.52), "alkaline"));
	assert(!strcmp(phname(-4.33), "invalid"));
	assert(!strcmp(phname(8.27), "alkaline"));
	assert(!strcmp(phname(9.72), "alkaline"));
	assert(!strcmp(phname(-4.58), "invalid"));
	assert(!strcmp(phname(14.85), "invalid"));
	assert(!strcmp(phname(17.76), "invalid"));
	assert(!strcmp(phname(3.9), "acidic"));
	assert(!strcmp(phname(14.21), "invalid"));
	assert(!strcmp(phname(-2.35), "invalid"));
	assert(!strcmp(phname(2.66), "acidic"));
	assert(!strcmp(phname(16.45), "invalid"));
	assert(!strcmp(phname(3.46), "acidic"));
	assert(!strcmp(phname(7.26), "alkaline"));
	assert(!strcmp(phname(12.46), "alkaline"));
	assert(!strcmp(phname(17.51), "invalid"));
	assert(!strcmp(phname(19.7), "invalid"));
	assert(!strcmp(phname(10.46), "alkaline"));
	assert(!strcmp(phname(-4.83), "invalid"));
	assert(!strcmp(phname(3.13), "acidic"));
	assert(!strcmp(phname(11.38), "alkaline"));
	assert(!strcmp(phname(5.23), "acidic"));
	assert(!strcmp(phname(18.85), "invalid"));
	assert(!strcmp(phname(15.82), "invalid"));
	assert(!strcmp(phname(9.17), "alkaline"));
	assert(!strcmp(phname(2.73), "acidic"));
	assert(!strcmp(phname(10.99), "alkaline"));
	assert(!strcmp(phname(-3.86), "invalid"));
	assert(!strcmp(phname(17.59), "invalid"));
	assert(!strcmp(phname(5.5), "acidic"));
	assert(!strcmp(phname(-3.35), "invalid"));
	assert(!strcmp(phname(16.02), "invalid"));
	assert(!strcmp(phname(8.78), "alkaline"));
	assert(!strcmp(phname(18.94), "invalid"));
	assert(!strcmp(phname(-4.69), "invalid"));
	assert(!strcmp(phname(0.86), "acidic"));
	assert(!strcmp(phname(-3.45), "invalid"));
	assert(!strcmp(phname(19.05), "invalid"));
	assert(!strcmp(phname(5.41), "acidic"));
	assert(!strcmp(phname(0.44), "acidic"));
	assert(!strcmp(phname(8.82), "alkaline"));
	assert(!strcmp(phname(-1.24), "invalid"));
	assert(!strcmp(phname(1.72), "acidic"));
	assert(!strcmp(phname(10.01), "alkaline"));
	assert(!strcmp(phname(3.49), "acidic"));
	assert(!strcmp(phname(13.62), "alkaline"));
	assert(!strcmp(phname(3.43), "acidic"));
	assert(!strcmp(phname(4.35), "acidic"));
	assert(!strcmp(phname(17.07), "invalid"));
	assert(!strcmp(phname(14.64), "invalid"));

	return 0;
}

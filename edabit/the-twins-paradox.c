/*

Jack and Jill are twins. When they are 10 years of age, Jack leaves earth in his spaceship bound for Altair IV, some 17 light-years distant.
Though not equipped with warp drive, Jack's ship is still capable of attaining near light speed.
When he returns to earth he finds that Jill has grown to adulthood while he, Jack, remains a young boy.

Albert Einstein had predicted this strange quirk of time in his 1905 paper "On the Electrodynamics of Moving Bodies" aka The Theory of Special Relativity.
It has been verified experimentally many times.

Implement a function that has as its arguments: The twins' age at the time of Jack's departure, the distance in light-years to the destination star,
and the speed of Jack's ship as a fraction of the speed of light.

The function will return Jack's age and Jill's age at the time of Jack's return to earth,
rounded to the nearest tenth of a year. The math is simple enough for 10-year-old Jack to understand. See Resources for help.

Examples

twins(20, 10, 0.4) ➞ "Jack's age is 65.8, Jill's age is 70.0"

twins(20, 10, 0.8) ➞ "Jack's age is 35.0, Jill's age is 45.0"

twins(10, 16. 73, 0.999) ➞ "Jack's age is 11.5, Jill's age is 43.5"
// The Altair IV trip.

Notes

We are assuming for the sake of simplicity that Jack's periods of acceleration and deceleration are negligibly brief.
That is a huge assumption but, nevertheless, it doesn't invalidate the age calculations.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
twins(double a, double d, double v, char *b, size_t n)
{
	double ja, jl, t;

	t = 2 * d / v;
	jl = a + t;
	ja = a + t * sqrt(1 - v * v);

	snprintf(b, n, "Jack's age is %.1f, Jill's age is %.1f", ja, jl);
	return b;
}

void
test(double a, double d, double v, const char *s)
{
	char b[80];

	twins(a, d, v, b, sizeof(b));
	assert(!strcmp(b, s));
}

int
main(void)
{
	test(20, 10, 0.4, "Jack's age is 65.8, Jill's age is 70.0");
	test(20, 10, 0.8, "Jack's age is 35.0, Jill's age is 45.0");
	test(10, 16.73, 0.999, "Jack's age is 11.5, Jill's age is 43.5");
	test(1, 5, 0.1, "Jack's age is 100.5, Jill's age is 101.0");
	test(25, 30, 0.99999, "Jack's age is 25.3, Jill's age is 85.0");

	return 0;
}

/*

One cause for speeding is the desire to shorten the time spent traveling. While in long distance trips speeding does save an appreciable amount of time, the same cannot be said about short distance trips.

Create a function that calculates the amount of time saved (in minutes) were you traveling with an average speed that is above the speed-limit as compared to traveling with an average speed exactly at the speed-limit.
Examples

// The paramater's format is as follows:
// (speed limit, avg speed, distance traveled at avg speed)

timeSaved(80, 90, 40) ➞ 3.3

timeSaved(80, 90, 4000) ➞ 333.3

timeSaved(80, 100, 40 ) ➞ 6.0

timeSaved(80, 100, 10) ➞ 1.5

Notes

    Speed = distance/time
    The time returned should be in minutes, not in hours!

*/

#include <assert.h>
#include <math.h>

double
timesaved(int l, int s, int d)
{
	double t1, t2;

	t1 = d * 60.0 / l;
	t2 = d * 60.0 / s;
	return t1 - t2;
}

void
eq(double x, double y)
{
	assert(fabs(x - y) < 1e-1);
}

int
main(void)
{
	eq(timesaved(80, 90, 40), 3.3);
	eq(timesaved(80, 90, 4000), 333.3);
	eq(timesaved(80, 100, 40), 6.0);
	eq(timesaved(80, 100, 10), 1.5);
	eq(timesaved(60, 65, 25), 1.9);
	eq(timesaved(60, 60, 20), 0);
	eq(timesaved(80, 95, 200), 23.7);
	eq(timesaved(70, 92, 50), 10.2);
	eq(timesaved(70, 92, 20), 4.1);
	eq(timesaved(70, 100, 12), 3.1);

	return 0;
}

/*

Like so many good stories, this one begins with a claim that Kari is a faster runner than Ola, who of course challenges Kari to a run-down.
Dubbed (rather ironically) Non-Competitive Pace Challenge, they want to see who can run the furthest in a certain amount of time t.
Clearly they both choose to run in straight lines with constant speed.

Kari wrote an app to make sure that Ola does not cheat, but the app requires that their phones constantly communicate over Bluetooth.

After their run, Kari needs to ensure that they were never too far apart from each other at any time during the run. Write a program that computes the maximum distance between Kari and Ola at any point during the run.

Input

The input consists of a single line containing eight integers describing four points:

    the starting position of Kari,

    the starting position of Ola,

    the ending position of Kari, and

    the ending position of Old

in that order. Each point is given by two integers x and y (0≤x,y≤10^4), the coordinates of the point.

Output

Output the maximum distance between Kari and Ola during their run, with an absolute or relative error of at most 10^-6.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

double
maxdist(double x1, double y1, double x2, double y2, double X1, double Y1, double X2, double Y2)
{
	double d1, d2;

	d1 = hypot(x2 - x1, y2 - y1);
	d2 = hypot(X2 - X1, Y2 - Y1);
	return max(d1, d2);
}

void
test(double x1, double y1, double x2, double y2, double X1, double Y1, double X2, double Y2, double r)
{
	double d;

	d = maxdist(x1, y1, x2, y2, X1, Y1, X2, Y2);
	printf("%f\n", d);
	assert(fabs(d - r) < 1e-8);
}

int
main(void)
{
	test(0, 0, 0, 0, 1, 1, 2, 2, 1.4142135624);
	test(0, 0, 0, 1, 0, 2, 2, 1, 2.2360679775);
	test(5, 0, 10, 0, 5, 0, 10, 0, 5);
	return 0;
}

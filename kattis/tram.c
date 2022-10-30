/*

It is 1815 and the politicians in Lund have just decided to build a tram line in Lund. Oh, sorry. That was wrong, let’s start over. It is 2015 and the politicians in Lund have just decided to build a tram line in Lund.

The politicians have already decided that the tram line should run from south-east to north-west.
In order not to cause too many complaints from the citizens, they want to make the line as useful as possible.
Therefore they want to minimize the total unusefulness of the tram.

The unusefulness for citizen i is equal to the square of the closest distance from the citizen’s home to the tram line.
The total unusefulness of the tram is the sum of all citizens’ unusefulnesses.

Given the coordinates of each citizen’s home, determine the value a minimizing the total unusefulnes, where the equation of the tram line is given by y=x+a.

Input

The first line of input consists of an integer, 1≤N≤105, the number of citizens in Lund.
Then follow N lines, with two space-separated integers xi,yi (|xi|,|yi|≤106), the coordinates of citizen i’s home.

Output

The output consists of a single number, a, minimizing the total unusefulness.
An answer will be accepted if it is within an absolute or relative error of 10^-3.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

double
usefulness(Point *p, size_t n)
{
	size_t i;
	double r;

	if (n == 0)
		return 0;

	r = 0;
	for (i = 0; i < n; i++)
		r += p[i].y - p[i].x;
	return r * 1.0 / n;
}

void
test(Point *p, size_t n, double r)
{
	double v;

	v = usefulness(p, n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-3);
}

int
main(void)
{
	Point p1[] = {
	    {1, 1},
	    {2, 2},
	    {3, 3},
	};
	Point p2[] = {
	    {0, 1},
	    {1, 0},
	    {1, 1},
	};
	Point p3[] = {
	    {0, 2},
	    {1, 1},
	    {1, 0},
	};

	test(p1, nelem(p1), 0);
	test(p2, nelem(p2), 0);
	test(p3, nelem(p3), 0.333333);
	return 0;
}

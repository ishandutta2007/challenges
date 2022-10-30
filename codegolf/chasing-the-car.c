/*

Imagine you are sitting at a park. Suddenly your car gets hijacked and being driven in different directions. Here are the directions, arrows show which direction goes towards where:

     South
       |
       V
East->   <-West
       ^
       | 
     North

After being driven, the car stops. Now you have to find out how far the car is away from you and angle of you and your car in degrees.
It will be given how many units have been driven and in which direction.
Input/Output format is flexible, you can take a 2D list/1D list/string etc and return the displacement and angle.

Test Cases

[[40,East],[40,North],[30,West],[30,South]] -> 14.1421356237 45.0
[[45,North],[200,East]] -> 205.0 75.9637565321

No need to output exact angle and distance, just 2 digits after decimal is fine, but more than 2 is fine too.

Only given directions are North, east, south, west.

The value of movement in a direction is always positive integer.

Trailing Whitespace allowed. Code golf, so shortest code wins.

My English is bad, sorry. Please ask for clarification if you have trouble understanding

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define rad2deg(x) ((x)*180 / M_PI)

typedef struct {
	double units;
	char direction[32];
} Waypoint;

void
carchase(Waypoint *w, size_t n, double *d, double *a)
{
	Waypoint *p;
	double x, y;
	size_t i;

	x = y = 0;
	for (i = 0; i < n; i++) {
		p = w + i;
		if (!strcmp(p->direction, "North"))
			y += p->units;
		else if (!strcmp(p->direction, "South"))
			y -= p->units;
		else if (!strcmp(p->direction, "East"))
			x += p->units;
		else if (!strcmp(p->direction, "West"))
			x -= p->units;
	}

	*d = hypot(x, y);
	*a = rad2deg(atan2(x, y));
}

void
test(Waypoint *w, size_t n)
{
	double d, a;

	carchase(w, n, &d, &a);
	printf("%.6f %.2f\n", d, a);
}

int
main(void)
{
	Waypoint w1[] = {
	    {40, "East"},
	    {40, "North"},
	    {30, "West"},
	    {30, "South"},
	};
	Waypoint w2[] = {
	    {45, "North"},
	    {200, "East"},
	};

	test(w1, nelem(w1));
	test(w2, nelem(w2));

	return 0;
}

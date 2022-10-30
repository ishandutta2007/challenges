/*

I read about circles somewhere, and just now learned about discs (it's actually a pretty common concept) and thought about codegolf.

Your task is to randomize a point/several points on a disc with the radius 1.

Rules:

    All points must have an equal probability to be generated
    Floating point coordinates must be used; the minimum requirement is two decimals (e.g. the points (0.12, -0.45) or (0.00, -1.00) are valid)
    You get -20 bytes if your program actually displays the bounding circle and the point(s) generated in it. Coordinates still has to be valid but not displayed, and the image generated has to be at least 201 by 201 pixels in size
    You get -5 bytes if your program takes the number of points to be generated as input on stdin
    If you decide not to plot the bounding circle and the point(s), your program has to output the point(s) generated on the format (x, y) or (x,y) on stdout
    If you decide to take the number of generated points as input, but not to plot it - your program has to output all the randomized points on the format stated above with or without one space in between

Shortest submission in bytes wins!

*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
	double x, y;
} Point;

Point
discp(void)
{
	double r, a;

	r = sqrt(drand48());
	a = drand48() * 2 * M_PI;
	return (Point){
	    .x = r * cos(a),
	    .y = r * sin(a),
	};
}

int
main(void)
{
	Point p;
	int i;

	srand48(time(NULL));
	for (i = 0; i < 256; i++) {
		p = discp();
		printf("(%.3f, %.3f) %.3f\n", p.x, p.y, hypot(p.x, p.y));
	}

	return 0;
}

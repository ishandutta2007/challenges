/*

Chef want to book Ola Cab,he have to take ride from point one (xi,yi) to second point (xj,yj),
Ola cost N rupees per unit, Chef have R rupees in his pocket,
You have to help Chef to find Whether he have suffiecient amount of money in his pocket for paying to ola,

if yes print “yes”(without quotes) else print “no”(without quotes)

*/
#include <stdio.h>
#include <math.h>

typedef struct {
	int x, y;
} Point;

const char *
rideout(Point p, Point q, int n, int r)
{
	double d;

	d = hypot(q.x - p.x, q.y - p.y);
	return (d * n <= r) ? "yes" : "no";
}

int
main(void)
{
	Point a = {4, 6};
	Point b = {1, 3};
	printf("%s\n", rideout(a, b, 20, 80));
	return 0;
}

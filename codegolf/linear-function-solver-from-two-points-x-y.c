/*

The Task

Write a function L() that takes two Tuple arguments of coordinates in the form (x, y), and returns their respective linear function in the form (a, c), where a is the co-efficent of the x term and c is the y-intercept.

You can assume that the input will not be a line perpendicular the the x axis, and that the two inputs are separate points.
Scoring 

This is Code Golf: shortest program wins.

Please Note: No use of any mathematical functions apart from basic operators (+,-,/,*).
Example

Here is my un-golfed solution in Python.

def L(Point1, Point2):
    x = 0
    y = 1
    Gradient = (float(Point1[y]) - float(Point2[y])) / (float(Point1[x]) - float(Point2[x]))
    YIntercept = Point1[y] - Gradient * Point1[x] 
    return (Gradient, YIntercept)

Output:

>>> L( (0,0) , (1,1) )
(1.0, 0.0)

>>> L( (0,0) , (2,1) )
(0.5, 0.0)

>>> L( (0,0) , (7,1) )
(0.14285714285714285, 0.0)

>>> L( (10,22.5) , (5,12.5) )
(2.0, 2.5)

*/

#include <stdio.h>

typedef struct {
	double x, y;
} Point;

int
L(Point a, Point b, double r[2])
{
	if (a.x == b.x) {
		r[0] = r[1] = 0;
		return -1;
	}

	r[0] = (a.y - b.y) / (a.x - b.x);
	r[1] = a.y - r[0] * a.x;
	return 0;
}

void
test(Point a, Point b)
{
	double r[2];

	L(a, b, r);
	printf("%f %f\n", r[0], r[1]);
}

int
main(void)
{
	test((Point){0, 0}, (Point){1, 1});
	test((Point){0, 0}, (Point){2, 1});
	test((Point){0, 0}, (Point){7, 1});
	test((Point){10, 22.5}, (Point){5, 12.5});

	return 0;
}

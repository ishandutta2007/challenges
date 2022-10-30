/*

Every quadratic curve y = a x² + b x + c has a vertex point: the turning point where the curve stops heading down and starts going up.

Given the values a, b and c, you need to return the coordinates of the vertex. Return your answers rounded to 2 decimal places.

Notes

    See Resources if you're not sure how to find the x or y coordinates of the vertex.
    a will always be non-zero.

*/

#include <stdio.h>

typedef struct {
	double x, y;
} Vertex;

Vertex
findvertex(double a, double b, double c)
{
	double x, y;

	if (a == 0)
		return (Vertex){0, 0};

	x = -b / (2 * a);
	y = a * x * x + b * x + c;
	return (Vertex){x, y};
}

void
printvertex(Vertex v)
{
	printf("[%.2f, %.2f]\n", v.x, v.y);
}

int
main(void)
{
	printvertex(findvertex(1, 0, 25));
	printvertex(findvertex(-1, 0, 25));
	printvertex(findvertex(1, 10, 25));
	printvertex(findvertex(8, 4, 0));
	printvertex(findvertex(4, -200, 1000));
	printvertex(findvertex(1, -50, -1000));
	printvertex(findvertex(-1, 20, 600));
	printvertex(findvertex(5, 1, 20));
	return 0;
}

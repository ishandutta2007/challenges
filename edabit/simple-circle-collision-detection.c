/*

Create a function that returns True if the given circles are intersecting, otherwise return False. The circles are given as two lists containing the values in the following order:

Radius of the circle.
Center position on the x-axis.
Center position on the y-axis.

*/

#include <stdio.h>

typedef struct {
	int r, x, y;
} Circle;

int
ccc(Circle p, Circle q)
{
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) <= (p.r + q.r) * (p.r + q.r);
}

int
main(void)
{
	printf("%d\n", ccc((Circle){10, 0, 0}, (Circle){10, 10, 10}));
	printf("%d\n", ccc((Circle){10, 0, 0}, (Circle){5, 0, 0}));
	printf("%d\n", ccc((Circle){1, 0, 0}, (Circle){1, 0, 0}));
	printf("%d\n", ccc((Circle){5, 0, 0}, (Circle){5, 10, 10}));
	printf("%d\n", ccc((Circle){1, 0, 0}, (Circle){1, 10, 10}));
	return 0;
}

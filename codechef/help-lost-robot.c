/*

Robot Bunny is lost. It wants to reach its home as soon as possible. Currently it is standing at coordinates (x1, y1) in 2-D plane.
Its home is at coordinates (x2, y2). Bunny is extremely worried. Please help it by giving a command by telling the direction in which it should to go so as to reach its home.
If you give it a direction, it will keep moving in that direction till it reaches its home.
There are four possible directions you can give as command - "left", "right", "up", "down".
It might be possible that you can't instruct the robot in such a way that it reaches its home. In that case, output "sad".

*/

#include <stdio.h>

typedef struct {
	int x, y;
} Point;

const char *
path(Point p, Point q)
{
	if (p.x == q.x && p.y == q.y)
		return "happy";
	if (p.x == q.x)
		return (p.y < q.y) ? "up" : "down";
	if (p.y == q.y)
		return (p.x < q.x) ? "right" : "left";
	return "sad";
}

int
main(void)
{
	Point x = {0, 0};
	Point y = {1, 0};
	printf("%s\n", path(x, y));

	y = (Point){0, 1};
	printf("%s\n", path(x, y));

	y = (Point){1, 1};
	printf("%s\n", path(x, y));

	x = (Point){3, 4};
	y = (Point){5, 6};
	printf("%s\n", path(x, y));

	y = (Point){3, -400};
	printf("%s\n", path(x, y));

	x = (Point){6, -400};
	printf("%s\n", path(x, y));

	return 0;
}

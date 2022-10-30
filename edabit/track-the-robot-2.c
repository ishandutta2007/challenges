/*

This robot roams around a 2D grid. It starts at (0, 0) facing North. After each time it moves, the robot rotates 90 degrees clockwise.
Given the amount the robot has moved each time, you have to calculate the robot's final position.

To illustrate, if the robot is given the movements 20, 30, 10, 40 then it will move:

    20 steps North, now at (0, 20)
    30 steps East, now at (30, 20)
    10 steps South. now at (30, 10)
    40 steps West, now at (-10, 10)

...and will end up at coordinates (-10, 10).

Notes

Each movement is an integer (whole number).

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

Point
track(int *a, size_t n)
{
	Point p;
	size_t i;

	p.x = p.y = 0;
	for (i = 0; i < n; i++) {
		switch (i & 3) {
		case 0: // north
			p.y += a[i];
			break;
		case 1: // east
			p.x += a[i];
			break;
		case 2: // south
			p.y -= a[i];
			break;
		case 3: // west
			p.x -= a[i];
			break;
		}
	}
	return p;
}

void
test(int *a, size_t n)
{
	Point p;

	p = track(a, n);
	printf("[%d, %d]\n", p.x, p.y);
}

int
main(void)
{
	int a1[] = {20, 30, 10, 40};
	int a2[] = {10, -10, -10, 10};
	int a3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a4[] = {1, 0, 2, 0, 3, 0, 4, 0, 5, 0};
	int a5[] = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5};

	test(a1, nelem(a1));
	test(a2, nelem(a2));
	test(a2, 0);
	test(a3, nelem(a3));
	test(a4, nelem(a4));
	test(a5, nelem(a5));

	return 0;
}

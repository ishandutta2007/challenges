/*

A robot has been given a list of movement instructions. Each instruction is either left, right, up or down, followed by a distance to move. The robot starts at [0, 0]. You want to calculate where the robot will end up and return its final position as a list.

To illustrate, if the robot is given the following instructions:

["right 10", "up 50", "left 30", "down 10"]

It will end up 20 left and 40 up from where it started, so we return [-20, 40].

Notes

    The only instructions given will be left, right, up or down.
    The distance after the instruction is always a positive whole number.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

Point
track(const char **s, size_t n)
{
	Point p;
	char d[8];
	int t;
	size_t i;

	p.x = p.y = 0;
	for (i = 0; i < n; i++) {
		if (sscanf(s[i], "%7s %d", d, &t) != 2)
			continue;

		if (!strcmp(d, "up"))
			p.y += t;
		else if (!strcmp(d, "down"))
			p.y -= t;
		else if (!strcmp(d, "left"))
			p.x -= t;
		else if (!strcmp(d, "right"))
			p.x += t;
	}
	return p;
}

void
test(const char **s, size_t n)
{
	Point p;

	p = track(s, n);
	printf("[%d,%d]\n", p.x, p.y);
}

int
main(void)
{
	const char *s1[] = { "right 10", "up 50", "left 30", "down 10" };
	const char *s2[] = { "left 10", "left 100", "left 1000", "left 10000" };
	const char *s3[] = { "right 100", "right 100", "up 500", "up 10000" };
	const char *s4[] = { "left 10", "right 10", "down 10", "up 10" };

	test(s1, nelem(s1));
	test(s1, 0);
	test(s2, nelem(s2));
	test(s3, nelem(s3));
	test(s4, nelem(s4));

	return 0;
}

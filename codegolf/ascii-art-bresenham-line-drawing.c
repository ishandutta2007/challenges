/*

Write the shortest possible program that draws a Bresenham line in ASCII art. Your program should take two integers x and y (command line or stdin, your choice) and draw an ASCII line which starts in the upper left and goes right x units and down y units.
You must use _ and \ characters and place them in the correct location according to Bresenham's algorithm.

You may assume x >= y, so no vertical segments are required.

Note that because you're using the _ character, for a line with y=3 you will likely need to output 4 lines of text (and you may emit a leading blank line when it isn't necessary).

examples:

11 3
_
 \___
     \___
         \_
11 1
_____
     \_____

5 4

\
 \_
   \
    \

For points which are exactly halfway you may choose either rounding:

10 1
____
    \_____
or
_____
     \____

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
} Plotter;

void
beginplot(Plotter *pl, int x, int y)
{
	pl->x = x;
	pl->y = y;
}

void
endplot(void)
{
	printf("\n");
}

void
plot(Plotter *pl, int x, int y)
{
	int i;

	assert(pl->x <= x && pl->y <= y);

	while (pl->x < x && pl->y == y) {
		printf("_");
		pl->x++;
	}

	while (pl->x < x && pl->y < y) {
		printf("\n");
		for (i = 0; i < pl->x; i++)
			printf(" ");
		printf("\\");

		pl->x++;
		pl->y++;
	}
}

void
line(int x, int y)
{
	int x0, y0, x1, y1;
	int dx, dy, sx, sy;
	int e, e2;
	Plotter pl;

	x0 = 0;
	y0 = 0;
	x1 = x;
	y1 = y;

	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	e = dx + dy;

	beginplot(&pl, x0, y0);
	for (;;) {
		plot(&pl, x0, y0);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * e;
		if (e2 >= dy) {
			e += dy;
			x0 += sx;
		}
		if (e2 <= dx) {
			e += dx;
			y0 += sy;
		}
	}
	endplot();
}

int
main(void)
{
	line(11, 3);
	line(11, 1);
	line(5, 4);
	line(20, 20);
	line(15, 7);

	return 0;
}

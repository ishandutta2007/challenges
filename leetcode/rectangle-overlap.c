/*

A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner,
and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive. 
To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.


Notes:

Both rectangles rec1 and rec2 are lists of 4 integers.
All coordinates in rectangles will be between -10^9 and 10^9.

*/

#include <stdio.h>

typedef struct {
	int x1, y1;
	int x2, y2;
} Rect;

int
rectempty(Rect r)
{
	return r.x1 >= r.x2 || r.y1 >= r.y2;
}

Rect
rectintersect(Rect r, Rect s)
{
	if (r.x1 < s.x1)
		r.x1 = s.x1;
	if (r.y1 < s.y1)
		r.y1 = s.y1;
	if (r.x2 > s.x2)
		r.x2 = s.x2;
	if (r.y2 > s.y2)
		r.y2 = s.y2;
	if (rectempty(r))
		r = (Rect){0};
	return r;
}

int
rectoverlap(Rect r, Rect s)
{
	return !rectempty(rectintersect(r, s));
}

int
main(void)
{
	printf("%d\n", rectoverlap((Rect){0, 0, 2, 2}, (Rect){1, 1, 3, 3}));
	printf("%d\n", rectoverlap((Rect){0, 0, 1, 1}, (Rect){1, 0, 2, 1}));
	printf("%d\n", rectoverlap((Rect){0, 0, 1, 1}, (Rect){1, 1, 2, 2}));
	return 0;
}

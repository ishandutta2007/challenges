/*

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Note:

Assume that the total area is never beyond the maximum possible value of int.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x1, y1;
	int x2, y2;
} Rect;

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int
rectarea(Rect r)
{
	return abs(r.x2 - r.x1) * abs(r.y2 - r.y1);
}

Rect
rectcanon(Rect r)
{
	if (r.x2 < r.x1)
		swap(&r.x1, &r.x2);
	if (r.y2 < r.y1)
		swap(&r.y1, &r.y2);
	return r;
}

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
area(int A, int B, int C, int D, int E, int F, int G, int H)
{
	Rect r1, r2, r3;

	r1 = rectcanon((Rect){A, B, C, D});
	r2 = rectcanon((Rect){E, F, G, H});
	r3 = rectintersect(r1, r2);
	return rectarea(r1) + rectarea(r2) - rectarea(r3);
}

int
main(void)
{
	printf("%d\n", area(-3, 0, 3, 4, 0, -1, 9, 2));
	return 0;
}

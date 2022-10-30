/*

Create a function that returns the area of the overlap between two rectangles. The function will receive two rectangles, each with the coordinates of two of its opposite angles.
Examples

overlappingRectangles(
  [{ x: 2, y: 1 }, { x: 5, y: 5 }],
  [{ x: 3, y: 2 }, { x: 5, y: 7 }]
) ➞ 6

overlappingRectangles(
  [{ x: 2, y: -9 }, { x: 13, y: -4 }],
  [{ x: 5, y: -11 }, { x: 7, y: -2 }]
) ➞ 10

overlappingRectangles(
  [{ x: -8, y: -7 }, { x: -4, y: 0 }],
  [{ x: -5, y: -9 }, { x: -1, y: -2 }]
) ➞ 5

Example 1

Example 2

Example 3
Notes

    Coordinates can be positive or negative integers.
    Not all examples have overlaps.

*/

#include <assert.h>
#include <stdlib.h>
#include <math.h>

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
overlap(Rect r, Rect s)
{
	return rectarea(rectintersect(r, s));
}

int
main(void)
{
	Rect r1 = {2, 1, 5, 5};
	Rect s1 = {3, 2, 5, 7};

	Rect r2 = {2, -9, 13, -4};
	Rect s2 = {5, -11, 7, -2};

	Rect r3 = {-8, -7, -4, 0};
	Rect s3 = {-5, -9, -1, -2};

	Rect r4 = {-11, 2, -1, 6};
	Rect s4 = {-8, 2, -4, 9};

	Rect r5 = {-4, -6, 1, 1};
	Rect s5 = {-2, -2, 3, 4};

	Rect r6 = {-3, -3, 3, 3};
	Rect s6 = {-1, -1, 1, 1};

	Rect r7 = {1, 1, 4, 4};
	Rect s7 = {4, 4, 6, 6};

	Rect r8 = {1, 1, 4, 3};
	Rect s8 = {4, 4, 6, 6};

	Rect r9 = {1, 1, 3, 3};
	Rect s9 = {4, 4, 6, 6};

	assert(overlap(r1, s1) == 6);
	assert(overlap(r2, s2) == 10);
	assert(overlap(r3, s3) == 5);
	assert(overlap(r4, s4) == 16);
	assert(overlap(r5, s5) == 9);
	assert(overlap(r6, s6) == 4);
	assert(overlap(r7, s7) == 0);
	assert(overlap(r8, s8) == 0);
	assert(overlap(r9, s9) == 0);

	return 0;
}

#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int x, y, w, h;
} Rect;

bool
overlap(Rect *a, Rect *b)
{
	if (a->y + a->h < b->y)
		return false;

	if (a->y > b->y + b->h)
		return false;

	if (a->x + a->w < b->x)
		return false;

	if (a->x > b->x + b->w)
		return false;

	return true;
}

int
main(void)
{
	Rect a = {1, 2, 3, 4};
	Rect b = {2, 2, 3, 4};
	printf("%d\n", overlap(&a, &b));

	Rect c = {100, 100, 1, 1};
	Rect d = {50, 50, 49, 49};
	printf("%d\n", overlap(&c, &d));

	printf("%d\n", overlap(&a, &a));
	printf("%d\n", overlap(&b, &b));
	printf("%d\n", overlap(&c, &c));
	printf("%d\n", overlap(&d, &d));

	printf("%d\n", overlap(&a, &c));
	printf("%d\n", overlap(&a, &d));

	return 0;
}

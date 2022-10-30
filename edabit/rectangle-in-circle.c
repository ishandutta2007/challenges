/*

Create a function that takes three numbers — the width and height of a rectangle,
and the radius of a circle and returns true if the rectangle can fit inside the circle, false if it can't.

*/

#include <stdio.h>

int
rectincircle(int w, int h, int r)
{
	return (w * w + h * h) <= (4 * r * r);
}

int
main(void)
{
	printf("%d\n", rectincircle(5, 12, 7));
	printf("%d\n", rectincircle(5, 12, 6));
	printf("%d\n", rectincircle(3, 7, 4));
	printf("%d\n", rectincircle(4, 7, 4));
	printf("%d\n", rectincircle(11, 1, 6));
	printf("%d\n", rectincircle(21, 12, 12));
	printf("%d\n", rectincircle(8, 6, 5));
	printf("%d\n", rectincircle(5, 9, 5));
	return 0;
}

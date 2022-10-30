/*

Create a function that takes height and width and finds the
perimeter of a rectangle.

*/

#include <stdio.h>

int
perim(int w, int h)
{
	return 2 * (w + h);
}

int
main(void)
{
	printf("%d\n", perim(6, 7));
	printf("%d\n", perim(20, 10));
	printf("%d\n", perim(2, 9));
	return 0;
}

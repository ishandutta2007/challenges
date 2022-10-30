/*

Two cats and a mouse are at various positions on a line.
You will be given their starting positions.
Your task is to determine which cat will reach the mouse first,
assuming the mouse doesn't move and the cats travel at equal speed.
If the cats arrive at the same time, the mouse will be allowed to move and it will escape while they fight.

You are given q queries in the form of x, y, and z representing the respective positions for cats A and B, and for mouse C.
Complete the function  to return the appropriate answer to each query, which will be printed on a new line.

If cat A catches the mouse first, print Cat A.
If cat B catches the mouse first, print Cat B.
If both cats reach the mouse at the same time, print Mouse C as the two cats fight and mouse escapes.

*/

#include <stdio.h>
#include <stdlib.h>

void
catmouse(int x, int y, int z)
{
	int a, b;

	a = abs(z - x);
	b = abs(z - y);
	if (a < b)
		printf("Cat A\n");
	else if (a > b)
		printf("Cat B\n");
	else
		printf("Mouse C\n");
}

int
main(void)
{
	catmouse(2, 5, 4);
	catmouse(1, 2, 3);
	catmouse(1, 3, 2);
	catmouse(100, 2, 101);
	return 0;
}

/*

The Challenge:

Draw a rectangle of ASCII boxes: []

The Rules:

Takes a width and a height input

You can assume both of these are numbers

Must produce a string with newline characters, \n

Examples:

2, 2:

[][]
[][]
2, 3:

[][]
[][]
[][]
Fewest Bytes wins.

*/

#include <stdio.h>

void
boxes(int w, int h)
{
	int x, y;

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			printf("[]");
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	boxes(2, 2);
	boxes(2, 3);

	return 0;
}

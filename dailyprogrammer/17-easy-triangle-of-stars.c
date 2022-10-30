/*

Draw a triangle full of stars

*/

#include <stdio.h>

void
tristar(int h, int c)
{
	int i, j, k;

	for (i = 0, j = 1; i < h; i++, j *= 2) {
		for (k = 0; k < j; k++)
			printf("%c", c);
		printf("\n");
	}
}

int
main(void)
{
	int h;

	printf("Height: ");
	scanf("%d", &h);
	tristar(h, '@');

	return 0;
}

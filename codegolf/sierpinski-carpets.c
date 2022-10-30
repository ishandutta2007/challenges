/*

Who doesn't love a good fractal? The Sierpinski Carpet is a classic example of a fractal.

To complete this task, you will be required to generate a carpet of type n and print the resulting image to the stdout (see example below for formatting) n, representing the level carpet.
Steps can be found on this Wikipedia article.

This value will be taken from stdin or equivalent.

For example, an input of 4 would produce a level 4 carpet:

■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■
■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
■ ■ ■       ■ ■ ■ ■ ■ ■       ■ ■ ■ ■ ■ ■       ■ ■ ■
■   ■       ■   ■ ■   ■       ■   ■ ■   ■       ■   ■
■ ■ ■       ■ ■ ■ ■ ■ ■       ■ ■ ■ ■ ■ ■       ■ ■ ■ 
■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■
■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
■ ■ ■ ■ ■ ■ ■ ■ ■                   ■ ■ ■ ■ ■ ■ ■ ■ ■
■   ■ ■   ■ ■   ■                   ■   ■ ■   ■ ■   ■
■ ■ ■ ■ ■ ■ ■ ■ ■                   ■ ■ ■ ■ ■ ■ ■ ■ ■
■ ■ ■       ■ ■ ■                   ■ ■ ■       ■ ■ ■
■   ■       ■   ■                   ■   ■       ■   ■
■ ■ ■       ■ ■ ■                   ■ ■ ■       ■ ■ ■ 
■ ■ ■ ■ ■ ■ ■ ■ ■                   ■ ■ ■ ■ ■ ■ ■ ■ ■
■   ■ ■   ■ ■   ■                   ■   ■ ■   ■ ■   ■
■ ■ ■ ■ ■ ■ ■ ■ ■                   ■ ■ ■ ■ ■ ■ ■ ■ ■ 
■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■
■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
■ ■ ■       ■ ■ ■ ■ ■ ■       ■ ■ ■ ■ ■ ■       ■ ■ ■
■   ■       ■   ■ ■   ■       ■   ■ ■   ■       ■   ■
■ ■ ■       ■ ■ ■ ■ ■ ■       ■ ■ ■ ■ ■ ■       ■ ■ ■ 
■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■ ■   ■
■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■

An input of 3 would produce a level 3 carpet:

■ ■ ■ ■ ■ ■ ■ ■ ■
■   ■ ■   ■ ■   ■
■ ■ ■ ■ ■ ■ ■ ■ ■
■ ■ ■       ■ ■ ■
■   ■       ■   ■
■ ■ ■       ■ ■ ■
■ ■ ■ ■ ■ ■ ■ ■ ■
■   ■ ■   ■ ■   ■
■ ■ ■ ■ ■ ■ ■ ■ ■

An input of 2 would produce a level 2 carpet:

■ ■ ■
■   ■ 
■ ■ ■

And a input of 1 would produce a level 1 carpet (just a square):

■

Note the spaces between the columns.

The idea is to use the ■ character for blocks and space for gaps

The line starts with the ■ character.

As always, the smallest solution wins by character count (due to non-standard characters).

Alternatively, # can be used instead of the ■ character in languages that do not support Unicode.

*/

#include <stdio.h>
#include <math.h>

int
at(int l, int x, int y)
{
	for (; l > 0; l /= 3) {
		if ((x / l) & (y / l) & 1)
			return 1;

		x %= l;
		y %= l;
	}
	return 0;
}

void
carpet(int n)
{
	int x, y;

	printf("n=%d\n", n);
	n = pow(3, n - 1);
	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++)
			printf("%s ", at(n, x, y) ? " " : u8"■");
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	int i;

	for (i = 1; i <= 5; i++)
		carpet(i);

	return 0;
}

/*

Goal

The program's goal is to draw an ASCII art rectangle repeatedly doubled in size, alternating horizontally and vertically.
Each time the rectangle doubles in size, the extra area is represented by a different character and the previous areas remain unchanged.
The two smallest sections contain one character each and may be in any corner.

The program accepts a single integer as input, defining the number of sections the full rectangle contains.

No other external resources or inputs are allowed.

Sample input and output

10

ABDDFFFFHHHHHHHHJJJJJJJJJJJJJJJJ
CCDDFFFFHHHHHHHHJJJJJJJJJJJJJJJJ
EEEEFFFFHHHHHHHHJJJJJJJJJJJJJJJJ
EEEEFFFFHHHHHHHHJJJJJJJJJJJJJJJJ
GGGGGGGGHHHHHHHHJJJJJJJJJJJJJJJJ
GGGGGGGGHHHHHHHHJJJJJJJJJJJJJJJJ
GGGGGGGGHHHHHHHHJJJJJJJJJJJJJJJJ
GGGGGGGGHHHHHHHHJJJJJJJJJJJJJJJJ
IIIIIIIIIIIIIIIIJJJJJJJJJJJJJJJJ
IIIIIIIIIIIIIIIIJJJJJJJJJJJJJJJJ
IIIIIIIIIIIIIIIIJJJJJJJJJJJJJJJJ
IIIIIIIIIIIIIIIIJJJJJJJJJJJJJJJJ
IIIIIIIIIIIIIIIIJJJJJJJJJJJJJJJJ
IIIIIIIIIIIIIIIIJJJJJJJJJJJJJJJJ
IIIIIIIIIIIIIIIIJJJJJJJJJJJJJJJJ
IIIIIIIIIIIIIIIIJJJJJJJJJJJJJJJJ

Selection criteria

The shortest code in a week wins the points.

*/

#include <stdio.h>
#include <ctype.h>
#include <limits.h>

static int ascii[128];
static size_t asciilen;

void
init(void)
{
	size_t i;
	int c;

	for (i = 0; i < 128; i++) {
		c = ('A' + i) & 127;
		if (isprint(c))
			ascii[asciilen++] = c;
	}
}

void
dim(unsigned n, unsigned *w, unsigned *h)
{
	unsigned i;

	*w = *h = (n > 0);
	for (i = 1; i < n; i++) {
		if (i & 1)
			*w <<= 1;
		else
			*h <<= 1;
	}
}

int
bound(unsigned x, unsigned y)
{
	unsigned w, h;
	unsigned i;

	w = h = 1;
	for (i = 0; i < UINT_MAX; i++) {
		if (x < w && y < h)
			break;

		if (!(i & 1))
			w <<= 1;
		else
			h <<= 1;
	}
	return i;
}

void
rpf(unsigned n)
{
	unsigned x, y, w, h;

	dim(n, &w, &h);
	printf("%u %ux%u\n", n, w, h);
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			printf("%c", ascii[bound(x, y) % asciilen]);
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	unsigned i;

	init();
	for (i = 0; i <= 12; i++)
		rpf(i);
	return 0;
}

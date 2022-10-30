/*

Create a function that takes a number (from 1 - 60) and returns a corresponding string of hyphens.

Notes

    You will be provided integers ranging from 1 to 60.
    Don't forget to return your result as a string.

*/

#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

char *
dash(unsigned x, char *b, size_t n)
{
	if (n == 0)
		return b;
	if (x == 0) {
		b[0] = '\0';
		return b;
	}

	n = min(x, n - 1);
	memset(b, '-', n);
	b[n] = '\0';
	return b;
}

int
main(void)
{
	char b[80];
	unsigned i;
	for (i = 0; i < 60; i++)
		printf("%s\n", dash(i, b, sizeof(b)));
	return 0;
}

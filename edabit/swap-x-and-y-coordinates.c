/*

Write a function that swaps the X and Y coordinates in a string.

Notes

    Some numbers have multiple digits.
    Some numbers will be negative.

*/

#include <stdio.h>

char *
swapxy(const char *s, char *b, size_t n)
{
	int x1, y1, x2, y2;

	if (sscanf(s, "(%d, %d), (%d, %d)", &x1, &y1, &x2, &y2) != 4)
		return NULL;

	snprintf(b, n, "(%d, %d), (%d, %d)", y1, x1, y2, x2);
	return b;
}

int
main(void)
{
	char b[128];

	printf("%s\n", swapxy("(1, 2), (3, 4)", b, sizeof(b)));
	printf("%s\n", swapxy("(11, 23), (43, 99)", b, sizeof(b)));
	printf("%s\n", swapxy("(-5, -3), (7, 4)", b, sizeof(b)));
	printf("%s\n", swapxy("(-1095, -321), (0, -88)", b, sizeof(b)));

	return 0;
}

/*

Create a function that takes an array of 10 numbers (between 0 and 9) and returns a string of those numbers formatted as a phone number (e.g. (555) 555-5555).

Notes

Don't forget the space after the closing parenthese.

*/

#include <stdio.h>

char *
phonefmt(int a[10], char *b, size_t n)
{
	snprintf(b, n, "(%d%d%d) %d%d%d-%d%d%d%d",
	         a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
	return b;
}

int
main(void)
{
	char b[80];

	int p1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	printf("%s\n", phonefmt(p1, b, sizeof(b)));

	int p2[] = {5, 1, 9, 5, 5, 5, 4, 4, 6, 8};
	printf("%s\n", phonefmt(p2, b, sizeof(b)));

	int p3[] = {3, 4, 5, 5, 0, 1, 2, 5, 2, 7};
	printf("%s\n", phonefmt(p3, b, sizeof(b)));

	return 0;
}

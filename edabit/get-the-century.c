/*

Create a function that takes in a date and returns the correct century.

Notes

All dates will be between 1000 and 2010.
The 11th century is between 1001 and 1100.
The 18th century is between 1701-1800.

*/

#include <stdio.h>

char *
century(int y, char *b, size_t n)
{
	if (!(1000 <= y && y <= 2010))
		return NULL;

	if (y <= 2000)
		snprintf(b, n, "%dth century", (y + 99) / 100);
	else
		snprintf(b, n, "21st century");
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", century(1756, b, sizeof(b)));
	printf("%s\n", century(1555, b, sizeof(b)));
	printf("%s\n", century(1000, b, sizeof(b)));
	printf("%s\n", century(1001, b, sizeof(b)));
	printf("%s\n", century(2005, b, sizeof(b)));
	printf("%s\n", century(1789, b, sizeof(b)));
	printf("%s\n", century(1510, b, sizeof(b)));
	printf("%s\n", century(1615, b, sizeof(b)));
	printf("%s\n", century(2000, b, sizeof(b)));
	printf("%s\n", century(1997, b, sizeof(b)));
	return 0;
}

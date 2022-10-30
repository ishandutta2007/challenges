/*

Given a fraction as a string, return whether or not it is greater than 1 when evaluated.

Notes

Fractions must be strictly greater than 1 (see example #3).

*/

#include <stdio.h>

int
gto(const char *s)
{
	unsigned x, y;

	if (sscanf(s, "%u/%u", &x, &y) != 2)
		return -2;
	if (y == 0)
		return -1;
	return x > y;
}

int
main(void)
{
	printf("%d\n", gto("1/2"));
	printf("%d\n", gto("7/4"));
	printf("%d\n", gto("10/10"));
	printf("%d\n", gto("12/30"));
	printf("%d\n", gto("28/3"));
	printf("%d\n", gto("35/31"));
	printf("%d\n", gto("11/27"));
	printf("%d\n", gto("42/32"));
	printf("%d\n", gto("34/15"));
	printf("%d\n", gto("16/16"));
	printf("%d\n", gto("38/41"));
	printf("%d\n", gto("45/43"));
	printf("%d\n", gto("13/38"));
	printf("%d\n", gto("43/2"));
	printf("%d\n", gto("16/31"));
	printf("%d\n", gto("41/15"));
	printf("%d\n", gto("2/38"));
	printf("%d\n", gto("37/21"));
	return 0;
}

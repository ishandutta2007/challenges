/*

Challenge

Given input in the form <n1>, <n2> where number can be -1, 0, or 1, return the corresponding cardinal direction.
Positive numbers move East in the x-axis and South in the y-axis, Negative numbers move West in the x-axis and North in the y-axis.

Output must be in the form South East, North East, North. It is case-sensitive.

If the input is 0, 0, your program must return That goes nowhere, silly!.

Sample Input/Outpot:
1, 1 -> South East

0, 1 -> South

1, -1 -> North East

0, 0 -> That goes nowhere, silly!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
direction(int x, int y, char *b)
{
	int l;

	if (x == 0 && y == 0) {
		sprintf(b, "That goes nowhere, silly!");
		return b;
	}

	l = 0;
	if (y < 0)
		l += sprintf(b + l, "North");
	else if (y > 0)
		l += sprintf(b + l, "South");

	if (x && l)
		l += sprintf(b + l, " ");

	if (x < 0)
		l += sprintf(b + l, "West");
	else if (x > 0)
		l += sprintf(b + l, "East");

	return b;
}

void
test(int x, int y, const char *r)
{
	char b[128];

	direction(x, y, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, 1, "South East");
	test(0, 1, "South");
	test(1, -1, "North East");
	test(0, 0, "That goes nowhere, silly!");

	return 0;
}

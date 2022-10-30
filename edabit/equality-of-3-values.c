/*

Create a function that takes three integer arguments (a, b, c) and returns the number of equal values.

Notes

Your function must return 0, 2 or 3.

*/

#include <stdio.h>

int
equal3(int a, int b, int c)
{
	int f;

	f = 0;
	if (a == b)
		f |= 0x3;
	if (a == c)
		f |= 0x5;
	if (b == c)
		f |= 0x6;
	return !!(f & 0x1) + !!(f & 0x2) + !!(f & 0x4);
}

int
main(void)
{
	printf("%d\n", equal3(2, 3, 4));
	printf("%d\n", equal3(7, 3, 7));
	printf("%d\n", equal3(4, 4, 4));
	printf("%d\n", equal3(7, 3, 4));
	printf("%d\n", equal3(3, 3, 6));
	printf("%d\n", equal3(1, 1, 1));
	printf("%d\n", equal3(1, 7, 6));
	printf("%d\n", equal3(7, 7, 7));
	return 0;
}

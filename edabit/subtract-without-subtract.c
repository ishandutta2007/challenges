/*

Create a function that subtracts one positive integer from another, without using -.

Notes

    Do not multiply by -1.
    Use bitwise operations.

*/

#include <stdio.h>

void
swapi(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

int
sub(int x, int y)
{
	int b;

	if (x < y)
		swapi(&x, &y);

	while (y) {
		b = ~x & y;
		x ^= y;
		y = b << 1;
	}
	return x;
}

int
main(void)
{
	printf("%d\n", sub(5, 9));
	printf("%d\n", sub(10, 30));
	printf("%d\n", sub(0, 0));
	return 0;
}

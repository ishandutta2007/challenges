/*

All submissions for this problem are available.
Write a program to obtain length (L) and breadth (B) of a rectangle
and check whether its area is greater or perimeter is greater or both are equal.

*/
#include <stdio.h>

void
geom(int l, int b)
{
	int a, p;

	a = l * b;
	p = 2 * (l + b);
	if (a > p) {
		printf("Area\n");
		printf("%d\n", a);
	} else if (a == p) {
		printf("Eq\n");
		printf("%d\n", a);
	} else {
		printf("Peri\n");
		printf("%d\n", p);
	}
}

int
main(void)
{
	geom(1, 2);
	geom(40, 40);
	return 0;
}

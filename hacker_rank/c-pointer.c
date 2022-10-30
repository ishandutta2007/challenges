/*

You have to complete the function void update(int *a,int *b), which reads two integers as argument,
and sets a with the sum of them, and b with the absolute difference of them.

*/

#include <stdio.h>
#include <stdlib.h>

void
update(int *a, int *b)
{
	int x, y;

	x = *a;
	y = *b;
	*a = x + y;
	*b = abs(x - y);
}

int
main(void)
{
	int a, b;

	a = 4;
	b = 5;
	update(&a, &b);
	printf("%d %d\n", a, b);

	a = 60;
	b = 10;
	update(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}

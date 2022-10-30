/*

Given three numbers, x, y and z, determine whether they are the edges
of a right angled triangle.

Notice the largest side of the triangle might not be the
last one passed to the function.
All numbers will be integers (whole numbers).

*/

#include <stdio.h>

void
swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

int
isright(int a, int b, int c)
{
	if (a > b)
		swap(&a, &b);
	if (a > c)
		swap(&a, &c);
	if (b > c)
		swap(&b, &c);
	return a > 0 && a * a + b * b == c * c;
}

int
main(void)
{
	printf("%d\n", isright(3, 4, 5));
	printf("%d\n", isright(145, 105, 100));
	printf("%d\n", isright(70, 130, 110));
	printf("%d\n", isright(60, 60, 60));
	printf("%d\n", isright(0, 4, 4));
	printf("%d\n", isright(-3, 4, 5));
	printf("%d\n", isright(115, 277, 252));
	printf("%d\n", isright(140, 170, 220));
	printf("%d\n", isright(915, 1748, 1973));
	return 0;
}

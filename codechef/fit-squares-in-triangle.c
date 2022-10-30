/*

What is the maximum number of squares of size 2x2 that can be fit in a right angled isosceles triangle of base B.
One side of the square must be parallel to the base of the isosceles triangle.
Base is the shortest side of the triangle

*/
#include <stdio.h>

int
fit_slow(int b)
{
	int r;

	r = 0;
	while (b > 2) {
		r += (b - 2) / 2;
		b -= 2;
	}
	return r;
}

int
fit(int b)
{
	int n;

	n = b / 2;
	return n * (n - 1) / 2;
}

int
main(void)
{
	int i;
	for (i = 1; i <= 100; i++)
		printf("%d %d %d\n", i, fit_slow(i), fit(i));

	return 0;
}

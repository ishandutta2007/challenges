/*

In this problem, you will implement three variadic functions named sum, min and max
to calculate sums, minima, maxima of a variable number of arguments.
The first argument passed to the variadic function is the count of the number of arguments, which is followed by the arguments themselves.

*/
#include <stdio.h>
#include <stdarg.h>

int
sum(int n, ...)
{
	int i, s;
	va_list ap;

	va_start(ap, n);
	s = 0;
	for (i = 0; i < n; i++)
		s += va_arg(ap, int);
	va_end(ap);
	return s;
}

int
min(int n, ...)
{
	int i, x, y;
	va_list ap;

	if (n <= 0)
		return -1;

	va_start(ap, n);
	x = va_arg(ap, int);
	for (i = 1; i < n; i++) {
		y = va_arg(ap, int);
		if (x > y)
			x = y;
	}
	va_end(ap);
	return x;
}

int
max(int n, ...)
{
	int i, x, y;
	va_list ap;

	if (n <= 0)
		return -1;

	va_start(ap, n);
	x = va_arg(ap, int);
	for (i = 1; i < n; i++) {
		y = va_arg(ap, int);
		if (x < y)
			x = y;
	}
	va_end(ap);
	return x;
}

int
main(void)
{
	printf("%d\n", sum(6, 1, 2, 3, 4, 5, 6));
	printf("%d\n", min(6, 1, 2, 3, 4, 5, 6));
	printf("%d\n", max(6, 1, 2, 300, 4, 5, 6));
	return 0;
}

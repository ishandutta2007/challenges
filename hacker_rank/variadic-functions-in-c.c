/*

Variadic functions are functions which take a variable number of arguments. In C programming, a variadic function will contribute to the flexibility of the program that you are developing.

The declaration of a variadic function starts with the declaration of at least one named variable, and uses an ellipsis as the last parameter, e.g.

int printf(const char* format, ...);

In this problem, you will implement three variadic functions named sum(), min(), and max()to calculate sums, minima, maxima of a variable number of arguments.
The first argument passed to the variadic function is the count of the number of arguments, which is followed by the arguments themselves. 

*/

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int
sum(int n, ...)
{
	va_list ap;
	int i, r;

	va_start(ap, n);
	r = 0;
	for (i = 0; i < n; i++)
		r += va_arg(ap, int);
	va_end(ap);
	return r;
}

int
min(int n, ...)
{
	va_list ap;
	int i, r, v;

	va_start(ap, n);
	r = INT_MAX;
	for (i = 0; i < n; i++) {
		v = va_arg(ap, int);
		if (v < r)
			r = v;
	}
	va_end(ap);
	return r;
}

int
max(int n, ...)
{
	va_list ap;
	int i, r, v;

	va_start(ap, n);
	r = INT_MIN;
	for (i = 0; i < n; i++) {
		v = va_arg(ap, int);
		if (v > r)
			r = v;
	}
	va_end(ap);
	return r;
}

#define numargs(...) (sizeof((int[]){__VA_ARGS__}) / sizeof(int))
#define print(f, ...) printf("%s: %d\n", #f, f(numargs(__VA_ARGS__), __VA_ARGS__))
#define test(...)                        \
	do {                             \
		print(min, __VA_ARGS__); \
		print(max, __VA_ARGS__); \
		print(sum, __VA_ARGS__); \
		printf("\n");            \
	} while (0)

int
main(void)
{
	test(1, 2, 3, 4, 5);
	test(-4, 52, 2, 1);
	test(5, 2, 13, 4, 245, 36, 464, 647, 342342);
	test(4, 5, 5, 5, 34, 2, 45, 3647, 34, -5363, -2536);
	return 0;
}

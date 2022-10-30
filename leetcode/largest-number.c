/*

Given a list of non negative integers, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
snprint(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return min(size, n);
}

int
cmp(const void *a, const void *b)
{
	char s[128], t[128];
	unsigned x, y;

	x = *(unsigned int *)a;
	y = *(unsigned int *)b;
	snprintf(s, sizeof(s), "%u%u", x, y);
	snprintf(t, sizeof(t), "%u%u", y, x);

	return strcmp(t, s);
}

char *
largest(char *b, size_t m, unsigned *a, size_t n)
{
	size_t i, l;

	qsort(a, n, sizeof(*a), cmp);
	l = 0;
	l += snprint(b + l, m - l, "");
	for (i = 0; i < n; i++)
		l += snprint(b + l, m - l, "%u", a[i]);
	return b;
}

int
main(void)
{
	unsigned n1[] = {10, 2};
	unsigned n2[] = {3, 30, 34, 5, 9};
	unsigned n3[] = {0, 0};
	unsigned n4[] = {1, 34, 56, 78, 910};
	char b[1024];

	printf("%s\n", largest(b, nelem(b), n1, nelem(n1)));
	printf("%s\n", largest(b, nelem(b), n2, nelem(n2)));
	printf("%s\n", largest(b, nelem(b), n3, nelem(n3)));
	printf("%s\n", largest(b, nelem(b), n4, nelem(n4)));

	return 0;
}

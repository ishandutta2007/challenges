/*

Create a function that takes two timestamps as input, and returns a string describing the time
elapsed between them (in days, hours, minutes, seconds as appropriate).

Notes

Timestamps are seconds elapsed since 1st January 1970.

*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void
swapul(unsigned long *x, unsigned long *y)
{
	unsigned long t;

	t = *x;
	*x = *y;
	*y = t;
}

int
snprint(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return (n > size) ? size : n;
}

char *
elapsed(unsigned long t1, unsigned long t2, char *b, size_t n)
{
	unsigned long d, h, m, s, t;
	size_t l;

	l = 0;
	l += snprint(b + l, n - l, "");
	if (t2 < t1) {
		l += snprint(b + l, n - l, "negative ");
		swapul(&t1, &t2);
	}

	t = t2 - t1;
	s = t % 60;
	m = (t / 60) % 60;
	h = (t / 3600) % 24;
	d = (t / 86400);
	if (d) {
		l += snprint(b + l, n - l, "%lu day%s", d, (d > 1) ? "s" : "");
		if (h || m || s)
			l += snprint(b + l, n - l, ", ");
	}
	if (h) {
		l += snprint(b + l, n - l, "%lu hour%s", h, (h > 1) ? "s" : "");
		if (m || s)
			l += snprint(b + l, n - l, ", ");
	}
	if (m) {
		l += snprint(b + l, n - l, "%lu minute%s", m, (m > 1) ? "s" : "");
		if (s)
			l += snprint(b + l, n - l, ", ");
	}
	if (s)
		l += snprint(b + l, n - l, "%lu second%s", s, (s > 1) ? "s" : "");

	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", elapsed(1559813526, 1559899926, b, sizeof(b)));
	printf("%s\n", elapsed(1559681004, 1559899926, b, sizeof(b)));
	printf("%s\n", elapsed(1557641659, 1559899926, b, sizeof(b)));
	printf("%s\n", elapsed(1557652446, 1559899926, b, sizeof(b)));
	printf("%s\n", elapsed(1558773066, 1559899926, b, sizeof(b)));
	printf("%s\n", elapsed(1552513985, 1559899926, b, sizeof(b)));
	printf("%s\n", elapsed(1559899926, 1559899926, b, sizeof(b)));
	return 0;
}

/*

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

*/

#include <stdio.h>
#include <stdarg.h>

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

char *
defang(const char *ip, char *b, size_t n)
{
	size_t i, l;

	l = 0;
	for (i = 0; ip[i]; i++) {
		if (ip[i] == '.')
			l += snprint(b + l, n - l, "[.]");
		else
			l += snprint(b + l, n - l, "%c", ip[i]);
	}
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", defang("1.1.1.1", b, sizeof(b)));
	printf("%s\n", defang("255.100.50.0", b, sizeof(b)));
	return 0;
}

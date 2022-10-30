/*

Create a function that takes a number and return a string with the number in expanded notation (AKA expanded form). See the resources tab for details on expanded notation.

Notes

You can expect only whole numbers greater than 0 as test input.

*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
snprint(char *s, size_t n, const char *fmt, ...)
{
	va_list ap;
	size_t l;

	va_start(ap, fmt);
	l = vsnprintf(s, n, fmt, ap);
	va_end(ap);
	return min(l, n);
}

char *
expand(unsigned long x, char *b, size_t n)
{
	char s[80];
	int i, j, l;

	if (n == 0)
		return b;
	if (x == 0) {
		snprint(b, n, "0");
		return b;
	}

	l = snprint(s, sizeof(s), "%lu", x);
	j = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] != '0') {
			j += snprint(b + j, n - j, "%c", s[i]);
			if (l - i - 1 > 0)
				j += snprint(b + j, n - j, "%0*d", l - i - 1, 0);
		}

		if (i < l - 1 && s[i + 1] != '0')
			j += snprint(b + j, n - j, " + ");
	}

	return b;
}

int
main(void)
{
	char b[256];
	printf("%s\n", expand(13ul, b, sizeof(b)));
	printf("%s\n", expand(86ul, b, sizeof(b)));
	printf("%s\n", expand(17000000ul, b, sizeof(b)));
	printf("%s\n", expand(420370022ul, b, sizeof(b)));
	printf("%s\n", expand(70304ul, b, sizeof(b)));
	printf("%s\n", expand(9000000ul, b, sizeof(b)));
	printf("%s\n", expand(5325ul, b, sizeof(b)));
	printf("%s\n", expand(2096039485293ul, b, sizeof(b)));
	printf("%s\n", expand(92093403034573ul, b, sizeof(b)));
	printf("%s\n", expand(0ul, b, sizeof(b)));
	return 0;
}

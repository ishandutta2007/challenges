/*

Write a function that converts a string into star shorthand. If a character is repeated n times, convert it into character*n.

Notes

Leave lone occurrences of a character as is.
Return an empty string if given an empty string input.

*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

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
ssh(const char *s, char *b, size_t n)
{
	size_t i, j, l;

	if (n == 0)
		return b;
	b[0] = '\0';

	l = 0;
	for (i = 0; s[i]; i += j) {
		j = 1;
		while (s[i] == s[i + j])
			j++;

		if (j == 1)
			l += snprint(b + l, n - l, "%c", s[i]);
		else
			l += snprint(b + l, n - l, "%c*%d", s[i], j);
	}
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", ssh("abbccc", b, sizeof(b)));
	printf("%s\n", ssh("haaaappyyyyy", b, sizeof(b)));
	printf("%s\n", ssh("77777geff", b, sizeof(b)));
	printf("%s\n", ssh("11223344", b, sizeof(b)));
	printf("%s\n", ssh("abc", b, sizeof(b)));
	printf("%s\n", ssh("", b, sizeof(b)));
	return 0;
}

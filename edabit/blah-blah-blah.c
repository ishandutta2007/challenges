/*

Create a function which replaces the last n words with "blah". Add "..." to the last blah.

Notes

    If n is longer than the amount of words in the sentence, replace every word with "blah" (see example #3).
    All blahs shall be lowercase!

*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

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
blahblah(const char *s, size_t n, char *b, size_t m)
{
	size_t i, j, l;

	if (m > 0)
		b[0] = '\0';

	for (j = l = 0; s[j]; j++)
		l += snprint(b + l, m - l, "%c", s[j]);

	for (i = 0; i < n; i++) {
		while (j > 0 && isspace(s[j]))
			j--;
		while (j > 0 && !isspace(s[j]))
			j--;
	}
	l = min(m, j);

	for (i = 0; i < n && s[j]; i++) {
		while (s[j] && isspace(s[j])) {
			l += snprint(b + l, m - l, " ");
			j++;
		}

		l += snprint(b + l, m - l, "blah");
		while (s[j] && !isspace(s[j]))
			j++;
	}
	if (n && j)
		l += snprint(b + l, m - l, "...");

	return b;
}

int
main(void)
{
	char b[256];

	printf("%s\n", blahblah("A function is a block of code which only runs when it is called", 5, b, sizeof(b)));
	printf("%s\n", blahblah("one two three four five", 2, b, sizeof(b)));
	printf("%s\n", blahblah("Sphinx of black quartz judge my vow", 10, b, sizeof(b)));
	printf("%s\n", blahblah("The quadratic formula is negative b plus or minus the square root of b squared subtract four ac all over two a", 5, b, sizeof(b)));
	printf("%s\n", blahblah("", 5, b, sizeof(b)));
	printf("%s\n", blahblah("blagh", 5, b, sizeof(b)));

	return 0;
}

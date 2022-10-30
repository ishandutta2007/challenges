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
	return min(size, n);
}

int
isvowel(int c)
{
	switch (tolower(c)) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return 1;
	}
	return 0;
}

char *
goatlatin(const char *s, char *b, size_t n)
{
	size_t i, j, w;
	int c, l;

	l = 0;
	w = 1;
	for (i = 0; s[i]; w++) {
		c = 0;
		if (!isvowel(s[i]))
			c = s[i++];
		for (; s[i] && !isspace(s[i]); i++)
			l += snprint(b + l, n - l, "%c", s[i]);
		if (c)
			l += snprint(b + l, n - l, "%c", c);
		l += snprint(b + l, n - l, "ma");
		for (j = 0; j < w; j++)
			l += snprint(b + l, n - l, "a");
		for (; isspace(s[i]); i++)
			l += snprint(b + l, n - l, "%c", s[i]);
	}
	return b;
}

int
main(void)
{
	char b[128];
	printf("%s\n", goatlatin("I speak Goat Latin", b, sizeof(b)));
	printf("%s\n", goatlatin("The quick brown fox jumped over the lazy dog", b, sizeof(b)));
	return 0;
}

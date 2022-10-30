/*

Write a function that inserts a white space between every instance of a lower character followed immediately by an upper character.

Notes

Each word in the phrase will be at least two characters long.

*/

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int
snprint(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return (size < n) ? size : n;
}

char *
insertws(const char *s, char *b, size_t n)
{
	size_t i, l;

	if (n == 0)
		return b;
	*b = '\0';

	l = 0;
	for (i = 0; s[i]; i++) {
		if (i > 0 && islower(s[i - 1]) && isupper(s[i]))
			l += snprint(b + l, n - l, " ");
		l += snprint(b + l, n - l, "%c", s[i]);
	}
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", insertws("SheWalksToTheBeach", b, sizeof(b)));
	printf("%s\n", insertws("MarvinTalksTooMuch", b, sizeof(b)));
	printf("%s\n", insertws("HopelesslyDevotedToYou", b, sizeof(b)));
	printf("%s\n", insertws("EvenTheBestFallDownSometimes", b, sizeof(b)));
	printf("%s\n", insertws("TheGreatestUpsetInHistory", b, sizeof(b)));
	printf("%s\n", insertws("A", b, sizeof(b)));
	printf("%s\n", insertws("AisTan", b, sizeof(b)));
	return 0;
}

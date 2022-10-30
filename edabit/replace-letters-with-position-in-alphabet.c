/*

Create a function that takes a string and replaces each letter with its appropriate position in the alphabet. "a" is 1, "b" is 2, "c" is 3, etc, etc.

Notes

If any character in the string isn't a letter, ignore it.

*/

#include <stdio.h>
#include <string.h>
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
	return (n > size) ? size : n;
}

char *
alphabetindex(const char *s, char *b, size_t n)
{
	size_t i, l;
	char c;

	l = 0;
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]);
		if ('a' <= c && c <= 'z') {
			if (l > 0)
				l += snprint(b + l, n - l, " ");
			l += snprint(b + l, n - l, "%d", c - 'a' + 1);
		}
	}
	return b;
}

int
main(void)
{
	char b[256];

	printf("%s\n", alphabetindex("Wednesday is hump day, but has anyone asked the camel if he’s happy about it?", b, sizeof(b)));
	printf("%s\n", alphabetindex("Check back tomorrow; I will see if the book has arrived.", b, sizeof(b)));
	printf("%s\n", alphabetindex("We have a lot of rain in June.", b, sizeof(b)));
	printf("%s\n", alphabetindex("Sixty-Four comes asking for bread.", b, sizeof(b)));
	printf("%s\n", alphabetindex("The#b00k$is*in^fr0nt#0f!the_taBle.", b, sizeof(b)));
	printf("%s\n", alphabetindex("Lets all be unique together until we realise we are all the same.", b, sizeof(b)));
	printf("%s\n", alphabetindex("The river stole the gods.", b, sizeof(b)));
	printf("%s\n", alphabetindex("Wow, does that work?", b, sizeof(b)));
	printf("%s\n", alphabetindex("If Purple People Eaters are real… where do they find purple people to eat?", b, sizeof(b)));
	printf("%s\n", alphabetindex("Abstraction is often one floor above you.", b, sizeof(b)));
	return 0;
}

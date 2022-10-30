/*

Create a function that converts a string of letters to their respective number in the alphabet.
A	B	C	D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U	V	W	...
0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	...

Notes

Make sure the numbers are spaced.

*/

#include <stdio.h>
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
alphnum(const char *s, char *b, size_t n)
{
	size_t i, l;
	int c;

	l = 0;
	for (i = 0; s[i]; i++) {
		c = s[i];
		if ('A' <= c && c <= 'Z')
			c -= 'A';
		else if ('a' <= c && c <= 'z')
			c -= 'a';

		l += snprint(b + l, n - l, "%d", c);
		if (s[i + 1] != '\0')
			l += snprint(b + l, n - l, " ");
	}
	return b;
}

int
main(void)
{
	char b[80];

	printf("\"%s\"\n", alphnum("XYZ", b, sizeof(b)));
	printf("\"%s\"\n", alphnum("ABCDEF", b, sizeof(b)));
	printf("\"%s\"\n", alphnum("JAVASCRIPT", b, sizeof(b)));
	printf("\"%s\"\n", alphnum("ABCD", b, sizeof(b)));
	printf("\"%s\"\n", alphnum("BCDA", b, sizeof(b)));
	printf("\"%s\"\n", alphnum("AAA", b, sizeof(b)));

	return 0;
}

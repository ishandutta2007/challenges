/*

Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

    All letters in hexadecimal (a-f) must be in lowercase.
    The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
    The given number is guaranteed to fit within the range of a 32-bit signed integer.
    You must not use any method provided by the library which converts/formats the number to hex directly.

*/

#include <stdio.h>
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

char *
rev(char *b, size_t n)
{
	size_t i;
	char c;

	for (i = 0; i < n / 2; i++) {
		c = b[i];
		b[i] = b[n - i - 1];
		b[n - i - 1] = c;
	}
	return b;
}

char *
hex(int x, char *b, size_t n)
{
	static const char tab[] = "0123456789abcdef";
	unsigned v;
	size_t l;

	v = x;
	l = 0;
	do {
		l += snprint(b + l, n - l, "%c", tab[v & 0xf]);
		v >>= 4;
	} while (v);

	return rev(b, l);
}

int
main(void)
{
	char b[80];

	printf("%s\n", hex(26, b, sizeof(b)));
	printf("%s\n", hex(-1, b, sizeof(b)));
	printf("%s\n", hex(100, b, sizeof(b)));
	printf("%s\n", hex(452525, b, sizeof(b)));
	printf("%s\n", hex(0, b, sizeof(b)));
	printf("%s\n", hex(-24524, b, sizeof(b)));
	return 0;
}

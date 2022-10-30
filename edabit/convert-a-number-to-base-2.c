/*

Create a function that returns a base 2 (binary) represetation of a base 10 (decimal) string number. To convert is simple: ((2) means base 2 and (10) means base 10) 010101001(2) = 1 + 8 + 32 + 128.

Going from right to left, the value of the most right bit is 1, now from that every bit to the left will be x2 the value, value of an 8 bit binary numbers are (256, 128, 64, 32, 16, 8, 4, 2, 1).

Notes

    Numbers will always be below 1024 (not including 1024).
    The && operator could be useful.
    The strings will always go to the length at which the most left bit's value gets bigger than the number in decimal.

*/

#include <stdio.h>
#include <limits.h>

char *
rev(char *b, size_t n)
{
	size_t i;
	char c;

	for (i = 0; i < n; i++, n--) {
		c = b[i];
		b[i] = b[n - 1];
		b[n - 1] = c;
	}

	return b;
}

char *
binary(unsigned x, char *b, size_t n)
{
	size_t i;

	if (n == 0)
		return NULL;

	i = 0;
	do {
		if (i + 1 < n)
			b[i++] = '0' + (x & 1);
		x >>= 1;
	} while (x);

	b[i] = '\0';
	return rev(b, i);
}

int
main(void)
{
	char b[80];

	printf("%s\n", binary(100, b, sizeof(b)));
	printf("%s\n", binary(1, b, sizeof(b)));
	printf("%s\n", binary(0, b, sizeof(b)));
	printf("%s\n", binary(69, b, sizeof(b)));
	printf("%s\n", binary(1023, b, sizeof(b)));
	printf("%s\n", binary(511, b, sizeof(b)));
	printf("%s\n", binary(666, b, sizeof(b)));
	printf("%s\n", binary(123, b, sizeof(b)));
	printf("%s\n", binary(5, b, sizeof(b)));
	printf("%s\n", binary(10, b, sizeof(b)));
	printf("%s\n", binary(UINT_MAX, b, sizeof(b)));
	printf("%s\n", binary(256, b, sizeof(b)));

	return 0;
}

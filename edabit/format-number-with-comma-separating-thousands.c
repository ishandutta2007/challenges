/*

Create a function that takes a number as an argument and returns a string formatted to separate thousands.

Notes

You can expect a valid number for all test cases.

*/

#include <stdio.h>
#include <limits.h>

char *
numfmt(int x, char *b, size_t n)
{
	char s[80];
	size_t i, j, k, l;

	if (n == 0)
		return b;

	l = snprintf(s, sizeof(s), "%d", x);
	i = j = 0;
	k = 3 - (l % 3);
	if (s[0] == '-') {
		b[j++] = s[i++];
		k = 3 - ((l - 1) % 3);
	}

	if (k == 3)
		k = 0;
	for (; i < l; i++) {
		if (j >= n - 1)
			break;
		b[j++] = s[i];

		if (++k == 3 && i + 1 < l) {
			if (j >= n - 1)
				break;
			b[j++] = ',';
			k = 0;
		}
	}
	b[j] = '\0';
	return b;
}

int
main(void)
{
	char b[80];
	long i;

	printf("%s\n", numfmt(1000, b, sizeof(b)));
	printf("%s\n", numfmt(100000, b, sizeof(b)));
	printf("%s\n", numfmt(20, b, sizeof(b)));
	printf("%s\n", numfmt(100, b, sizeof(b)));
	printf("%s\n", numfmt(0, b, sizeof(b)));
	printf("%s\n", numfmt(12948, b, sizeof(b)));
	printf("%s\n", numfmt(-200, b, sizeof(b)));
	printf("%s\n", numfmt(INT_MIN, b, sizeof(b)));
	printf("%s\n", numfmt(INT_MAX, b, sizeof(b)));
	for (i = 1; i <= 1000000000; i *= 1000)
		printf("%s\n", numfmt(i, b, sizeof(b)));
	return 0;
}

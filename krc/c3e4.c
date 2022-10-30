// In a two's complement number representation, our version of itoa does not
// handle the largest negative number, that is, the value of n equal to -2^(wordsize-1).
// Explain why not. Modify it to print that value correctly,
// regardless of the machine on which it runs.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void
appendc(char *s, char c, size_t *i, size_t n)
{
	if (*i < n) {
		if (*i + 1 == n)
			c = '\0';
		s[(*i)++] = c;
	}
}

void
reverse(char *s, size_t n)
{
	size_t i;
	char c;

	for (i = 0; i < n / 2; i++) {
		c = s[n - i - 1];
		s[n - i - 1] = s[i];
		s[i] = c;
	}
}

char *
itoa(int x, char *s, size_t n)
{
	size_t i;
	int sgn;

	if (n == 0)
		return s;

	sgn = x;
	i = 0;
	do {
		appendc(s, abs(x % 10) + '0', &i, n);
	} while ((x /= 10));
	if (sgn < 0)
		appendc(s, '-', &i, n);
	appendc(s, '\0', &i, n);
	reverse(s, i - 1);
	return s;
}

int
main(void)
{
	char buf[80];
	printf("%s\n", itoa(INT_MIN, buf, sizeof(buf)));
	printf("%s\n", itoa(INT_MAX, buf, sizeof(buf)));
	return 0;
}

// Write a version of itoa that accepts three arguments instead of two. The third
// argument is a minimum field width the converted number must be padded with
// blanks on the left if necessary to make it wide enough.

#include <stdio.h>
#include <stdlib.h>

void
reverse(char *s, size_t n)
{
	size_t i;
	char c;

	for (i = 0; i < n / 2; i++) {
		c = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = c;
	}
}

void
appendc(char *s, size_t n, size_t *i, char c)
{
	if (*i < n) {
		if (*i + 1 == n)
			c = '\0';
		s[(*i)++] = c;
	}
}

char *
itoa(int x, char *s, size_t n, size_t w)
{
	size_t i;
	int sgn;

	if (n == 0)
		return s;

	sgn = x;
	i = 0;
	do {
		appendc(s, n, &i, abs(x % 10 + '0'));
	} while ((x /= 10) != 0);

	if (sgn < 0)
		appendc(s, n, &i, '-');
	while (i < w && i < n)
		appendc(s, n, &i, ' ');

	appendc(s, n, &i, '\0');
	reverse(s, i - 1);
	return s;
}

int
main(void)
{
	char b[80];
	int i;

	printf("%s\n", itoa(20, b, sizeof(b), 10));
	printf("%s\n", itoa(13, b, sizeof(b), 4));
	for (i = 0; i < 256; i++)
		printf("%s\n", itoa(i, b, sizeof(b), i / 2));
	return 0;
}

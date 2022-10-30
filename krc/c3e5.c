// Write the function itob(n,s,b) that converts the integer n into a base b
// character representation in the string s.
// In particular, itob(n,s,16) formats n as a hexadecimal integer in s.

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int
scnprintf(char *s, size_t n, char *fmt, ...)
{
	va_list ap;
	size_t m;

	va_start(ap, fmt);
	m = vsnprintf(s, n, fmt, ap);
	va_end(ap);
	return (m < n) ? m : n;
}

char *
reverse(char *s, size_t n)
{
	size_t i;
	char t;

	for (i = 0; i < n / 2; i++) {
		t = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = t;
	}
	return s;
}

char *
itob(int x, char *s, size_t n, int b)
{
	int c, j, sgn;
	size_t i;

	if (b < 2) {
		scnprintf(s, n, "0");
		return s;
	}

	sgn = x;
	if (x < 0)
		x = -x;

	i = 0;
	do {
		j = x % b;
		if (j <= 9)
			c = j + '0';
		else
			c = j + 'a' - 10;
		i += scnprintf(s + i, n - i, "%c", c);
	} while ((x /= b) > 0);

	if (sgn < 0)
		i += scnprintf(s + i, n - i, "-");

	return reverse(s, i);
}

int
main(void)
{
	char b[80];
	int i, j;

	for (i = 0; i <= 16; i++) {
		for (j = 0; j <= 256; j++)
			printf("%d %d %s\n", i, j, itob(j, b, sizeof(b), i));
		printf("\n");
	}

	return 0;
}

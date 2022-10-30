// Given a 32-bit signed integer, reverse digits of an integer.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void
rev(char *s, size_t n)
{
	size_t i;
	char c;

	for (i = 0; i < n / 2; i++) {
		c = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = c;
	}
}

long
reverse(int x)
{
	char b[80], *p;
	int n, s;

	n = snprintf(b, sizeof(b), "%d", x);
	p = b;
	s = 1;
	if (b[0] == '-') {
		p = b + 1;
		s = -1;
		n--;
	}
	rev(p, n);
	return s * atol(p);
}

int
main(void)
{
	printf("%ld\n", reverse(123));
	printf("%ld\n", reverse(-123));
	printf("%ld\n", reverse(INT_MIN));
	printf("%ld\n", reverse(INT_MAX));
	return 0;
}

// If an Integer N, write a program to reverse the given number.
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

int
reverse(int n)
{
	char b[80], *p;
	int l, s;

	l = snprintf(b, sizeof(b), "%d", n);
	p = b;
	s = 1;
	if (b[0] == '-') {
		p = b + 1;
		s = -1;
		l--;
	}
	rev(p, l);
	return atoi(p) * s;
}

int
main(void)
{
	printf("%d\n", reverse(12345));
	printf("%d\n", reverse(31203));
	printf("%d\n", reverse(2123));
	printf("%d\n", reverse(2300));
	printf("%d\n", reverse(-100));
	printf("%d\n", reverse(CHAR_MIN));
	printf("%d\n", reverse(CHAR_MAX));
	printf("%d\n", reverse(SHRT_MIN));
	printf("%d\n", reverse(SHRT_MAX));
	return 0;
}

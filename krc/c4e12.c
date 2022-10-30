// Adapt the ideas of printd to write a recursive version of iota;
// that is, convert an integer into a string by calling a recursive routine
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <threads.h>

char *
itoa(int n, char *s)
{
	thread_local static int i;

	if (n / 10)
		itoa(n / 10, s);
	else {
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}

	s[i++] = labs(n) % 10 + '0';
	s[i] = '\0';
	return s;
}

int
main(void)
{
	char buf[80];
	printf("%s\n", itoa(10, buf));
	printf("%s\n", itoa(INT_MIN, buf));
	printf("%s\n", itoa(INT_MAX, buf));
	printf("%s\n", itoa(340, buf));
	return 0;
}

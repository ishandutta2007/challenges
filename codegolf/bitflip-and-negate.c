/*

Given an integer, make an expression that produces it from 0 using unary negation - and bitwise complement ~ (~n = -n-1), with the operators applied right to left.

...
-3  = ~-~-~0
-2  = ~-~0
-1  = ~0
 0  = 0
 1  = -~0
 2  = -~-~0
 3  = -~-~-~0
...

Your expression must be as short as possible, which means no redundant parts of ~~, --, -0, or 00. Output or print the expression as a string or a sequence of characters.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
number(int n, char *b)
{
	static const char sym[] = "-~";

	size_t l;
	int i;

	l = 0;
	if (n > 0)
		l += sprintf(b + l, "-");
	l += sprintf(b + l, "~");

	n = abs(n);
	for (i = 1; i < n; i++)
		l += sprintf(b + l, "%s", sym);

	sprintf(b + l, "0");
	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	number(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(-3, "~-~-~0");
	test(-2, "~-~0");
	test(-1, "~0");
	test(1, "-~0");
	test(2, "-~-~0");
	test(3, "-~-~-~0");

	return 0;
}

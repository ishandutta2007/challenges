/*

Create a function that takes a number and returns its multiplicative persistence, which is the number of times you must multiply the digits in num until you reach a single digit.

*/

#include <stdio.h>

int
bugger(int n)
{
	char b[80], *p;
	size_t i, l;
	int c, v;

	c = 0;
	v = n;
	for (;;) {
		l = snprintf(b, sizeof(b), "%d", v);
		p = b;
		if (b[0] == '-') {
			l--;
			p++;
		}
		if (l == 1)
			break;

		v = 1;
		for (i = 0; i < l; i++)
			v *= p[i] - '0';
		c++;
	}
	return c;
}

int
main(void)
{
	int i;

	printf("%d\n", bugger(39));
	printf("%d\n", bugger(999));
	printf("%d\n", bugger(4));
	printf("%d\n", bugger(25));
	printf("%d\n", bugger(-999));
	for (i = 0; i <= 1000000; i++)
		printf("%d %d\n", i, bugger(i));
	return 0;
}

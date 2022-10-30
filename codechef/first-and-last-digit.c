// If Give an integer N . Write a program to obtain the sum of the first and last digit of this number.
#include <stdio.h>
#include <stdlib.h>

int
sum(int n)
{
	char b[80], *p;
	int l;

	l = snprintf(b, sizeof(b), "%d", n);
	p = b;
	if (p[0] == '-') {
		p++;
		l--;
	}
	return (p[0] - '0') + (p[l - 1] - '0');
}

int
main(void)
{
	printf("%d\n", sum(1234));
	printf("%d\n", sum(124894));
	printf("%d\n", sum(242323));
	printf("%d\n", sum(-242323));
	printf("%d\n", sum(-124894));
	printf("%d\n", sum(-1234));
	printf("%d\n", sum(-9239));
	printf("%d\n", sum(21130));
	return 0;
}

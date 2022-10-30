/*

Use any programming language to display numbers divisible by 1000000 that are greater than 1 and less than 10000000.
Each number should be displayed in new line. Your program should display exactly:

1000000
2000000
3000000
4000000
5000000
6000000
7000000
8000000
9000000

*/

#include <stdio.h>

typedef unsigned long long uvlong;

void
display(void)
{
	uvlong n, m, s;

	n = s = 1000000ull;
	m = 10000000ull;
	while (n < m) {
		printf("%llu\n", n);
		n += s;
	}
}

int
main(void)
{
	display();
	return 0;
}

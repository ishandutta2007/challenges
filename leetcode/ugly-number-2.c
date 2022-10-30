/*

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

*/

#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

unsigned *
uglysieve(unsigned n)
{
	unsigned *u, i;
	unsigned n2, n3, n5;
	unsigned i2, i3, i5;

	if (n == 0)
		return NULL;

	u = calloc(n, sizeof(*u));
	if (!u)
		return NULL;

	i2 = 0;
	i3 = 0;
	i5 = 0;
	n2 = 2;
	n3 = 3;
	n5 = 5;

	u[0] = 1;
	for (i = 1; i < n; i++) {
		u[i] = min(n2, min(n3, n5));
		if (u[i] == n2)
			n2 = u[++i2] * 2;
		if (u[i] == n3)
			n3 = u[++i3] * 3;
		if (u[i] == n5)
			n5 = u[++i5] * 5;
	}

	return u;
}

void
test(unsigned n)
{
	unsigned *u, i;

	u = uglysieve(n);
	if (!u) {
		printf("oom\n");
		return;
	}
	for (i = 0; i < n; i++) {
		printf("%u ", u[i]);
		if ((i & 15) == 15)
			printf("\n");
	}
	printf("\n");
	free(u);
}

int
main(void)
{
	test(1000);
	return 0;
}

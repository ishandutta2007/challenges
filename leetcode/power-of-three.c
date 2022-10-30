/*

Given an integer, write a function to determine if it is a power of three.

*/

#include <stdio.h>
#include <limits.h>

int
ispow3(int n)
{
	if (n < 1)
		return 0;

	while (n % 3 == 0)
		n /= 3;
	return n == 1;
}

int
ispow3c(int n)
{
	static int x = 0;

	if (n < 1)
		return 0;

	if (x == 0) {
		x = 3;
		while (INT_MAX / 3 > x)
			x *= 3;
	}

	return x % n == 0;
}

int
main(void)
{
	int i;
	for (i = 0; i < INT_MAX; i++) {
		if (ispow3(i))
			printf("%d %d %d\n", i, ispow3(i), ispow3c(i));
	}
	return 0;
}

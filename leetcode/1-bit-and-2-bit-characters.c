/*

We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Note: 
1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
onebit(int *a, size_t n)
{
	if (n == 0)
		return -1;
	if (n == 1)
		return 1;
	return a[n - 1] == 0 && a[n - 2] == 0;
}

int
main(void)
{
	int a[] = {1, 0, 0};
	printf("%d\n", onebit(a, nelem(a)));

	int b[] = {1, 1, 1, 0};
	printf("%d\n", onebit(b, nelem(b)));

	return 0;
}

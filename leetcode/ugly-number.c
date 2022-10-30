/*

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Note:

    1 is typically treated as an ugly number.
    Input is within the 32-bit signed integer range: [−231,  231 − 1].

*/

#include <stdio.h>

int
isugly(unsigned x)
{
	if (x == 0)
		return 0;
	while ((x % 2) == 0)
		x /= 2;
	while ((x % 3) == 0)
		x /= 3;
	while ((x % 5) == 0)
		x /= 5;
	return x == 1;
}

int
main(void)
{
	printf("%d\n", isugly(1));
	printf("%d\n", isugly(6));
	printf("%d\n", isugly(8));
	printf("%d\n", isugly(14));
	return 0;
}

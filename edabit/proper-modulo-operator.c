/*

In JavaScript, the modulo operator is very bad. For example, -13 % 64 = -13, when the actual answer is 51.
Create a function to fix this. It should also work for positive numbers.

Notes

All test cases contain valid numbers.

*/

#include <stdio.h>

int
mod(int a, int b)
{
	a %= b;
	if (a < 0)
		a += b;
	return a;
}

int
main(void)
{
	printf("%d\n", mod(-13, 64));
	printf("%d\n", mod(50, 25));
	printf("%d\n", mod(-6, 3));
	printf("%d\n", mod(-45, 2));
	return 0;
}

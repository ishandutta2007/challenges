/*

All submissions for this problem are available.
Write a program to obtain a number N and increment
its value by 1 if the number is divisible by 4 otherwise decrement its value by 1.

*/
#include <stdio.h>

int
incdec(int n)
{
	return (n % 4 == 0) ? n + 1 : n - 1;
}

int
main(void)
{
	printf("%d\n", incdec(5));
	printf("%d\n", incdec(4));
	printf("%d\n", incdec(-4));
	return 0;
}

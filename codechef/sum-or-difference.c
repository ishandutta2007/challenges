/*

All submissions for this problem are available.
Write a program to take two numbers as input and print their difference
if the first number is greater than the second number otherwise print their sum.

*/
#include <stdio.h>

int
sumdiff(int a, int b)
{
	if (a > b)
		return a - b;
	return a + b;
}

int
main(void)
{
	printf("%d\n", sumdiff(82, 28));
	printf("%d\n", sumdiff(3, 28));
	return 0;
}

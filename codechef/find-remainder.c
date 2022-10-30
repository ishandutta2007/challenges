/*

Write a program to find the remainder when two given numbers are divided. 

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
	printf("%d\n", mod(1, 2));
	printf("%d\n", mod(100, 200));
	printf("%d\n", mod(10, 40));
	return 0;
}

/*

Given two numbers, return true if the sum of both numbers is less than 100. Return false otherwise.

*/

#include <stdio.h>

int
lesser100(int a, int b)
{
	return a + b < 100;
}

int
main(void)
{
	printf("%d\n", lesser100(5, 57));
	printf("%d\n", lesser100(77, 30));
	printf("%d\n", lesser100(0, 59));
	printf("%d\n", lesser100(78, 35));
	printf("%d\n", lesser100(63, 11));
	printf("%d\n", lesser100(37, 99));
	printf("%d\n", lesser100(52, 11));
	printf("%d\n", lesser100(82, 95));
	printf("%d\n", lesser100(17, 44));
	printf("%d\n", lesser100(74, 53));
	printf("%d\n", lesser100(3, 77));
	printf("%d\n", lesser100(25, 80));
	printf("%d\n", lesser100(59, 28));
	printf("%d\n", lesser100(69, 87));
	printf("%d\n", lesser100(10, 45));
	printf("%d\n", lesser100(43, 58));
	printf("%d\n", lesser100(50, 44));
	printf("%d\n", lesser100(74, 89));
	printf("%d\n", lesser100(3, 27));
	printf("%d\n", lesser100(21, 79));
	return 0;
}

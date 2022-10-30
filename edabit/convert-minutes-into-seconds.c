/*

Write a function that takes an integer minutes and converts it to seconds.
Examples

convert(5) ➞ 300

convert(3) ➞ 180

convert(2) ➞ 120

Notes
	Don't forget to return the result.

*/

#include <stdio.h>

int
convert(int m)
{
	return m * 60;
}

int
main(void)
{
	printf("%d\n", convert(5));
	printf("%d\n", convert(3));
	printf("%d\n", convert(2));
	printf("%d\n", convert(6));
	printf("%d\n", convert(4));
	printf("%d\n", convert(8));
	printf("%d\n", convert(60));
	return 0;
}

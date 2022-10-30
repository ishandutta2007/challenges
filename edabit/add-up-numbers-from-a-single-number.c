/*

Create a function that takes a number as an argument. Add up all the numbers from 1 to the number you passed to the function.
For example, if the input is 4 then your function should return 10 because 1 + 2 + 3 + 4 = 10.

Notes

Expect any positive number between 1 and 1000.

*/

#include <stdio.h>

unsigned
addup(unsigned n)
{
	return n * (n + 1) / 2;
}

int
main(void)
{
	printf("%u\n", addup(4));
	printf("%u\n", addup(13));
	printf("%u\n", addup(600));
	printf("%u\n", addup(392));
	printf("%u\n", addup(53));
	printf("%u\n", addup(897));
	printf("%u\n", addup(23));
	printf("%u\n", addup(1000));
	printf("%u\n", addup(738));
	printf("%u\n", addup(100));
	printf("%u\n", addup(925));
	printf("%u\n", addup(1));
	printf("%u\n", addup(999));
	printf("%u\n", addup(175));
	printf("%u\n", addup(111));
	return 0;
}

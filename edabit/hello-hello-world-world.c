/*

Write a function that takes an integer and:

    If the number is a multiple of 3, return "Hello".
    If the number is a multiple of 5, return "World".
    If the number is a multiple of both 3 and 5, return "Hello World".

*/

#include <stdio.h>

const char *
helloworld(unsigned n)
{
	if ((n % 3) == 0 && (n % 5) == 0)
		return "Hello World";
	if ((n % 3) == 0)
		return "Hello";
	if ((n % 5) == 0)
		return "World";
	return "";
}

int
main(void)
{
	printf("%s\n", helloworld(3));
	printf("%s\n", helloworld(5));
	printf("%s\n", helloworld(15));
	printf("%s\n", helloworld(101));
	return 0;
}

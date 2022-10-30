/*

Chef is very interested in image processing. In image processing colours are generally written in hexadecimal.
In his project chef is given a decimal number and he has to convert it in hexadecimal.As chef is very lazy he has given this task to you. 

*/
#include <stdio.h>

char *
hex(int x, char *b, size_t n)
{
	snprintf(b, n, "%x", x);
	return b;
}

int
main(void)
{
	char b[80];
	printf("%s\n", hex(255, b, sizeof(b)));
	printf("%s\n", hex(100, b, sizeof(b)));
	return 0;
}

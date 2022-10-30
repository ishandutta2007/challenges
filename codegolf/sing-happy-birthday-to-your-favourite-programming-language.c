/*

Your favourite programming language has just had a birthday. Be nice and sing it the Happy Birthday song.

Of course you should accomplish this by writing a program in that language. The program takes no input, and writes the following text to the standard output or an arbitrary file:

Happy Birthday to You
Happy Birthday to You
Happy Birthday Dear [your favourite programming language]
Happy Birthday to You
You should substitute the bracketed part (and omit the brackets).

This is a code golf — shortest code wins.

*/

#include <stdio.h>

void
sing(const char *s)
{
	printf("Happy Birthday to You\n");
	printf("Happy Birthday to You\n");
	printf("Happy Birthday Dear %s\n", s);
	printf("Happy Birthday to You\n");
}

int
main(void)
{
	sing("C");
	return 0;
}

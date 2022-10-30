/*

Use any programming language to display "AWSALILAND" in such a way, so that each letter is in a new line and repeated as many times as its position in the English alphabet.
For example letter, (A) should be displayed just once because it is the first letter of the alphabet.
Letter D should be displayed 4 times because it is the 4th letter of the alphabet.

So, the output should be this:

A
WWWWWWWWWWWWWWWWWWWWWWW
SSSSSSSSSSSSSSSSSSS
A
LLLLLLLLLLLL
IIIIIIIII
LLLLLLLLLLLL
A
NNNNNNNNNNNNNN
DDDD

*/

#include <stdio.h>

void
display(const char *s)
{
	size_t i;
	int c, n;

	for (i = 0; s[i]; i++) {
		n = 1;
		c = s[i] & 0xff;
		if ('A' <= c && c <= 'Z')
			n = c - 'A' + 1;

		while (n-- > 0)
			printf("%c", c);

		printf("\n");
	}
}

int
main(void)
{
	display("AWSALILAND");

	return 0;
}

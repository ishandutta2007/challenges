/*

A current internet meme is to type 2spooky4me, with a second person typing 3spooky5me, following the (n)spooky(n+2)me pattern.

Your mission is to implement this pattern in your chosen language. You should write a program or function that takes a value n (from standard input, as a function argument, or closest alternative), and outputs the string (n)spooky(n+2)me (without the parentheses;
to standard output, as a return value for a function, or closest alternative).

Your solution should work for all inputs, from 1 up to 2 below your language's maximum representable integer value (2^32-3 for C on a 32-bit machine, for example).

Example implementation in Python:

def spooky(n):
    return "%dspooky%dme"%(n,n+2)

spooky(2) -> "2spooky4me"

This is code-golf, so standard loopholes are forbidden, and the shortest answer in bytes wins!

*/

#include <stdio.h>

char *
spooky(unsigned n, char *b)
{
	sprintf(b, "%uspooky%ume", n, n + 2);
	return b;
}

int
main(void)
{
	char b[128];

	printf("%s\n", spooky(2, b));
	return 0;
}

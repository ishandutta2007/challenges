/*

Challenge
The challenge is simple: print a snake.
You will get the length of the snake as input.
A snake of length 2 looks like this:

==(:)-
A snake of length 7 looks like this:

=======(:)-
In other words, the length of a snake is how many equal signs are before the head.

Usage
Let's say I made a C++ implementation and compiled it to ./getsnake.
I could run it like so:

$ ./getsnake 10
==========(:)-
Clarifications
Standard loopholes are disallowed.
You can get input and output in any acceptable way.
You can assume all inputs given are positive integers.
You may write a function instead of a regular program.

*/

#include <stdio.h>
#include <stdlib.h>

void
snake(int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("=");
	printf("(:)-\n");
}

void
usage(void)
{
	fprintf(stderr, "usage: <length>\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	if (argc < 2)
		usage();

	snake(atoi(argv[1]));
	return 0;
}

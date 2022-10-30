/*

Introduction

In the error outputs of some languages such as Java, a pointer is shown to give the programmer an idea of exactly where the error went wrong.

Take this example on Ideone:

Main.java:12: error: ';' expected
    Invalid Java!
                ^

Notice the caret shows where the invalid code is?
Challenge

Your challenge is: given number N and string S, place a pointer on the Nth character in S.
Examples

Input: 2, "Lorem ipsum, dollar sit amet."

Output:

Lorem ipsum, dollar sit amet.
 ^

Rules

    Input is received via STDIN or function parameters
    Output is printed out to the console or returned
    Trailing new lines, spaces etc are allowed in the output
    The pointer character must be a ^ caret and must be on a new line.
    This is code golf, so the shortest answer wins. Good luck!

*/

#include <stdio.h>

void
pointer(size_t p, const char *s)
{
	size_t i;

	printf("%s\n", s);
	for (i = 1; i < p; i++)
		printf(" ");
	printf("^\n");
}

int
main(void)
{
	pointer(2, "Lorem ipsum, dollar sit amet.");
	pointer(13, "Invalid Java!");

	return 0;
}

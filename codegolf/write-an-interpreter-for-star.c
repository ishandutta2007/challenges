/*

The task is simple. Write an interpreter for the language *.

Here's a bigger link to the wiki.

There are only three valid * programs:

    * Prints "Hello World"
     *  Prints a random number between 0 and 2,147,483,647
    *+* Runs forever.

The third case must be an infinite loop according to the specifications in this question
Input:

    The input can be taken via any acceptable input method by our standard I/O rules
    It will always be one of the above programs

Output:

    The first case should print exactly Hello World, with or without a trailing line break.
    For the second case, if your language's integer maximum is smaller than 2,147,483,647, use your language's integer maximum
    The first and second cases can print to any acceptable output by our standard I/O rules.
    The third case should not give any output.

Scoring:

As this is code-golf, the shortest answer, in bytes, wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int
interpret(const char *s)
{
	int r;

	r = 0;
	if (!strcmp(s, "*"))
		printf("Hello World\n");
	else if (!strcmp(s, " * "))
		printf("%d\n", rand());
	else if (!strcmp(s, "*+*")) {
		for (;;)
			;
	} else
		r = -1;
	return r;
}

int
main(void)
{
	srand(time(NULL));

	interpret("*");
	interpret(" * ");

	return 0;
}

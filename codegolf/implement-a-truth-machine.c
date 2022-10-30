/*


A truth-machine (credits goes to this guy for coming up with it) is a very simple program designed to demonstrate the I/O and control flow of a language. Here's what a truth-machine does:

    Gets a number (either 0 or 1) from STDIN.

    If that number is 0, print out 0 and terminate.

    If that number is 1, print out 1 forever.

Challenge

Write a truth-machine as described above in your language of choice. The truth-machine must be a full program that follows these rules:

    take input from STDIN or an acceptable alternative
        If your language cannot take input from STDIN, it may take input from a hardcoded variable or suitable equivalent in the program
    must output to STDOUT or an acceptable alternative
        If your language is incapable of outputting the characters 0 or 1, byte or unary I/O is acceptable.
    when the input is 1, it must continually print 1s and only stop if the program is killed or runs out of memory

    the output must only be either a 0 followed by either one or no newline or space, or infinite 1s with each 1 followed by either one or no newline or space. No other output can be generated, except constant output of your language's interpreter that cannot be suppressed (such as a greeting, ANSI color codes or indentation). Your usage of newlines or spaces must be consistent: for example, if you choose to output 1 with a newline after it all 1s must have a newline after them.

    if and only if your language cannot possibly terminate on an input of 0 it is acceptable for the code to enter an infinite loop in which nothing is outputted.

Since this is a catalog, languages created after this challenge are allowed to compete. Note that there must be an interpreter so the submission can be tested.
It is allowed (and even encouraged) to write this interpreter yourself for a previously unimplemented language.
Other than that, all the standard rules of code-golf must be obeyed. Submissions in most languages will be scored in bytes in an appropriate preexisting encoding (usually UTF-8).

*/

#include <stdio.h>

int
main(void)
{
	int v;

	while (scanf("%d", &v) == 1) {
		if (v == 0) {
			printf("0");
			break;
		}
		if (v == 1) {
			for (;;)
				printf("1");
		}
	}

	return 0;
}

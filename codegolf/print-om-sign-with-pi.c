/*

This time I will give you an easy challenge:
Print the Om sign with π
!(Sorry for many challenges with π)

Here is the om sign drawn using pi numbers:

            59  0  64
              230781
3.14159
      26      502884
     535 83279     1971
   89 433              6939
       79    44         937
       323    749     510
    84            58209
626

Here is the sequence I used to order the numbers of π
:

om sign
Rules

    There will be no input(except it has to be)
    The program should print the sign to STDOUT
    Its's code-golf, so the shortest code in bytes wins!
    You must include all the spaces and line breaks in the original text.

Good luck

*/

#include <stdio.h>

int
main(void)
{
	const char *txt =
	    "            59  0  64\n"
	    "              230781\n"
	    "3.14159\n"
	    "      26      502884\n"
	    "     535 83279     1971\n"
	    "   89 433              6939\n"
	    "       79    44         937\n"
	    "       323    749     510\n"
	    "    84            58209\n"
	    "626\n";

	printf("%s", txt);
	return 0;
}

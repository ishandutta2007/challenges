/*

Challenge Description:

Write a program that asks the user for input. The user will enter Good or Bad. You do not have to support any other input. If the user enters Good, print Bad and vice versa (to stdout etc).

Notes:

1) You cannot use any other pair of two words.

2) Your program only has to ask and print once.

3) You do not need to display prompt string.

4) The output must appear separated from the input by any means.

5) No function is allowed accepting the value and returning the result; User must interact with the program.

Good luck!

*/

#include <stdio.h>
#include <string.h>

int
main(void)
{
	char b[32];

	b[0] = '\0';
	scanf("%31s", b);
	if (!strcmp(b, "Good"))
		printf("Bad\n");
	else if (!strcmp(b, "Bad"))
		printf("Good\n");
	return 0;
}

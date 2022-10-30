/*

Task

Given a non-negative number, check if it's odd or even. In case it's even, output that number.
Otherwise, throw any exception/error that your language supports, and stop the program.

Example with Python

Input: 1
Output:

Traceback (most recent call last):
  File ".code.tio", line 1, in <module>
    IfYouWantThenThrowThis
NameError: name 'IfYouWantThenThrowThis' is not defined

Another example

Input: 2
Output: 2
Rules

    This is code-golf, so the answer with shortest bytes wins.
    These loopholes are, obviously, forbidden.
    Standard code-golf rules apply.
    Please specify the language you are using and the amount of bytes.
    It would be great if you would put a link to a sandbox where your code can be ran in action, such as TIO.
    Explaining your code is very welcomed.

*/

#include <assert.h>
#include <stdio.h>

void
output(int n)
{
	assert(!(n & 1));
	printf("%d\n", n);
}

int
main(void)
{
	output(2);
	output(4);
	output(1);

	return 0;
}

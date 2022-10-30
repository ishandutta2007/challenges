/*

Info

Create a diagonal line given its length (lets call the variable say n where n>0)

    The diagonal line starts from top left and goes to bottom right.
    You must use the ascii character \ for the line.
    The input number can be given from STDIN or if your program doesnt support that use a hardcoded value in your code or pass it as an argument while running the program.
    For padding only use the space character 0x20
    Trailing spaces and/or newlines are allowed.
    The length of the line is the non whitespace characters

Here is an example program (59 bytes)

n = int(input())
for i in range(n):
  print(' ' * i + '\\')

Try it online!

Example:

Input: 4
Output
\
 \
  \
   \

Rules

    Use Standard I/O when possible.
    Standard Loopholes are forbidden.
    This is code golf so the shortest answer in bytes wins.
    Please explain the code that you wrote.

*/

#include <stdio.h>

void
line(int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++)
			printf(" ");
		printf("\\\n");
	}
}

int
main(void)
{
	int i;

	for (i = 4; i <= 20; i += 4)
		line(i);
	return 0;
}

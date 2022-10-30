/*

The task is to display n characters of the ASCII table.

You may write a function (or a program that takes the argument as a parameter, STDIN is allowed as well) that takes a parameter n, which will be the index of the last character to print.

The task is quite simple, so as an example here's a possible implementation in Python 2.7:

(lambda n:map(chr, range(n)))(256)

As I said it's a simple task. So this is code-golf and the shortest codes wins!

EDIT

As some of you pointed out this code doesn't print the result. It's just an example since I might struggle explaining the problem in english ;-).

EDIT2

Feel free to post the answer in any programming language, even if it's not the shortest code. Maybe there are some interesting implementations out there!

EDIT3

Fixed the example so it prints the result.

*/

#include <stdio.h>
#include <ctype.h>

void
print(int n)
{
	int i;

	for (i = 0; i <= n; i++) {
		printf("%-3d %-2x %-3o | ", i, i, i);
		if (isprint(i))
			printf("'%c'", i);
		printf("\n");
	}
}

int
main(void)
{
	print(127);
	return 0;
}

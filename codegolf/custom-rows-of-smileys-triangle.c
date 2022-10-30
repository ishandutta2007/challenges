/*

This problem is inspired from shinh's problem.

Given an input of positive integer n, output a smiley triangle (see below) with n rows.

Detailed rules

    Can be either a function or a full program.
    Standard I/O rules applied.
    Standard loopholes are forbitten.
    This is code-golf. Shortest code wins.

Valid output syntax

Assuming ASCII encoding. A smiley triangle with n

rows triangle(n), where n>=1, should be output. <0xXX> is a character with such codepoint, in hexadecimal.

triangle(n) = triangle(n) <0x0a> | triangle_(n)
triangle_(1) = <0x3a> spaces
triangle_(n) = triangle_(n-1) <0x0a> row(n) spaces
row(2) = <0x3a> <0x2d>
row(n) = row(n-1) <0x29>
spaces = <0x09> spaces | <0x20> spaces | *empty*

Example outputs

If n is 1, then

:

If n is 2, then

:
:-

If n=5, then

:
:-
:-)
:-))
:-)))

*/

#include <stdio.h>

void
row(int n)
{
	if (n < 2)
		return;
	if (n == 2) {
		printf("\x3a\x2d");
		return;
	}
	row(n - 1);
	printf("\x29");
}

void
triangle(int n)
{
	if (n < 1)
		return;
	if (n == 1) {
		printf("\x3a");
		return;
	}
	triangle(n - 1);
	printf("\n");
	row(n);
}

void
smiley(int n)
{
	printf("n=%d\n", n);
	triangle(n);
	printf("\n\n");
}

int
main(void)
{
	smiley(1);
	smiley(2);
	smiley(5);
	return 0;
}

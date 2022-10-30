/*

Output/print this block of text:

1234567890
2468013579
3691470258
4815926037
5049382716
6172839405
7306295184
8520741963
9753108642
0987654321
Acceptable formats include:

Trailing newlines/whitespace
List of strings
List of lists of characters
List of lists of integers
However, list of integers is not acceptable because the last line is not an integer.

This is code-golf. Shortest answer in bytes wins. Standard loopholes apply.

*/

#include <stdio.h>

void
block(void)
{
	puts("1234567890");
	puts("2468013579");
	puts("3691470258");
	puts("4815926037");
	puts("5049382716");
	puts("6172839405");
	puts("7306295184");
	puts("8520741963");
	puts("9753108642");
	puts("0987654321");
}

int
main(void)
{
	block();

	return 0;
}

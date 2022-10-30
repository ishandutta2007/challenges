/*

The Challenge
Given a string, output the text in the shape of a square.

You can assume that the text will always fit in a square, and that it will never be an empty string.

You can also assume it will never have newlines.

Example
Input:
Hi, world

Output:
Hi,
 wo
rld
Test Cases
Input:
Hi, world! Hello

Output:
Hi,
worl
d! H
ello

Input:
Lorem ipsum dolor sit amt

Output:
Lorem
 ipsu
m dol
or si
t amt

Input:
H

Output:
H

Rules
This is code-golf, so shortest answer in bytes wins! Tiebreaker is most upvoted answer.
Standard loopholes are forbidden.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void
st(const char *s)
{
	size_t i, j, n;

	n = sqrt(strlen(s));
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%c", *s++);
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	st("Hi, world");
	st("Hi, world! Hello");
	st("Lorem ipsum dolor sit amt");
	st("H");

	return 0;
}

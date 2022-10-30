/*

Introduction

XOR is a digital logic gate that implements an exclusive or. Most of the times, this is shown as ^. The four possible outcomes in binary:

0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0

This can also be seen as addition modulo 2 in binary. In decimal, we need to convert the decimal to binary, 35 = 100011 and 25 = 11001.To compute the XOR value, we place them on top of each other:

100011
 11001 ^
--------
111010  = 58 in decimal

The task: When given an integer value N greater than 1, output an XOR table with the size N + 1. For example, N = 5:

 0 1 2 3 4 5
 1 0 3 2 5 4
 2 3 0 1 6 7
 3 2 1 0 7 6
 4 5 6 7 0 1
 5 4 7 6 1 0

You can see that there is one space in front of each number, because the highest amount in the table has length 1. However, if we take N = 9, we get the following grid:

  0  1  2  3  4  5  6  7  8  9
  1  0  3  2  5  4  7  6  9  8
  2  3  0  1  6  7  4  5 10 11
  3  2  1  0  7  6  5  4 11 10
  4  5  6  7  0  1  2  3 12 13
  5  4  7  6  1  0  3  2 13 12
  6  7  4  5  2  3  0  1 14 15
  7  6  5  4  3  2  1  0 15 14
  8  9 10 11 12 13 14 15  0  1
  9  8 11 10 13 12 15 14  1  0

The highest value has length 2, so the value is right-aligned to length 3 (highest length + 1).

Rules:

    Leading whitespace is not mandatory, only if used (or not) consistently
    You must output a table in the form shown above.
    The padding between columns should be as small as possible
    This is code-golf, so the submission with the least amount of bytes wins!

*/

#include <stdio.h>
#include <math.h>

void
xortable(unsigned n)
{
	unsigned i, j, l;

	l = ceil(log10(n)) + 1;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			printf("%*u", l, i ^ j);
			if (j + 1 <= n)
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	xortable(5);
	xortable(9);
	return 0;
}

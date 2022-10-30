/*

Given a number and either "+" or "*", return an addition or multiplication table with the dimensions of that number.

Specifications

    The input will be formatted as dimension, operation.
    The program should not return anything if the operation input is not + or *.
    The program should not return anything if the dimension input is less than 1.

(4,*):
1 2 3 4
2 4 6 8
3 6 9 12
4 8 1216


(4,+):
1234
2456
3567
4678

The spaces between the numbers in the table should be equal to one less than the number of digits in dimension^2 for multiplication, and for addition one less than the number of digits in dimension * 2.

*/

#include <stdio.h>
#include <math.h>

void
table(unsigned n, int op)
{
	unsigned i, j, p, v;

	p = log2(n * n + 1);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			v = 0;
			switch (op) {
			case '+':
				v = i + (j - 1);
				if (i > 1 && j > 1)
					v++;
				break;
			case '*':
				v = i * j;
				break;
			}

			printf("%-*u", p, v);
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	table(4, '*');
	table(4, '+');
	table(5, '*');
	table(5, '+');

	return 0;
}

/*

The Seven-Eleven problem is find 4 positive numbers (with two decimal digits, A.BC) such that their sum is equal to their product and is equal to 7.11.

a + b + c + d = a * b * c * d = 7.11
0 < a <= b <= c <= d

Write the shortest program to compute all non-decreasing quadruples. Precomputing the values is not allowed.

*/

#include <stdio.h>

void
seveneleven(void)
{
	long a, b, c, d;

	for (a = 1; a <= 711 / 4; a++) {
		for (b = a; b <= 711 / 4; b++) {
			for (c = b; c <= 711 / 4; c++) {
				d = 711 - (a + b + c);
				if (d < c)
					break;

				if (a * b * c * d == 711000000l)
					printf("a = %.2f, b = %.2f, c = %.2f, d = %.2f\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);
			}
		}
	}
}

int
main(void)
{
	seveneleven();
	return 0;
}

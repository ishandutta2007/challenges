/*

Given a number n, write a function that returns PI to n decimal places.

Examples

myPi(5) ➞ 3.14159

myPi(4) ➞ 3.1416

myPi(15) ➞ 3.141592653589793

Notes

    n will not be above 15, to keep this challenge simple.
    Round up the last digit if the next digit in PI is greater or equal to 5 (see second example above).
    The return value must be a number, not a string.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double
pi(unsigned n)
{
	static const char digits[] = "3.141592653589793";
	char b[32];

	if (n >= 15)
		n = 15;
	strncpy(b, digits, n + 2);
	b[n + 2] = '\0';
	return atof(b);
}

int
main(void)
{
	unsigned i;

	for (i = 0; i <= 15; i++)
		printf("%u %.15f\n", i, pi(i));

	return 0;
}

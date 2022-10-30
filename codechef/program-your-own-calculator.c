/*
All submissions for this problem are available.Write a program to obtain 2 numbers ( A and B ) and an arithmetic operator (C) and then design a calculator

depending upon the operator entered by the user.

So for example if C="+", you have to sum the two numbers.

If C="-", you have to subtract the two numbers.

If C=" * ", you have to print the product.

If C=" / ", you have to divide the two numbers.
*/
#include <stdio.h>
#include <math.h>

double
calc(int op, double a, double b)
{
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			return NAN;
		return a / b;
	}
	return 0;
}

int
main(void)
{
	printf("%.2lf\n", calc('/', 8, 2));
	printf("%.2lf\n", calc('+', 5, 3));
	return 0;
}

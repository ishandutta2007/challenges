/*

Create a function that outputs the results of a flashcard. A flashcard is an array of three elements: a number, an operator symbol, and another number. Return the mathematical result of that expression.

There are 4 operators: + (addition), - (subtraction), x (multiplication), and / (division).
If the flashcard displays a number being divided by zero, e.g. [3, "/", 0], then return undefined.
For division, round to the hundredths place. So [10, "/", 3] should return 3.33.

Examples

flash([3, "x", 7]) ➞ 21

flash([5, "+", 7]) ➞ 12

flash([10, "-", 9]) ➞ 1

flash([10, "/", 0]) ➞ undefined

flash([10, "/", 3]) ➞ 3.33

Notes

Flash cards contain only zero or positive numbers.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
flash(double x, int op, double y)
{
	switch (op) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	case 'x':
		return x * y;
	case '/':
		if (y == 0)
			return NAN;
		return x / y;
	}
	return NAN;
}

void
test(double x, int op, double y, double r)
{
	double p;

	p = flash(x, op, y);
	printf("%f %f\n", p, r);
	if (isnan(p))
		assert(isnan(r));
	else
		assert(fabs(p - r) < 1e-2);
}

int
main(void)
{
	test(3, 'x', 7, 21);
	test(5, '+', 7, 12);
	test(10, '-', 9, 1);
	test(10, '/', 0, NAN);
	test(10, '/', 3, 3.33);
	test(2, 'x', 0, 0);
	test(0, '/', 5, 0);
	test(0, '+', 0, 0);
	test(0, '-', 0, 0);
	test(8, '-', 0, 8);
	test(0, '/', 0, NAN);
	test(3, '/', 8, 0.38);

	return 0;
}

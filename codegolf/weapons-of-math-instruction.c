/*

Last time when I tried to come up with something easy that wasn't a duplicate, it ended up being way too hard.. So hopefully this time it's indeed something newcomers can try as well.

Input:

An array/list with integers/decimals. (Or a string representing an array with integers/decimals.)

Output:

Loop through the numbers and apply the following five mathematical operands in this order:

    Addition (+);
    Subtraction (−);
    Multiplication (* or × or ·);
    Real / Calculator Division (/ or ÷);
    Exponentiation (^ or **).

(NOTE: The symbols between parenthesis are just added as clarification. If your programming language uses a completely different symbol for the mathematical operation than the examples, then that is of course completely acceptable.)

Keep continuing until you've reached the end of the list, and then give the result of the sum.

Challenge rules:

    Exponentiation by 0 (n ^ 0) should result in 1 (this also applies to 0 ^ 0 = 1).
    There are no test cases for division by 0 (n / 0), so you don't have to worry about that edge-case.
    If the array contains just a single number, we return that as the result.

General rules:

    This is code-golf, so shortest answer in bytes wins.
    Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
    Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
    Default Loopholes are forbidden.
    If possible, please add a link with a test for your code.

Test cases:

[1,2,3,4,5] -> 0
-> 1 + 2 = 3
  -> 3 - 3 = 0
    -> 0 * 4 = 0
      -> 0 / 5 = 0

[5,12,23,2,4,4,2,6,7] -> 539
-> 5 + 12 = 17
  -> 17 - 23 = -6
    -> -6 * 2 = -12
      -> -12 / 4 = -3
        -> -3 ^ 4 = 81
          -> 81 + 2 = 83
            -> 83 - 6 = 77
              -> 77 * 7 -> 539

[-8,50,3,3,-123,4,17,99,13] -> -1055.356...
-> -8 + 50 = 42
  -> 42 - 3 = 39
    -> 39 * 3 = 117
      -> 117 / -123 = -0.9512...
        -> -0.9512... ^ 4 = 0.818...
          -> 0.818... + 17 = 17.818...
            -> 17.818... - 99 -> -81.181...
              -> -81.181... * 13 = -1055.356...

[2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2] -> 256
-> 2 + 2 = 4
  -> 4 - 2 = 2
    -> 2 * 2 = 4
      -> 4 / 2 = 2
        -> 2 ^ 2 = 4
          -> 4 + 2 = 6
            -> 6 - 2 = 4
              -> 4 * 2 = 8
                -> 8 / 2 = 4
                  -> 4 ^ 2 = 16
                    -> 16 + 2 = 18
                      -> 18 - 2 = 16
                        -> 16 * 2 = 32
                          -> 32 / 2 = 16
                            -> 16 ^ 2 = 256

[1,0,1,0,1,0] -> 1
-> 1 + 0 = 1
  -> 1 - 1 = 0
    -> 0 * 0 = 0
      -> 0 / 1 = 0
        -> 0 ^ 0 = 1

[-9,-8,-1] -> -16
  -> -9 + -8 = -17
    -> -17 - -1 = -16

[0,-3] -> -3
  -> 0 + -3 = -3

[-99] -> -99

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
binop(int op, double x, double y)
{
	switch (op) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	case '^':
		return pow(x, y);
	}
	return 0;
}

double
apply(double *a, size_t n)
{
	static const char op[] = {'+', '-', '*', '/', '^'};
	size_t i;
	double r;

	if (n == 0)
		return 0;

	r = a[0];
	for (i = 1; i < n; i++)
		r = binop(op[(i - 1) % nelem(op)], r, a[i]);
	return r;
}

void
test(double *a, size_t n, double r)
{
	double p;

	p = apply(a, n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-3);
}

int
main(void)
{
	double a1[] = {1, 2, 3, 4, 5};
	double a2[] = {5, 12, 23, 2, 4, 4, 2, 6, 7};
	double a3[] = {-8, 50, 3, 3, -123, 4, 17, 99, 13};
	double a4[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	double a5[] = {1, 0, 1, 0, 1, 0};
	double a6[] = {-9, -8, -1};
	double a7[] = {0, -3};
	double a8[] = {-99};

	test(a1, nelem(a1), 0);
	test(a2, nelem(a2), 539);
	test(a3, nelem(a3), -1055.356);
	test(a4, nelem(a4), 256);
	test(a5, nelem(a5), 1);
	test(a6, nelem(a6), -16);
	test(a7, nelem(a7), -3);
	test(a8, nelem(a8), -99);

	return 0;
}

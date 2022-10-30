/*

Challenge
Given a (floating-point/decimal) number, return its reciprocal, i.e. 1 divided by the number. The output must be a floating-point/decimal number, not just an integer.

Detailed specification
You must receive input in the form of a floating-point/decimal number...
...which has at least 4 significant digits of precision (if needed).
More is better, but does not count in the score.
You must output, with any acceptable output method...
...the reciprocal of the number.
This can be defined as 1/x, x⁻¹.
You must output with at least 4 significant digits of precision (if needed).
Input will be positive or negative, with absolute value in the range [0.0001, 9999] inclusive. You will never be given more than 4 digits past the decimal point, nor more than 4 starting from the first non-zero digit. Output needs to be accurate up to the 4th digit from the first non-zero one.

(Thanks @MartinEnder)

Here are some sample inputs:

0.5134
0.5
2
2.0
0.2
51.2
113.7
1.337
-2.533
-244.1
-0.1
-5
Note that you will never be given inputs which have above 4 digits of precision.

Here is a sample function in Ruby:

def reciprocal(i)
    return 1.0 / i
end

Rules
All accepted forms of output are allowed
Standard loopholes banned
This is code-golf, shortest answer in bytes wins, but will not be selected.

Clarifications
You will never receive the input 0.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
reciprocal(double x)
{
	return 1.0 / x;
}

int
main(void)
{
	static const double tab[] = {
	    0.5134,
	    0.5,
	    2,
	    2.0,
	    0.2,
	    51.2,
	    113.7,
	    1.337,
	    -2.533,
	    -244.1,
	    -0.1,
	    -5,
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		printf("%.4f\n", reciprocal(tab[i]));

	return 0;
}

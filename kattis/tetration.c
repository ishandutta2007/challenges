/*

Anthony is just now learning basic math, how exciting! He first learns about addition

a + n = a + 1 + 1 + 1 ...+ 1 (n times)

then multiplication
a x n = a + a + a ... + a (n times)

exponentiation
a^n = a x a x a ... x a (n times)

and finally, tetration
n^a = a ^ a ^ a ^ a ... ^ a (n times)

Very quickly, Anthony becomes interested in infinite tetrations, namely ∞a=a^a⋅⋅⋅.

Anthony wonders, given an arbitrary real number N, what is the solution to ∞a=N?

Unable to figure it out, Anthony has asked you to write a program to help him!

Here’s a fun fact: A solution only exists for 1/e≤N≤e.

Input

The first line of input contains one real number N, 0.36788≤N≤2.718281.

Output

Output a single line containing a real number a, such that ∞a=N.
Your answer will be considered correct if its absolute or relative error doesn’t exceed 10^-5.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
tetration(double n)
{
	return pow(n, 1 / n);
}

void
test(double n, double r)
{
	double p;

	p = tetration(n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-5);
}

int
main(void)
{
	test(2.000000, 1.414214);
	test(1.000000, 1.000000);
	test(1.500000, 1.310371);

	return 0;
}

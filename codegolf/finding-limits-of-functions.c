/*

A limit in math determines the value that a function f(x) approaches as x gets closer and closer to a certain value.

Let me use the equation f(x)=x^2/x as an example.
Obviously, f(x) is undefined if x is 0 (x=0, x2=0, 0/0 is undefined).
But, what happens when we calculate f(x) as x approaches 0?

x=0.1, f(x)=0.01/0.1 = 0.1
x=0.01, f(x)=0.0001/0.01 = 0.01
x=0.00001, f(x)=0.0000000001/0.00001 = 0.00001
We can easily see that f(x) is approaching 0 as x approaches 0.

What about when f(x)=1/x^2, and we approach 0?

x=0.1, f(x)=1/0.01=100
x=0.01, f(x)=1/0.0001=10000
x=0.00001, f(x)=1/0.0000000001=10000000000
As x approaches 0, f(x) approaches positive infinity.

You will be given two things in whatever input format you like:

f(x) as an eval-able string in your language
a as a floating point
Output the value that f(x) approaches when x approaches a. Do not use any built-in functions that explicitly do this.

Input Limitations:

The limit of f(x) as x approaches a will always exist.
There will be real-number values just before and just after f(a): you will never get f(x)=sqrt(x), a=-1 or anything of the sort as input.
Output Specifications:

If f(x) approaches positive or negative infinity, output +INF or -INF, respectively.
If f(a) is a real number, then output f(a).
Test Cases:

f(x)=sin(x)/x, a=0; Output: 1
f(x)=1/x^2, a=0; Output: +INF
f(x)=(x^2-x)/(x-1), a=1; Output: 1
f(x)=2^x, a=3; Output: 8
Shortest code wins. Good luck!

*/

#include <stdio.h>
#include <math.h>
#include <float.h>

double
limit(double (*f)(double), double a)
{
	double s, x, y;
	double e, ne;
	int i;

	e = DBL_MAX;
	s = 0.01;
	x = f(a + s);
	for (i = 0; i < 10; i++) {
		s *= 0.1;
		y = f(a + s);

		ne = fabs(y - x);
		if (ne > e)
			return (y < 0) ? -INFINITY : INFINITY;

		e = ne;
		x = y;
	}
	return y;
}

double
f1(double x)
{
	return sin(x) / x;
}

double
f2(double x)
{
	return 1 / (x * x);
}

double
f3(double x)
{
	return ((x * x) - x) / (x - 1);
}

double
f4(double x)
{
	return pow(2, x);
}

double
f5(double x)
{
	return -1 / x;
}

double
f6(double x)
{
	return x;
}

double
f7(double x)
{
	return (x * x) / x + 4;
}

double
f8(double x)
{
	return cos(x) / x;
}

int
main(void)
{
	printf("%f\n", limit(f1, 0));
	printf("%f\n", limit(f2, 0));
	printf("%f\n", limit(f3, 1));
	printf("%f\n", limit(f4, 3));
	printf("%f\n", limit(f5, 0));
	printf("%f\n", limit(f6, 2340));
	printf("%f\n", limit(f7, 0));
	printf("%f\n", limit(f8, 0));

	return 0;
}

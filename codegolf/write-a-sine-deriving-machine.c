/*

The Challenge

Your challenge is to write a program that evaluates the following function:

f(x, t) = d^x / dt^x (sin t)

That is, the x-th derivative of sin t. In case you aren't familiar with calculus, here is a table of derivatives for the sine function:

...

f(-1, t) = -cos t

f(0, t) = sin t

f(1, t) = cos t

f(2, t)= -sin t

...

The sequence repeats these 4 functions.
The Inputs

Your program should take in an integer to be used as the x value in the function, and a float to be used at the t value in the function.

Your program may use radians or degrees for the sine function.
The Output

Your program should output the value of f(x, t) given the integer x and float t.
Scoring

This is code-golf, so the shortest answer (in bytes) wins.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
dsin(int n, double x)
{
	return sin(x + M_PI / 2 * n);
}

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
main(void)
{
	double u[4], v[4];
	double x;
	int i, n;

	for (x = 0; x <= 2 * M_PI; x += 0.01) {
		for (i = -1; i <= 2; i++) {
			n = mod(i, 4);
			switch (n) {
			case 0:
				u[0] = sin(x);
				break;
			case 1:
				u[1] = cos(x);
				break;
			case 2:
				u[2] = -sin(x);
				break;
			case 3:
				u[3] = -cos(x);
				break;
			}
			v[n] = dsin(n, x);
		}

		printf("%f %f %f %f\n", u[0], u[1], u[2], u[3]);
		printf("%f %f %f %f\n", v[0], v[1], v[2], v[3]);
		printf("\n");

		for (i = 0; i < 4; i++)
			assert(fabs(u[i] - v[i]) < 1e-8);
	}

	return 0;
}

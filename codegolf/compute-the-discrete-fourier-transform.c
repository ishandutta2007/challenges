/*

Implement the Discrete Fourier Transform (DFT) for a sequence of any length. This may implemented as either a function or a program and the sequence can be given as either an argument or using standard input.

The algorithm will compute a result based on standard DFT in the forward direction. The input sequence has length N and consists of [x(0), x(1), ..., x(N-1)].
The output sequence will have the same length and consists of [X(0), X(1), ..., X(N-1)] where each X(k) is defined by the relation below.

Xk=def∑n=0N−1xn⋅e−2πikn/N

Rules

    This is code-golf so the shortest solution wins.
    Builtins that compute the DFT in forward or backward (also known as inverse) directions are not allowed.
    Floating-point inaccuracies will not be counted against you.

Test Cases

DFT([1, 1, 1, 1]) = [4, 0, 0, 0]
DFT([1, 0, 2, 0, 3, 0, 4, 0]) = [10, -2+2j, -2, -2-2j, 10, -2+2j, -2, -2-2j]
DFT([1, 2, 3, 4, 5]) = [15, -2.5+3.44j, -2.5+0.81j, -2.5-0.81j, -2.5-3.44j]
DFT([5-3.28571j, -0.816474-0.837162j, 0.523306-0.303902j, 0.806172-3.69346j, -4.41953+2.59494j, -0.360252+2.59411j, 1.26678+2.93119j] = [2, -3j, 5, -7j, 11, -13j, 17]

Help

There was a previous challenge for finding the DFT using a FFT algorithm for sequences with lengths equal to a power of 2.
You may find some tricks there that might help you here. Keep in mind that this challenge does not limit you to any complexity and also requires your solution to work for sequences of any length.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dft(double complex *in, double complex *out, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		out[i] = 0;
		for (j = 0; j < n; j++)
			out[i] += in[j] * cexp(-2 * M_PI * I * i * j / n);
	}
}

void
dump(double complex *p, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%f%+fi\n", creal(p[i]), cimag(p[i]));
	printf("\n");
}

void
test(double complex *x, size_t n, double complex *y)
{
	static const double eps = 1e-2;
	double complex p[128];
	size_t i;

	dft(x, p, n);
	dump(p, n);
	for (i = 0; i < n; i++) {
		assert(fabs(creal(y[i] - p[i])) < eps);
		assert(fabs(cimag(y[i] - p[i])) < eps);
	}
}

int
main(void)
{
	double complex x1[] = {1, 1, 1, 1};
	double complex y1[] = {4, 0, 0, 0};

	double complex x2[] = {1, 0, 2, 0, 3, 0, 4, 0};
	double complex y2[] = {10, -2 + 2 * I, -2, -2 - 2 * I, 10, -2 + 2 * I, -2, -2 - 2 * I};

	double complex x3[] = {1, 2, 3, 4, 5};
	double complex y3[] = {15, -2.5 + 3.44 * I, -2.5 + 0.81 * I, -2.5 - 0.81 * I, -2.5 - 3.44 * I};

	double complex x4[] = {5 - 3.28571 * I, -0.816474 - 0.837162 * I, 0.523306 - 0.303902 * I, 0.806172 - 3.69346 * I, -4.41953 + 2.59494 * I, -0.360252 + 2.59411 * I, 1.26678 + 2.93119 * I};
	double complex y4[] = {2, -3 * I, 5, -7 * I, 11, -13 * I, 17};

	test(x1, nelem(x1), y1);
	test(x2, nelem(x2), y2);
	test(x3, nelem(x3), y3);
	test(x4, nelem(x4), y4);

	return 0;
}

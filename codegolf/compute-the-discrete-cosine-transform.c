/*

Implement the Discrete Cosine Transform (DCT). This may implemented as either a function or a program and the sequence can be given as either an argument or using standard input.
Your program must be able to handle sequences of any length (assuming a hypothetical version of your language which has no limits on things like memory and integer size).

There was a previous challenge for DFT, now lets compute DCT! ;-)

Use the DCT-II definition from Wikipedia:

DCT-II

Your program takes a sequence xn as input, and must produce the corresponding sequence Xk. In this formula, the cosine is in radians.
Rules

    This is code-golf so the shortest solution wins.
    Builtins that compute the DCT in forward or backward (also known as inverse) directions are not allowed.
    Floating-point inaccuracies will not be counted against you.
    You don't have to use the exact algorithm shown here, as long as you produce the same results.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dct2(double *in, double *out, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		out[i] = 0;
		for (j = 0; j < n; j++)
			out[i] += in[j] * cos(M_PI / n * (j * 1.0 + 0.5) * i);
	}
}

void
dump(double *p, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%f\n", p[i]);
	printf("\n");
}

void
test(double *x, size_t n, double *y)
{
	static const double eps = 1e-2;
	double p[128];
	size_t i;

	dct2(x, p, n);
	dump(p, n);
	for (i = 0; i < n; i++)
		assert(fabs(y[i] - p[i]) < eps);
}

int
main(void)
{
	double x1[] = {1, 2, 3, 4};
	double y1[] = {10, -3.1543220298989496, -8.881784197001252e-16, -0.22417076458398388};

	double x2[] = {495, 364, 7, 43, 7458};
	double y2[] = {8367, -6433.52745697727, 6301.342239553353, -4398.037853443233, 2135.3422395533503};

	test(x1, nelem(x1), y1);
	test(x2, nelem(x2), y2);

	return 0;
}

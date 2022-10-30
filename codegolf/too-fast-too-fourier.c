/*

Implement the Fast Fourier Transform in the fewest possible characters.

Rules:

Shortest solution wins

It can be assumed that the input is a 1D array whose length is a power of two.

You may use the algorithm of your choice, but the solution must actually be a Fast Fourier Transform, not just a naive Discrete Fourier Transform (that is, it must have asymptotic computation cost of O(NlogN))

the code should implement the standard forward Fast Fourier Transform, the form of which can be seen in equation (3) of this Wolfram article,

F[n] = Sum[k=0, N-1, f[k]*exp(-2*pi*i*n*k/N]

Using an FFT function from a pre-existing standard library or statistics package is not allowed. The challenge here is to succinctly implement the FFT algorithm itself.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <time.h>
#include <fftw3.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

void
dft(double complex *x, double complex *y, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		y[i] = 0;
		for (j = 0; j < n; j++)
			y[i] += x[j] * cexp(-2 * M_PI * I * i * j / n);
	}
}

uvlong
ilog2(uvlong n)
{
	uvlong r, p;

	r = 0;
	for (p = 1; p < n; p <<= 1)
		r++;
	return r;
}

uvlong
revb(uvlong v, uvlong b)
{
	uvlong i, r;

	r = 0;
	for (i = 0; i < b; i++)
		r = (r << 1) | ((v >> i) & 1);
	return r;
}

// https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm
void
fft2(double complex *x, double complex *y, size_t n)
{
	double complex w, wm;
	double complex t, u;
	uvlong j, k, m;
	uvlong b, s;
	size_t i;

	b = ilog2(n);
	for (i = 0; i < n; i++)
		y[revb(i, b)] = x[i];

	for (s = 1ULL; s <= b; s++) {
		m = 1ULL << s;
		wm = cexp((-2 * M_PI * I) / m);
		for (k = 0; k < n; k += m) {
			w = 1;
			for (j = 0; j < m / 2; j++) {
				t = w * y[k + j + m / 2];
				u = y[k + j];
				y[k + j] = u + t;
				y[k + j + m / 2] = u - t;
				w *= wm;
			}
		}
	}
}

int
eq(double complex a, double complex b)
{
	static const double eps = 1e-6;

	return (fabs(creal(a) - creal(b)) < eps) &&
	       (fabs(cimag(a) - cimag(b)) < eps);
}

void
test(double complex *x, size_t n)
{
	double complex y1[1024], y2[1024], y3[1024];
	fftw_plan pl;
	size_t i;

	pl = fftw_plan_dft_1d(n, x, y3, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(pl);

	dft(x, y1, n);
	fft2(x, y2, n);
	for (i = 0; i < n; i++) {
		assert(eq(y1[i], y2[i]));
		assert(eq(y2[i], y3[i]));
	}

	fftw_destroy_plan(pl);
}

void
crand(double complex *x, size_t n, double s)
{
	size_t i;

	for (i = 0; i < n; i++)
		x[i] = drand48() * s + (I * drand48() * s);
}

int
main(void)
{
	double complex x1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	double complex x2[] = {3 * I, 4 * I, 5 * I, 1.3};

	double complex x[1024];

	srand48(time(NULL));
	test(x1, nelem(x1));
	test(x2, nelem(x2));

	crand(x, nelem(x), 1e4);
	test(x, nelem(x));

	return 0;
}

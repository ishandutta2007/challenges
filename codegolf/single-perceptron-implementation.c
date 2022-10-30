/*

Challenge
Train a single perceptron with 2 inputs and 1 output.

Step 1: Initialize the weights

Step 2: Calculate the output

For inputs: [i1, i2, ..., in] and weights: [w1, w2, ..., wn] the output is:

i1 * w1 + i2 * w2 + ... + in * wn
Step 3: Apply activation function on the output (i.e sigmoid)

Step 4: Update the weights

w(t + 1) = w(t) + r * (desired_output - actual_output)
Where r: learning rate

Step 5 Repeat steps 2, 3 and 4

Input
iterations: how many times you repeat steps 2, 3 and 4
input: a list with 2 input values i.e. [1, 0]
output: the desired output
learning_rate: the learning rate i.e.0.3

Output
It should print the last calculated output. Keep in mind this should be very close to the desired output i.e 0.96564545 for desired output 1

Example
For input (training for XOR):

1000, [1 0], 1, 0.3
The output should be:

0.9966304251639512
Note The output will never be the same even for identical test cases due to random weights initialization.

Rules
The inputs and outputs of the perceptron are fixed to: 2 and 1 respectively.
The output needs to be close to the desired output (see example).
You can use any activation function you want, just mention it.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

void
randv(double *v, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		v[i] = drand48();
}

double
activate(double *x, double *w, size_t n)
{
	double s;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++)
		s += x[i] * w[i];
	return sigmoid(s);
}

void
adjust(double *w, size_t n, double o)
{
	size_t i;

	for (i = 0; i < n; i++)
		w[i] += o;
}

double
fit(double *x, double y, double *w, size_t n, int e, double r)
{
	double p;
	int i;

	randv(w, n);
	for (i = 0; i < e; i++) {
		p = activate(x, w, n);
		adjust(w, n, r * (y - p));
	}
	return p;
}

void
test(double *x, double y, size_t n, int e, double r)
{
	double w[128];
	double p;

	p = fit(x, y, w, n, e, r);
	printf("%f %f %f\n", p, y, fabs(p - y));
}

int
main(void)
{
	double x1[] = {1, 0};
	double x2[] = {0.4, 0.5};
	double x3[] = {0.2, 0.6};

	srand48(time(NULL));

	test(x1, 1, nelem(x1), 1000, 0.3);
	test(x2, 0.345, nelem(x2), 10000, 0.3);
	test(x3, 0.777, nelem(x3), 10000, 0.6);

	return 0;
}

/*

I'd like to propose a different kind of golfing challenge to this community:

(Artificial) Neural Networks are very popular machine learning models that can be designed and trained to approximate any given (usually unknown) function.
They're often used to solve highly complex problems that we don't know how to solve algorithmically like speech recognition, certain kinds of image classifications,
various tasks in autonomous driving systems, ... For a primer on neural networks, consider this excellent Wikipedia article.

As this is the first in what I hope to be a series of machine learning golf challenges, I'd like to keep things as simple as possible:

In the language and framework of your choice, design and train a neural network that, given (x1,x2)
calculates their product x1⋅x2 for all integers x1,x2 between (and including) −10 and 10.

Performance Goal

To qualify, your model may not deviate by more than 0.5

from the correct result on any of those entries.

Rules

Your model

    must be a 'traditional' neural network (a node's value is calculated as a weighted linear combination of some of the nodes in a previous layer followed by an activation function),
    may only use the following standard activation functions:
                linear
                softmax
                selu(a, b)
                softplus
                leaky-relu
                tanh
                sigmoid
                hard-sigmoid
                exponential
must take (x1,x2)

    either as a tuple/vector/list/... of integers or floats as its only input,
    return the answer as an integer, float (or a suitable container, e.g. a vector or list, that contains this answer).

Your answer must include (or link to) all code necessary to check your results -- including the trained weights of your model.

Scoring

The neural network with the smallest number of weights (including bias weights) wins.

Enjoy!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

/*

@xnor:
Uses the approximate equality for small epsilon in taylor expansion
A*B = (exp(e*A + e*B) - exp(e*A - e*B)) / (2*e*e)

*/

double
nmul(double a, double b)
{
	static const double e = 1e-6;
	double c, d, s, r;

	c = 1.0 / (2 * e * e);

	// 2 weights, exponential activation
	s = exp(e * a + e * b);
	d = exp(e * a - e * b);

	// 3 weights, linear activation
	r = (c * s) + (-c * d) + (-b / e);

	return r;
}

int
main(void)
{
	double a, b;

	for (a = -10; a <= 10; a++) {
		for (b = -10; b <= 10; b++)
			assert(fabs(nmul(a, b) - (a * b)) < 1e-3);
	}
	return 0;
}

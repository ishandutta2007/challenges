/*

It is known that any natural number can be decomposed into the sum of three triangular numbers (assuming 0 is triangular), according to Fermat's Polygonal Number Theorem.
Your task is to come up with an algorithm of decomposing number into 3 triangular numbers that has the best asymptotic complexity.
As an input you are given a number N. Output should contain three numbers, they must be triangular(or 0) and sum of them must be equal to number given in the input.

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
triangular(uvlong n)
{
	return n * (n + 1) / 2;
}

void
decompose(uvlong n, uvlong r[3])
{
	uvlong a, b, c;

	for (a = 0; a <= n; a++) {
		r[0] = triangular(a);
		for (b = 0; b <= n; b++) {
			r[1] = triangular(b);
			for (c = 0; c <= n; c++) {
				r[2] = triangular(c);
				if (r[0] + r[1] + r[2] > n)
					break;

				if (r[0] + r[1] + r[2] == n)
					return;
			}
		}
	}
}

int
main(void)
{
	uvlong i, v[3];

	for (i = 0; i <= 50000; i++) {
		decompose(i, v);
		assert(v[0] + v[1] + v[2] == i);
	}
	return 0;
}

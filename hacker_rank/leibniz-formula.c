/*

In Calculus, the Leibniz formula for π is given by:

Leibniz

or:

Summation

You will be given an integer n. Your task is to print the summation of the Leibniz formula up to the nth term of the series correct to 15 decimal places.

Input Format

The first line contains the number of test cases (T) which is less than 100. Each additional line is a test case for a positive integer value (p) less than 10^7.

Sample Input

2
10
20

Output Format

Output T lines, with each line containing the summation up to nth term.

Summation

Sample Output

0.760459904732351
0.772905951666960

Scoring

This is a code golf question. The goal is to write a solution with as little code as possible. A correct submission with a source code of X characters will receive the following score:

maxScore * (300 - X)/300

Any correct code longer than 300 characters will receive a score of maxScore * 0.001.
MaxScore is the maximum score attainable for the problem.
Note that whitespace is also treated as a character.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
leibniz(unsigned n)
{
	unsigned i;
	double r, s;

	r = 0;
	s = 1;
	for (i = 0; i < n; i++) {
		r += s / (2 * i + 1);
		s = -s;
	}
	return r;
}

void
test(unsigned n, double r)
{
	double p;

	p = leibniz(n);
	printf("%.15f\n", p);
	assert(fabs(p - r) < 1e-15);
}

int
main(void)
{
	test(10, 0.760459904732351);
	test(20, 0.772905951666960);

	return 0;
}

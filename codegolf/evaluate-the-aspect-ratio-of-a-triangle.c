/*

Given three sidelengths of a triangle, evaluate its aspect ratio AR given the following formula:

enter image description here

where

enter image description here

The closer to equilaterality a triangle is, the closer to 1 its aspect ratio is. The aspect ratio is bigger or equal to 1 for valid triangles.
Inputs

The input is three real positive numbers which can be encapsulated in a list or anything similar if need be.

Your program must output the same value no matter what the order in which the three sidelengths are inputted is.

Those three numbers will always be valid sidelengths of a triangle (degenerate triangles like one with sidelengths 1, 1 and 2 will not be given as input). You need not worry about floating point inaccuracies when values become extremely close to a degenerate triangle (e.g. it is acceptable that your program would error division by 0 for input [1, 1, 1.9999999999999999]).

The input can be given through STDIN, as a function argument, or anything similar.
Outputs

The output is a real number bigger or equal to 1 with the standard accuracy that is acceptable in your language.

The output may be printed to STDOUT, returned from a function, or anything similar.
Test cases

Inputs                   Output

  1      1      1         1
  3      4      5         1.25
 42     42   3.14         ≈ 6.9476
 14      6     12         1.575
  6     12     14         1.575
0.5    0.6    0.7         ≈ 1.09375

Scoring

This is code-golf, so the shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
aspect(double a, double b, double c)
{
	double s;

	s = 0.5 * (a + b + c);
	return (a * b * c) / (8 * (s - a) * (s - b) * (s - c));
}

void
test(double a, double b, double c, double r)
{
	double p;

	p = aspect(a, b, c);
	assert(fabs(p - r) < 1e-5);
}

int
main(void)
{
	test(1, 1, 1, 1);
	test(3, 4, 5, 1.25);
	test(42, 42, 3.14, 6.9476);
	test(14, 6, 12, 1.575);
	test(6, 12, 14, 1.575);
	test(0.5, 0.6, 0.7, 1.09375);

	return 0;
}

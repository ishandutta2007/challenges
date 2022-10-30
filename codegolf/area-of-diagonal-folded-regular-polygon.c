/*

I have a piece of paper whose shape is a regular n-gon with side length 1.
Then I fold it through some of its diagonals.
What is the area of the shape formed by the (former) edges of the regular polygon?

Illustration
Suppose n = 8, i.e. an octagon-shaped paper. Let's name the vertices from A to H (left picture).
Then I fold the paper along the two diagonals BE and FH (right picture).
Mathematically, folding BE means to reflect the vertices C and D with respect to the line BE to obtain C' and D'.
Your task is to calculate the area of the shaded octagon on the right picture.

Input
The number of sides n and a list representation of the folds l.
Each element of l represents either a fold or an intact side of the polygon. If it is a fold, its value is the number of sides moved by the fold (e.g. 3 for the BE fold above, 2 for FH).
Otherwise, the value is 1 (e.g. for the sides AB, EF, AH).

For the example above, the input will be 8, [1, 3, 1, 2, 1] if we count from the vertex A, counter-clockwise. If we count clockwise from E instead, the input will be 8, [3, 1, 1, 2, 1]; the expected answer is the same.

Note that sum(l) == n. Also, l == [1] * n (1 repeated n times) case is just the regular polygon untouched, which is a valid input.

The resulting polygon is guaranteed to be simple (it does not intersect or touch itself). For n=3 or n=4, this means that the only valid input is the polygon folded zero times.
For n=6, l=[1, 2, 2, 1] or l=[1, 2, 1, 2] is invalid because the two folds will cause two folded vertices to meet at the center of the hexagon.

Output
The area of the n-sided polygon created by the given folds. The result must be within 1e-6 absolute/relative error from the expected result.

Scoring & winning criterion
Standard code-golf rules apply. Shortest code in bytes wins.

Test cases
n l => answer
---------------
4 [1, 1, 1, 1]    => 1.000000
5 [1, 1, 1, 1, 1] => 1.720477
5 [2, 1, 1, 1]    => 0.769421
6 [1, 2, 1, 1, 1] => 1.732051
7 [1, 2, 1, 2, 1] => 2.070249
8 [1, 3, 1, 2, 1] => 1.707107

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
area(int sides, double *folds, size_t nfolds)
{
	double piece, poly;
	double t, r, h;
	size_t i;

	t = M_PI / sides;
	r = 0.5 / sin(t);
	h = 0.5 / tan(t);
	piece = h / 2;
	poly = piece * sides;
	for (i = 0; i < nfolds; i++)
		poly -= (piece * folds[i] - 0.5 * r * r * sin(2 * folds[i] * t)) * 2;
	return poly;
}

void
test(int sides, double *folds, size_t nfolds, double r)
{
	double a;

	a = area(sides, folds, nfolds);
	printf("%.6f\n", a);
	assert(fabs(a - r) < 1e-6);
}

int
main(void)
{
	double folds1[] = {1, 1, 1, 1};
	double folds2[] = {1, 1, 1, 1, 1};
	double folds3[] = {2, 1, 1, 1};
	double folds4[] = {1, 2, 1, 1, 1};
	double folds5[] = {1, 2, 1, 2, 1};
	double folds6[] = {1, 3, 1, 2, 1};

	test(4, folds1, nelem(folds1), 1.000000);
	test(5, folds2, nelem(folds2), 1.720477);
	test(5, folds3, nelem(folds3), 0.769421);
	test(6, folds4, nelem(folds4), 1.732051);
	test(7, folds5, nelem(folds5), 2.070249);
	test(8, folds6, nelem(folds6), 1.707107);

	return 0;
}

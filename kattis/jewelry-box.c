/*

Vy is obsessed with all the little pieces of jewelry and she has collected so many of them.
During her recent holiday trip, she bought even more items so she needs a new jewelry box now.
She decided that she would make it on her own.

\includegraphics[width=0.4\textwidth ]{box.png}

She bought a paperboard with very cute decoration which is a rectangle of size X×Y.
She will draw a 5-rectangle shape like the image above, cut and fold into a lidless box of size a×b×h.
Having so many items, Vy wants the volume of the box to be as large as possible. Your task is to help Vy calculate the largest volume.

Input

The input starts with the number of test cases T (T≤10000).
Then T test cases follow, each consists of 2 positive integers X, Y printed in a single line (X,Y≤100).

Output

For each test case in the input, print in a single line the largest volume with absolute or relative error less than 10^-6 that Vy can achieve.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
maxvolume(double x, double y)
{
	double h1, h2;
	double v1, v2;
	double s;

	s = sqrt((y * y) - (x * y) + (x * x));
	h1 = (y + x - s) / 6.0;
	h2 = (y + x + s) / 6.0;

	v1 = h1 * (y - 2 * h1) * (x - 2 * h1);
	v2 = 2 * (y - 2 * h2) * (x - 2 * h2);
	return fmax(v1, v2);
}

void
test(double x, double y, double r)
{
	double v;

	v = maxvolume(x, y);
	printf("%.10f\n", v);
	assert(fabs(v - r) < 1e-10);
}

int
main(void)
{
	test(3, 3, 2.00000000000);
	test(2, 4, 1.53960071784);

	return 0;
}

/*

Born in Warsaw, Benoît Mandelbrot (1924–2010) is considered the father of fractal geometry.
He studied mathematical processes that described self-similar and natural shapes known as fractals.
Perhaps his most well-known contribution is the Mandelbrot set, which is pictured below (the set contains the black points):

The Mandelbrot set is typically drawn on the complex plane, a 2-dimensional plane representing all complex numbers.
The horizontal axis represents the real portion of the number, and the vertical axis represents the imaginary portion. A complex number c=x+yi (at position (x,y) on the complex plane) is not in the Mandelbrot set if the following sequence diverges:

z_n+1←z^2_n+c beginning with z0=0. That is, limn→∞|zn|=∞. If the sequence does not diverge, then c is in the set.

Recall the following facts about imaginary numbers and their arithmetic:

i = sqrt(-1)
i^2 = -1
(x + yi)^2 = x^2 - y^2 + 2xyi
|x + yi| = sqrt(x*x + y*y)

where x and y are real numbers, and |⋅| is known as the modulus of a complex number (in the complex plane, the modulus of x+yi is equal to the straight-line distance from the origin to the the point (x,y)).

Write a program which determines if the sequence zn diverges for a given value c within a fixed number of iterations. That is, is c in the Mandelbrot set or not?
To detect divergence, just check to see if |zn|>2 for any zn that we compute – if this happens, the sequence is guaranteed to diverge.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <complex.h>

const char *
diverge(double complex p, int n)
{
	double complex z;
	int i;

	z = 0;
	for (i = 0; i < n; i++) {
		z = z * z + p;
		if (cabs(z) > 2)
			return "OUT";
	}
	return "IN";
}

void
test(double complex p, int n, const char *r)
{
	assert(!strcmp(diverge(p, n), r));
}

int
main(void)
{
	test(0 + 0 * I, 100, "IN");
	test(1.264 - 1.109 * I, 100, "OUT");
	test(1.264 - 1.109 * I, 10, "OUT");
	test(1.264 - 1.109 * I, 1, "IN");
	test(-2.914 - 1.783 * I, 200, "OUT");
	test(0.124 + 0.369 * I, 200, "IN");
	return 0;
}

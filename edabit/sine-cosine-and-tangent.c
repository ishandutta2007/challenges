/*

Create three functions that will do three things:

    Multiply one number by the sine of another number.
    Multiply one number by the COSINE of another number.
    Multiply one number by the tangent of another number.

In each function, you will be given 2 numbers: $x and $y.
Another important thing to note, the numbers will be in degrees, not radians.
That is extremely important. Remember to round the result to 2 decimal places, as well.

Examples

sine(8, 27) ➞ 8 sin 27 ➞ 3.63

cosine(10, 4) ➞ 10 cos 4 ➞ 0.70

tangent(4, 39) ➞ 4 tan 39 ➞ 2.52

Notes

N/A

*/

#define _GNU_SOURCE
#include <assert.h>
#include <math.h>

#define deg2rad(x) (((x)*M_PI) / 180)

double
sine(double x, double y)
{
	return x * sin(deg2rad(y));
}

double
cosine(double x, double y)
{
	return x * cos(deg2rad(y));
}

double
tangent(double x, double y)
{
	return x * tan(deg2rad(y));
}

void
test(double (*f)(double, double), double x, double y, double r)
{
	assert(fabs(f(x, y) - r) < 1e-2);
}

int
main(void)
{
	test(sine, 8, 27, 3.63);
	test(sine, 5, 22, 1.87);
	test(sine, 8, 27, 3.63);
	test(sine, 18, 61, 15.74);
	test(sine, 22, 1, 0.38);
	test(sine, 11, 38, 6.77);

	test(cosine, 10, 4, 9.98);
	test(cosine, 13, 42, 9.66);
	test(cosine, 8, 97, -0.97);
	test(cosine, 38, 71, 12.37);
	test(cosine, 89, 14, 86.36);
	test(cosine, 17, 58, 9.01);

	test(tangent, 4, 39, 3.24);
	test(tangent, 16, 102, -75.27);
	test(tangent, 11, 5, 0.96);
	test(tangent, 21, 42, 18.91);
	test(tangent, 10, 8, 1.41);
	test(tangent, 18, 68, 44.55);

	return 0;
}

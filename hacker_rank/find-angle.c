/*

abc is a right triangle, 90 degree at b
point m is the midpoint of hypotenuse ac
given lengths of ab and bc
find angle mbc in degrees rounded to nearest integer

*/

#include <stdio.h>
#include <math.h>

#define rad2deg(x) ((x)*180 / M_PI)

double
angle1(double ab, double bc)
{
	// make a rectangle with the other side with the same length
	// as ab and bc, we can then calculate the angle using opp/adj = tan(theta)
	return round(rad2deg(atan2(ab, bc)));
}

double
angle2(double ab, double bc)
{
	double ac, num, den, r, d;

	// uses laws of cosine where you calculate the angle of ab
	ac = hypot(ab, bc);
	num = bc * bc + ac * ac - ab * ab;
	den = 2 * bc * ac;
	if (den == 0)
		return NAN;
	return round(rad2deg(acos(num / den)));
}

int
main(void)
{
	int i, j;

	printf("%lf %lf\n", angle1(10, 10), angle2(10, 10));
	printf("%lf %lf\n", angle1(3, 4), angle2(3, 4));
	printf("%lf %lf\n", angle1(5, 12), angle2(5, 12));
	printf("%lf %lf\n", angle1(9, 40), angle2(9, 40));
	printf("%lf %lf\n", angle1(1, 10), angle2(1, 10));
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++)
			printf("%lf %lf\n", angle1(i, j), angle2(i, j));
	}
	return 0;
}

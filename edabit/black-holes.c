/*

A black hole is a region of spacetime where gravity is so strong that nothing⁠ — no particles or even electromagnetic radiation such as light ⁠— can escape from it.

The Schwarzschild radius (sometimes historically referred to as the gravitational radius) is a physical parameter that shows up in the Schwarzschild solution to Einstein's field equations,
corresponding to the radius defining the event horizon of a Schwarzschild black hole.

Objective

Create a function that takes the name and the mass (in solar masses) of a black hole as an argument and returns the Schwarzschild radius, the Schwarzschild density and the type of black hole.

Consider:

c = 299792458
G = 6.67430e-11
pi = 3.141592
sun_mass = 1.99e30

Types of black holes:
Type	Solar Mass
Supermassive black hole	> 1e5
Intermediate-mass black hole	> 1e2 and <= 1e5
Stellar black hole	> 1e-1 and <= 1e2
Micro black hole	<= 1e-1
Examples

black_holes("APM 08279+5255", 2.3e10) ➞

---------- Black Hole APM 08279+5255 ----------

Schwarzschild radius = 6.80e+13 m
Schwarzschild density = 3.48e-02 kg/m3
Type of black hole = Supermassive black hole

black_holes("Messier 87", 7.22e9) ➞

---------- Black Hole Messier 87 ----------

Schwarzschild radius = 2.13e+13 m
Schwarzschild density = 3.53e-01 kg/m3
Type of black hole = Supermassive black hole

black_holes("Messier 110", 1.45e4) ➞

---------- Black Hole Messier 110 ----------

Schwarzschild radius = 4.29e+07 m
Schwarzschild density = 8.75e+10 kg/m3
Type of black hole = Intermediate-mass black hole

Notes

Express the Schwarzschild radius and the Schwarzschild density using scientific notation with two decimal places.

*/

#include <stdio.h>

void
blackholes(const char *s, double m)
{
	static const double c = 299792458;
	static const double G = 6.67430e-11;
	static const double pi = 3.141592;
	static const double sm = 1.99e30;

	const char *t;
	double r, d;

	m *= sm;
	r = (2 * G * m) / (c * c);
	d = (3 * c * c) / (8 * pi * G * r * r);
	if (m > 1e5)
		t = "Supermassive";
	else if (m > 1e2 && m <= 1e5)
		t = "Intermediate-mass";
	else if (m > 1e-1 && m <= 1e2)
		t = "Stellar";
	else
		t = "Micro";

	printf("---------- Black Hole %s ----------\n", s);
	printf("\n");
	printf("Schwarzschild radius = %.2e m\n", r);
	printf("Schwarzschild density = %.2e kg/m^3\n", d);
	printf("Type of black hole = %s black hole\n", t);
	printf("\n");
}

int
main(void)
{
	blackholes("Messier 110", 1.45e4);
	blackholes("APM 08279+5255", 2.3e10);
	blackholes("Messier 87", 7.22e9);
	blackholes("A0620-00", 6.61);
	blackholes("NGC 4889", 2.1e10);

	return 0;
}

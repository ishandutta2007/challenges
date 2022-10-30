/*

Escape velocity is the minimum speed needed for a free, non-propelled object to escape from the gravitational influence of a massive body,
that is, to achieve an infinite distance from it.
Escape velocity is a function of the mass of the body and distance to the center of mass of the body.

Objective

Create a function that takes a planet as an argument and returns its escape velocity expressed in m/s, km/h and km/s.
Data

In the following table you will find for each planet its mass relative to Earth and its radius relative to Earth:
Planet	Mass	Radius
Mercury	0.0558	0.383
Venus	0.815	0.95
Earth	1	1
Mars	0.107	0.532
Jupiter	318	11.2
Saturn	95.1	9.41
Uranus	14.5	4.06
Neptune	17.2	3.88

Consider:

Earth mass = 5.976e24 kg
Earth equatorial radius = 6378 km
Gravitational Constant G = 6.67e-11 Nm²/kg²

Examples

escapeVelocity("Earth") ➞ "The escape velocity in m/s is: 11179.98. The escape velocity in km/h is: 40247.93. The escape velocity in km/s is: 11.18."
escapeVelocity("Venus") ➞ "The escape velocity in m/s is: 10355.19. The escape velocity in km/h is: 37278.68. The escape velocity in km/s is: 10.36."
escapeVelocity("Mars") ➞ "The escape velocity in m/s is: 5013.92. The escape velocity in km/h is: 18050.11. The escape velocity in km/s is: 5.01."

Notes

Round to the nearest hundred the escape velocity in m/s.
Using the rounded escape velocity in m/s calculate the escape velocity in km/h and round that number to the nearest hundred.
Finally, using the rounded escape velocity in m/s, calculate the escape velocity in km/s and round that number to the nearest hundred.

Pay special attention to units.
See part #2 of this series: Escape Velocity II.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
escvel(const char *p, char *b, size_t n)
{
	static const struct {
		const char *name;
		double mass;
		double radius;
	} tab[] = {
	    {"Mercury", 0.0558, 0.383},
	    {"Venus", 0.815, 0.95},
	    {"Earth", 1, 1},
	    {"Mars", 0.107, 0.532},
	    {"Jupiter", 318, 11.2},
	    {"Saturn", 95.1, 9.41},
	    {"Uranus", 14.5, 4.06},
	    {"Neptune", 17.2, 3.88},
	};
	double G, M, R, v, vkh, vks;
	size_t i;

	G = 6.67e-11;
	M = 5.976e24;
	R = 6378e3;
	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(p, tab[i].name)) {
			M *= tab[i].mass;
			R *= tab[i].radius;
			break;
		}
	}

	if (i == nelem(tab))
		snprintf(b, n, "Unknown planet %s\n", p);
	else {
		v = sqrt(2 * G * M / R);
		vkh = round(v * 3.6 * 1e2) / 1e2;
		vks = round(v / 1e3 * 1e2) / 1e2;

		snprintf(b, n, "The escape velocity in m/s is: %.2f. The escape velocity in km/h is: %.2f. The escape velocity in km/s is: %.2f.",
		         v, vkh, vks);
	}

	return b;
}

void
test(const char *p)
{
	char b[128];

	escvel(p, b, sizeof(b));
	printf("%s\n", b);
}

int
main(void)
{
	test("Mercury");
	test("Venus");
	test("Earth");
	test("Mars");
	test("Jupiter");
	test("Saturn");
	test("Uranus");
	test("Neptune");

	return 0;
}

/*

In this challenge, you have to convert a weight weighed on a planet of the Solar System to the corresponding weight on another planet.

To convert the weight, you have to divide it by the gravitational force of the planet on which is weighed and multiply the result (the mass) for the gravitational force of the other planet. See the table below for a list of gravitational forces:

weight on planetA / gravitational force of planetA) * gravitational force of planetB
Planet	m/s²
Mercury	3.7
Venus	8.87
Earth	9.81
Mars	3.711
Jupiter	24.79
Saturn	10.44
Uranus	8.69
Neptune	11.15

Given a weight weighed on planetA, return the converted value for planetB rounded to the nearest hundredth.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
spaceweights(const char *a, double w, const char *b)
{
	static const struct {
		char name[16];
		double gravity;
	} tab[] = {
	    {"Mercury", 3.7},
	    {"Venus", 8.87},
	    {"Earth", 9.81},
	    {"Mars", 3.711},
	    {"Jupiter", 24.79},
	    {"Saturn", 10.44},
	    {"Uranus", 8.69},
	    {"Neptune", 11.15},
	};
	size_t i;
	double ga, gb;

	ga = gb = -1;
	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(a, tab[i].name))
			ga = tab[i].gravity;
		if (!strcmp(b, tab[i].name))
			gb = tab[i].gravity;
		if (ga > 0 && gb > 0)
			return w / ga * gb;
	}
	return -1;
}

int
main(void)
{
	printf("%.2f\n", spaceweights("Earth", 1, "Mars"));
	printf("%.2f\n", spaceweights("Earth", 1, "Jupiter"));
	printf("%.2f\n", spaceweights("Earth", 1, "Neptune"));
	printf("%.2f\n", spaceweights("Jupiter", 100, "Mercury"));
	printf("%.2f\n", spaceweights("Venus", 75, "Jupiter"));
	printf("%.2f\n", spaceweights("Uranus", 10, "Saturn"));
	printf("%.2f\n", spaceweights("Mars", 120, "Mercury"));
	printf("%.2f\n", spaceweights("Neptune", 1421, "Earth"));
	printf("%.2f\n", spaceweights("Jupiter", 33, "Mercury"));
	printf("%.2f\n", spaceweights("Saturn", 555, "Venus"));
	printf("%.2f\n", spaceweights("Jupiter", 3.141592, "Earth"));
	return 0;
}

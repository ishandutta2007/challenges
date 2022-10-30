/*

Wild Roger is tasked with shooting down 6 bottles with 6 shots as fast as possible. Here are the different types of shots he could make:

    He could use one pistol to shoot a bottle with a "Bang!" in 0.5 seconds.
    Or he could use both pistols at once with a "BangBang!" to shoot two bottles in 0.5 seconds.

Given an array of strings, return the time (in seconds) it took to shoot down all 6 bottles. Make sure to only count Bangs and BangBangs. Anything else doesn't count.

Examples

rogerShots(["Bang!", "Bang!", "Bang!", "Bang!", "Bang!", "Bang!"]) ➞ 3

rogerShots(["Bang!", "Bang!", "Bang!", "Bang!", "BangBang!"]) ➞ 2.5

rogerShots(["Bang!", "BangBangBang!", "Boom!", "Bang!", "BangBang!", "BangBang!"]) ➞ 2

Notes

All the bottles will be shot down in all the tests.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
shots(const char **s, size_t n)
{
	size_t i;
	double r;
	int v;

	r = 0;
	v = 6;
	for (i = 0; i < n && v > 0; i++) {
		if (!strcmp(s[i], "Bang!"))
			v -= 1;
		else if (!strcmp(s[i], "BangBang!"))
			v -= 2;
		else
			continue;

		r += 0.5;
	}
	return r;
}

void
test(const char **s, size_t n, double r)
{
	double v;

	v = shots(s, n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-8);
}

int
main(void)
{
	const char *s1[] = {"Bang!", "Bang!", "Bang!", "Bang!", "Bang!", "Bang!"};
	const char *s2[] = {"Bang!", "Bang!", "Bang!", "Bang!", "BangBang!"};
	const char *s3[] = {"Bang!", "BangBangBang!", "Boom!", "Bang!", "BangBang!", "BangBang!"};
	const char *s4[] = {"BangBang!", "BangBang!", "BangBang!"};
	const char *s5[] = {"Bang!", "BadaBing!", "Badaboom!", "Bang!", "Bang!", "Bang!", "Bang!", "Bang!"};
	const char *s6[] = {"BangBang!", "BangBang!", "Bag!", "Ban!", "Tang!", "Bang!", "Bang!"};

	test(s1, nelem(s1), 3);
	test(s2, nelem(s2), 2.5);
	test(s3, nelem(s3), 2);
	test(s4, nelem(s4), 1.5);
	test(s5, nelem(s5), 3);
	test(s6, nelem(s6), 2);

	return 0;
}

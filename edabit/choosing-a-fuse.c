/*

A fuse melts when a current in an electrical device exceeds the fuse's rating, breaking the circuit and preventing the heat from building up too much (which can cause a fire).
The ideal fuse to choose is higher than the device's current output, yet as close as possible to it as well.

Given an array of fuse ratings, and the device's current output, return which of the fuses is the best for the device.

Examples

chooseFuse(["3V", "5V", "12V"], "4.5V") ➞ "5V"

chooseFuse(["5V", "14V", "2V"], "5.5V") ➞ "14V"

chooseFuse(["17V", "15V", "12V"], "9V") ➞ "12V"

Notes

    You will be given three possible ratings in voltage.
    Fuses may not be in a sorted order.
    Assume that there is a valid fuse in every test case

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
fuse(const char **s, size_t n, const char *t)
{
	const char *p;
	double u, v, w;
	size_t i;

	u = atof(t);
	w = 0;
	p = NULL;
	for (i = 0; i < n; i++) {
		v = atof(s[i]);
		if (v >= u && (w == 0 || v - u < w)) {
			p = s[i];
			w = v - u;
		}
	}
	return p;
}

void
test(const char **s, size_t n, const char *t, const char *r)
{
	const char *p;

	p = fuse(s, n, t);
	assert(p);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	const char *s1[] = {
	    "3V",
	    "5V",
	    "12V",
	};
	const char *s2[] = {
	    "5V",
	    "14V",
	    "2V",
	};
	const char *s3[] = {
	    "17V",
	    "15V",
	    "12V",
	};
	const char *s4[] = {
	    "1V",
	    "2V",
	    "3V",
	};
	const char *s5[] = {
	    "17V",
	    "15V",
	    "12V",
	};
	const char *s6[] = {
	    "7V",
	    "135V",
	    "12V",
	};
	const char *s7[] = {
	    "17V",
	    "15V",
	    "12V",
	};
	const char *s8[] = {
	    "3V",
	    "11V",
	    "12V",
	};
	const char *s9[] = {
	    "3V",
	    "5V",
	    "12V",
	};

	test(s1, nelem(s1), "4.5V", "5V");
	test(s2, nelem(s2), "5.5V", "14V");
	test(s3, nelem(s3), "9V", "12V");
	test(s4, nelem(s4), "2.5V", "3V");
	test(s5, nelem(s5), "1V", "12V");
	test(s6, nelem(s6), "9.5V", "12V");
	test(s7, nelem(s7), "17V", "17V");
	test(s8, nelem(s8), "4.5V", "11V");
	test(s9, nelem(s9), "0.5V", "3V");

	return 0;
}

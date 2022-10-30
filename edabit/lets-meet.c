/*

From point A, an object is moving towards point B at constant velocity va (in km/hr).
From point B, another object is moving towards point A at constant velocity vb (in km/hr).
Knowing this and the distance between point A and B (in km), write a function that returns how much time passes until both objects meet.

Format the output like this:

"2h 23min 34s"

Examples

letsMeet(100, 10, 30) ➞ "2h 30min 0s"

letsMeet(280, 70, 80) ➞ "1h 52min 0s"

letsMeet(90, 75, 65) ➞ "0h 38min 34s"

Notes

Seconds should be rounded down to the nearest whole number.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
meet(double d, double va, double vb, char *b, size_t n)
{
	double v, h, m, s;

	v = va + vb;
	if (v == 0)
		return NULL;

	h = d / v;
	m = fmod(h, 1.0) * 60;
	s = fmod(m, 1.0) * 60;

	snprintf(b, n, "%ldh %ldmin %lds", (long)h, (long)m, (long)s);
	return b;
}

void
test(double va, double vb, double d, const char *r)
{
	char b[128];

	assert(meet(va, vb, d, b, sizeof(b)));
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(100, 10, 30, "2h 30min 0s");
	test(33, 15, 20, "0h 56min 34s");
	test(250, 60, 80, "1h 47min 8s");
	test(125, 55, 40, "1h 18min 56s");
	test(0.6, 10, 15, "0h 1min 26s");
	test(0.8, 23, 18, "0h 1min 10s");
	test(0.72, 8, 12, "0h 2min 9s");
	test(33, 15, 20, "0h 56min 34s");
	test(360, 80, 64, "2h 30min 0s");
	test(10, 45, 42, "0h 6min 53s");
	test(90, 75, 65, "0h 38min 34s");
	test(280, 70, 80, "1h 52min 0s");

	return 0;
}

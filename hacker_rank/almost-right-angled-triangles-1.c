/*

Barely acute triangles are triangles with the sides of the form

a^2 + b^2 = c^1 - 1

Find all barely acute triangles with perimeter up to N

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long ulong;

ulong
acutes(ulong n)
{
	ulong a, b, c, d, r;

	r = 0;
	for (a = 1; a <= n; a++) {
		for (b = a; b <= n; b++) {
			d = a * a + b * b - 1;
			c = sqrt(d);
			if (a + b + c > n)
				break;
			if (c * c == d)
				r++;
		}
	}
	return r;
}

int
main(void)
{
	assert(acutes(21) == 12);
	return 0;
}

/*

The following picture shows the problem:

enter image description here

Write a function that, given an integer as the circle radius, calculates the number of lattice points inside the centered circle (including the boundary).

The image shows:

f[1] = 5  (blue points)
f[2] = 13 (blue + red points)  

other values for your checking/debugging:

f[3]    = 29
f[10]   = 317
f[1000] = 3,141,549
f[2000] = 12,566,345  

Should have a reasonable performance. Let's say less than a minute for f[1000].

Shortest code wins. Usual Code-Golf rules apply.

Please post the calculation and timing of f[1001] as an example.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
lattices(uvlong n)
{
	uvlong r, a, x, y;

	for (a = r = n * n; a--;) {
		x = a % (n + 1);
		y = a / n;
		if ((x * x + y * y) > (n * n))
			r--;
	}
	return 4 * r + 1;
}

int
main(void)
{
	assert(lattices(1) == 5);
	assert(lattices(2) == 13);
	assert(lattices(3) == 29);
	assert(lattices(10) == 317);
	assert(lattices(1000) == 3141549ull);
	assert(lattices(1001) == 3147833ull);
	assert(lattices(2000) == 12566345ull);

	return 0;
}

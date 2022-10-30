/*

Find the smallest x + y + z with integers x > y > z > 0 such that x + y, x − y, x + z, x − z, y + z, y − z are all perfect squares.

*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

int
square(long n)
{
	long x;

	x = sqrt(n);
	return x * x == n;
}

// https://www.mathblog.dk/project-euler-142-perfect-square-collection/
long
solve(long *x, long *y, long *z)
{
	long a, b, c, d, e, f;
	long i, j, k;

	for (i = 4; i < LONG_MAX; i++) {
		a = i * i;
		for (j = 3; j < i; j++) {
			c = j * j;
			f = a - c;
			if (f <= 0 || !square(f))
				continue;

			for (k = 2 - (j & 1); k < j; k += 2) {
				d = k * k;
				e = a - d;
				b = c - e;
				if (b <= 0 || e <= 0 || !square(b) || !square(e))
					continue;

				*x = (d + c) / 2;
				*y = (e + f) / 2;
				*z = (c - d) / 2;
				return *x + *y + *z;
			}
		}
	}
	return -1;
}

int
main(void)
{
	long x, y, z, r;

	r = solve(&x, &y, &z);

	printf("x=%ld y=%ld z=%ld\n", x, y, z);
	printf("x+y+z=%ld\n", r);

	return 0;
}

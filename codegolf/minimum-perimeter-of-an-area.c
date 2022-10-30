/*

Just a simple code golf function for fun, intentionally left open with few rules to see what creativity comes up.

Input: An integer representing the area of a rectangle.

Output: Two integers representing the side lengths of the rectangle that have the least perimeter for the area. (In any order.)

Test cases:

25 => 5, 5
53 => 53, 1
4294967295 => 65537, 65535

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

void
swap(uvlong *x, uvlong *y)
{
	uvlong t;

	t = *y;
	*y = *x;
	*x = t;
}

void
perimeter(uvlong a, uvlong r[2])
{
	uvlong i, w, h;

	r[0] = r[1] = 0;
	if (a == 0)
		return;

	for (i = sqrt(a); i % a; i--) {
		w = i;
		h = a / i;
		if (w * h != a)
			continue;

		if (r[0] == 0 || (w + h) < (r[0] + r[1])) {
			r[0] = w;
			r[1] = h;
		}
	}

	if (r[0] < r[1])
		swap(&r[0], &r[1]);
}

void
test(uvlong a, uvlong x, uvlong y)
{
	uvlong p[2];

	perimeter(a, p);
	printf("%llu %llu\n", p[0], p[1]);

	if (x < y)
		swap(&x, &y);
	assert(x == p[0] && y == p[1]);
}

int
main(void)
{
	test(25, 5, 5);
	test(53, 53, 1);
	test(4294967295ull, 65537ull, 65535ull);

	return 0;
}

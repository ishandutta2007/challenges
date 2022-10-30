/*

A ship has to transport cargo from one place to another, while picking up cargo along the way.
Given the total amount of cargo and the types of cargo holds in the ship as arrays,
create a function that returns true if all the cargo can fit on the ship, and false if it can't.

    "S" means 50 cargo space.
    "M" means 100 cargo space.
    "L" means 200 cargo space.

Examples

willFit(["M", "L", "L", "M"], [56, 62, 84, 90]) ➞ true

willFit(["S", "S", "S", "S", "L"], [40, 50, 60, 70 , 80, 90, 200]) ➞ false

willFit(["L", "L", "M"], [56, 62, 84, 90]) ➞ true

Notes

Calculate the cargo as a whole, and not for each seperate cargo hold (see example #2).

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
willfit(const char **s, size_t n, unsigned *c, size_t m)
{
	unsigned x, y;
	size_t i;

	x = y = 0;
	for (i = 0; i < n; i++) {
		switch (s[i][0]) {
		case 'S':
			x += 50;
			break;
		case 'M':
			x += 100;
			break;
		case 'L':
			x += 200;
			break;
		default:
			assert(0);
		}
	}

	for (i = 0; i < m; i++)
		y += c[i];

	return x >= y;
}

int
main(void)
{
	const char *s1[] = { "M", "L", "L", "M" };
	const char *s2[] = { "S", "S", "S", "S", "L" };
	const char *s3[] = { "L", "L", "M" };
	const char *s4[] = { "S", "L" };

	unsigned c1[] = { 56, 62, 84, 99 };
	unsigned c2[] = { 40, 50, 60, 70, 80, 90, 200 };
	unsigned c3[] = { 56, 62, 84, 90 };
	unsigned c4[] = { 73, 87, 95, 229 };

	assert(willfit(s1, nelem(s1), c1, nelem(c1)) == true);
	assert(willfit(s2, nelem(s2), c2, nelem(c2)) == false);
	assert(willfit(s3, nelem(s3), c3, nelem(c3)) == true);
	assert(willfit(s4, nelem(s4), c4, nelem(c4)) == false);

	return 0;
}

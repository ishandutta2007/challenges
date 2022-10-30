/*

Input

4 integers w, x, y, z from the range -999 to 999 inclusive where none of the values is 0.

Output

4 integers a, b, c, d so that aw + bx + cy + dz == 0 where none of the values is 0.

Restrictions

Your output should be the solution with the smallest sum of absolute values possible. That is the smallest value of |a|+|b|+|c|+|d|.
If there is more than one solution with the same sum of absolute values you can choose any one of them arbitrarily.

Examples

Input: 78 -75 24 33
Output: b = -1, d = 1, a = -2, c = 2

Input: 84 62 -52 -52
Output: a = -1, d = -1, b = -2, c = -3

Input: 26 45 -86 -4
Output: a = -3, b = -2, c = -2, d = 1

Input: 894 231 728 -106
Output: a = 3, b = -8, c = -1, d = 1

Input: -170 962 863 -803
Output: a = -5, d = 8, c = 2, b = 4

Added thanks to @Arnauld
Input: 3 14 62 74
Output: -2, 4, -2, 1

Unassessed bonus

Not in the challenge but does your code also work on this?

Input:  9923 -9187 9011 -9973

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
solve(int w, int x, int y, int z, int lo, int hi, int r[4])
{
	int a, b, c, d;
	int m, v;

	m = 0;
	for (a = lo; a <= hi; a++) {
		for (b = lo; b <= hi; b++) {
			for (c = lo; c <= hi; c++) {
				for (d = lo; d <= hi; d++) {
					if (a == 0 || b == 0 || c == 0 || d == 0)
						continue;

					if (a * w + b * x + c * y + d * z != 0)
						continue;

					v = abs(a) + abs(b) + abs(c) + abs(d);
					if (m == 0 || v < m) {
						m = v;
						r[0] = a;
						r[1] = b;
						r[2] = c;
						r[3] = d;
					}
				}
			}
		}
	}
	return m;
}

void
test(int w, int x, int y, int z, int lo, int hi)
{
	int r[4];

	assert(solve(w, x, y, z, lo, hi, r) > 0);
	printf("%d %d %d %d\n", r[0], r[1], r[2], r[3]);
}

int
main(void)
{
	int lo, hi;

	lo = -20;
	hi = 20;
	test(78, -75, 24, 33, lo, hi);
	test(84, 62, -52, 52, lo, hi);
	test(26, 45, -86, -4, lo, hi);
	test(894, 231, 728, -106, lo, hi);
	test(-170, 962, 863, -803, lo, hi);
	test(3, 14, 62, 74, lo, hi);
	test(9923, -9187, 9011, -9973, lo, hi);

	return 0;
}

/*

Given a list of directions to spin, "left" or "right", return an integer of how many full 360° rotations were made.
Note that each word in the array counts as a 90° rotation in that direction.

Examples

spinAround(["right", "right", "right", "right", "left", "right"]) ➞ 1
# You spun right 4 times (90 * 4 = 360)
# You spun left once (360 - 90 = 270)
# But you spun right once more to make a full rotation (270 + 90 = 360)

spinAround(["left", "right", "left", "right"]) ➞ 0

spinAround(["right", "right", "right", "right", "right", "right", "right", "right"]) ➞ 2

spinAround(["left", "left", "left", "left"]) ➞ 1

Notes

    Return a positive number.
    All tests will only include the words "right" and "left".

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// count rotations only in one direction, ie,
// right 4, left 4 will be 0 rotations rather than 2 rotations
unsigned
spin(const char **s, size_t n)
{
	size_t i;
	int p;

	p = 0;
	for (i = 0; i < n; i++) {
		if (!strcmp(s[i], "left"))
			p--;
		else if (!strcmp(s[i], "right"))
			p++;
	}
	return abs(p / 4);
}

void
test(const char **s, size_t n, unsigned r)
{
	assert(spin(s, n) == r);
}

int
main(void)
{
	const char *s1[] = {
	    "left",
	    "right",
	    "left",
	    "right",
	};
	const char *s2[] = {
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	};
	const char *s3[] = {
	    "left",
	    "left",
	    "left",
	    "left",
	};
	const char *s4[] = {"left"};
	const char *s5[] = {"right"};
	const char *s6[] = {
	    "right",
	    "right",
	    "right",
	    "left",
	    "right",
	    "right",
	};
	const char *s7[] = {
	    "left",
	    "left",
	    "right",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "right",
	    "left",
	    "left",
	    "right",
	    "right",
	    "right",
	    "right",
	    "left",
	    "left",
	    "right",
	    "right",
	};
	const char *s8[] = {
	    "right",
	    "left",
	    "left",
	    "right",
	    "left",
	    "left",
	    "right",
	    "left",
	    "right",
	    "right",
	    "left",
	    "left",
	    "right",
	    "right",
	    "right",
	    "left",
	    "left",
	    "right",
	};
	const char *s9[] = {
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	    "right",
	};
	const char *s10[] = {
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	    "left",
	};

	test(s1, nelem(s1), 0);
	test(s2, nelem(s2), 2);
	test(s3, nelem(s3), 1);
	test(NULL, 0, 0);
	test(s4, nelem(s4), 0);
	test(s5, nelem(s5), 0);
	test(s6, nelem(s6), 1);
	test(s7, nelem(s7), 1);
	test(s8, nelem(s8), 0);
	test(s9, nelem(s9), 10);
	test(s10, nelem(s10), 10);

	return 0;
}

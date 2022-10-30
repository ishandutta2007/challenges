/*

Given a number n, find if its 2nd, 4th and 8th roots are all integers (perfect roots), return True if it exists, False if not.
Examples

perfect_roots(256) ➞ True
# 2nd root of 256 is 16
# 4th root of 256 is 4
# 8th root of 256 is 2

perfect_roots(1000) ➞ False

perfect_roots(6561) ➞ True

Notes

n > 1


*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool
perfectroots(unsigned long n)
{
	unsigned long v;
	int i;

	for (i = 0; i < 3; i++) {
		v = sqrt(n);
		if (v * v != n)
			return false;
		n = v;
	}
	return true;
}

int
main(void)
{
	assert(perfectroots(256) == true);
	assert(perfectroots(1000) == false);
	assert(perfectroots(6561) == true);
	assert(perfectroots(12534) == false);
	assert(perfectroots(3455) == false);
	assert(perfectroots(65536ul) == true);
	assert(perfectroots(390625ul) == true);
	assert(perfectroots(1679616ul) == true);
	assert(perfectroots(6534561ul) == false);
	assert(perfectroots(253456ul) == false);
	assert(perfectroots(5764801ul) == true);
	assert(perfectroots(100000000ul) == true);

	return 0;
}

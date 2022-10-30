/*

Create a function that takes an integer and returns an array from 1 to the given number, where:

    If the number can be divided evenly by 4, amplify it by 10 (i.e. return 10 times the number).
    If the number cannot be divided evenly by 4, simply return the number.

Examples

amplify(4) ➞ [1, 2, 3, 40]

amplify(3) ➞ [1, 2, 3]

amplify(25) ➞ [1, 2, 3, 40, 5, 6, 7, 80, 9, 10, 11, 120, 13, 14, 15, 160, 17, 18, 19, 200, 21, 22, 23, 240, 25]

Notes

    The given integer will always be equal to or greater than 1.
    Include the number (see example above).

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned *
amplify(unsigned n)
{
	unsigned i, *p;

	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	for (i = 1; i <= n; i++)
		p[i - 1] = !(i & 3) ? i * 10 : i;
	return p;
}

void
test(unsigned n, unsigned *r)
{
	unsigned *p;

	p = amplify(n);
	assert(p);
	assert(!memcmp(p, r, sizeof(*r) * n));
	free(p);
}

int
main(void)
{
	test(1, (unsigned[]){1});
	test(4, (unsigned[]){1, 2, 3, 40});
	test(8, (unsigned[]){1, 2, 3, 40, 5, 6, 7, 80});
	test(25, (unsigned[]){1, 2, 3, 40, 5, 6, 7, 80, 9, 10, 11, 120, 13, 14, 15, 160, 17, 18, 19, 200, 21, 22, 23, 240, 25});

	return 0;
}

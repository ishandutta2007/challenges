/*

Write a function that takes an integer n and turns it into the ouput. No further instructions.

Notes

    The result has to do with counting something.
    Check the Tests tab for some extra hints.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

uintmax_t
mystery(uintmax_t x)
{
	char b[sizeof(x) * CHAR_BIT * CHAR_BIT];
	char p[sizeof(b)];
	size_t i, j, k;

	snprintf(b, sizeof(b), "%ju", x);
	for (i = k = 0; b[i]; i += j) {
		j = 1;
		while (b[i] == b[i + j])
			j++;
		k += sprintf(p + k, "%zu%c", j, b[i]);
	}
	return strtoumax(p, NULL, 10);
}

int
main(void)
{
	assert(mystery(UINTMAX_C(521)) == UINTMAX_C(151211));
	assert(mystery(UINTMAX_C(5211255)) == UINTMAX_C(1512211225));
	assert(mystery(UINTMAX_C(513515)) == UINTMAX_C(151113151115));
	assert(mystery(UINTMAX_C(15)) == UINTMAX_C(1115));
	assert(mystery(UINTMAX_C(15212)) == UINTMAX_C(1115121112));
	assert(mystery(UINTMAX_C(111111422)) == UINTMAX_C(611422));
	assert(mystery(UINTMAX_C(1)) == UINTMAX_C(11));
	assert(mystery(UINTMAX_C(513515)) == UINTMAX_C(151113151115));
	assert(mystery(UINTMAX_C(666)) == UINTMAX_C(36));
	assert(mystery(UINTMAX_C(69)) == UINTMAX_C(1619));

	return 0;
}

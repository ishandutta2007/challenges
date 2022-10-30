/*

Create a function that returns the number of hashes and pluses in a string.
Examples

hashPlusCount("###+") ➞ [3, 1]

hashPlusCount("##+++#") ➞ [3, 3]

hashPlusCount("#+++#+#++#") ➞ [4, 6]

hashPlusCount("") ➞ [0, 0]

Notes

    Return [0, 0] for an empty string.
    Return in the order of [hashes, pluses].

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t *
hashpluscount(const char *s, size_t r[2])
{
	size_t i;

	r[0] = r[1] = 0;
	for (i = 0; s[i]; i++) {
		r[0] += (s[i] == '#');
		r[1] += (s[i] == '+');
	}
	return r;
}

int
main(void)
{
	size_t r[2];

	size_t r1[] = { 4, 0 };
	size_t r2[] = { 1, 0 };
	size_t r3[] = { 0, 7 };
	size_t r4[] = { 0, 2 };
	size_t r5[] = { 2, 2 };
	size_t r6[] = { 3, 1 };
	size_t r7[] = { 3, 3 };
	size_t r8[] = { 4, 6 };
	size_t r9[] = { 0, 0 };

	assert(memcmp(hashpluscount("####", r), r1, sizeof(r1)) == 0);
	assert(memcmp(hashpluscount("#", r), r2, sizeof(r2)) == 0);
	assert(memcmp(hashpluscount("+++++++", r), r3, sizeof(r3)) == 0);
	assert(memcmp(hashpluscount("++", r), r4, sizeof(r4)) == 0);
	assert(memcmp(hashpluscount("#+#+", r), r5, sizeof(r5)) == 0);
	assert(memcmp(hashpluscount("###+", r), r6, sizeof(r6)) == 0);
	assert(memcmp(hashpluscount("##+++#", r), r7, sizeof(r7)) == 0);
	assert(memcmp(hashpluscount("#+++#+#++#", r), r8, sizeof(r8)) == 0);
	assert(memcmp(hashpluscount("", r), r9, sizeof(r9)) == 0);

	return 0;
}

/*

Write a function that returns true if you can use the letters of the first string to create the second string. Letters are case sensitive.
Examples

canBuild("aPPleAL", "PAL") ➞ true

canBuild("aPPleAL", "apple") ➞ false

canBuild("shortCAKE", "cakey") ➞ false

canBuild("a", "") ➞ true

Notes

N/A

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
canbuild(const char *s, const char *t)
{
	size_t i, h[256];

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;

	for (i = 0; t[i]; i++) {
		if (h[t[i] & 0xff] == 0)
			return false;
		h[t[i] & 0xff]--;
	}
	return true;
}

int
main(void)
{
	assert(canbuild("aPPleAL", "PAL") == true);
	assert(canbuild("aPPleAL", "apple") == false);
	assert(canbuild("shortCAKE", "cakey") == false);
	assert(canbuild("a", "") == true);
	assert(canbuild("OAT", "OAT") == true);
	assert(canbuild("maybelLINE", "maybe") == true);
	assert(canbuild("topsh", "shop") == true);
	assert(canbuild("topshSHP", "SHoP") == true);
	assert(canbuild("DAISIES", "SAID") == true);
	assert(canbuild("ToporP", "porT") == true);
	assert(canbuild("PoTluCK", "PuCK") == true);
	assert(canbuild("pATS", "p") == true);
	assert(canbuild("blah", "") == true);
	assert(canbuild("maybeLINE", "lINE") == false);
	assert(canbuild("teaPOT", "lINE") == false);
	assert(canbuild("", "a") == false);
	assert(canbuild("a", "A") == false);
	assert(canbuild("AAAAAA", "AAAAAAa") == false);
	assert(canbuild("apple", "appleY") == false);
	assert(canbuild("xxYYzZ", "zzZxYxY") == false);
	assert(canbuild("abCD", "aBCD") == false);

	return 0;
}

/*

Given two words, the letter distance is calculated by taking the absolute value of the difference in character codes and summing up the difference.

If one word is longer than another, add the difference in lengths towards the score.

To illustrate:

letterDistance("house", "fly") = dist("h", "f") + dist("o", "l") + dist("u", "y") + dist(house.length, fly.length)

= |104 - 102| + |111 - 108| + |117 - 121| + |5 - 3|
= 2 + 3 + 4 + 2
= 11

Examples

letterDistance("sharp", "sharq") ➞ 1

letterDistance("abcde", "Abcde") ➞ 32

letterDistance("abcde", "bcdef") ➞ 5

Notes

    Always start comparing the two strings from their first letter.
    Excess letters are not counted towards distance.
    Capital letters are included.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

uintmax_t
letterdistance(const char *s, const char *t)
{
	ssize_t i, j;
	uintmax_t r;

	r = 0;
	for (i = j = 0; s[i] || t[j];) {
		if (s[i] && t[j])
			r += imaxabs(s[i] - t[j]);
		if (s[i])
			i++;
		if (t[j])
			j++;
	}
	r += imaxabs(i - j);
	return r;
}

int
main(void)
{
	assert(letterdistance("house", "fly") == 11);
	assert(letterdistance("sharp", "sharq") == 1);
	assert(letterdistance("abcde", "bcdef") == 5);
	assert(letterdistance("abcde", "a") == 4);
	assert(letterdistance("abcde", "e") == 8);
	assert(letterdistance("very", "fragile") == 67);
	assert(letterdistance("abcde", "Abcde") == 32);
	assert(letterdistance("abcde", "A") == 36);

	return 0;
}

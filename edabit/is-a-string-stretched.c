/*

Write a function that returns true if the first string is the second string stretched, and false otherwise.
A stretch is to repeat each character in a string the same number of times.

Examples

isStretched("pppaaannndddaaa", "panda") ➞ true

isStretched("sssshhiipp", "ship") ➞ false

isStretched("magnet", "magnet") ➞ true

isStretched("magneto", "magnet") ➞ false

Notes

    Both strings must contain the same letters in order for the stretch to be valid.
    All strings will be in lower case letters.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
stretched(const char *s, const char *t)
{
	size_t i, j, k, l, m;

	for (i = k = m = 0; t[i]; i = j) {
		j = i + 1;
		while (t[i] == t[j])
			j++;

		for (l = 0; s[k] == t[i]; k++)
			l++;

		if (l == 0 || l % (j - i))
			return false;

		l /= (j - i);
		if (m && m != l)
			return false;
		m = l;
	}
	if (s[k])
		return false;

	return true;
}

int
main(void)
{
	assert(stretched("pppaaannndddaaa", "panda") == true);
	assert(stretched("hheelllloo", "hello") == true);
	assert(stretched("magnet", "magnet") == true);
	assert(stretched("eeeeemmmmmoooootttttiiiiiooooonnnnn", "emotion") == true);
	assert(stretched("sssshhiipp", "ship") == false);
	assert(stretched("cccaaannnddooorrr", "candor") == false);
	assert(stretched("relationshiipp", "relationship") == false);
	assert(stretched("magneto", "magnet") == false);
	assert(stretched("maggnet", "magnet") == false);
	assert(stretched("", "") == true);
	assert(stretched("aaa", "aa") == false);
	assert(stretched("aaa", "a") == true);
	assert(stretched("aaabbb", "ab") == true);

	return 0;
}

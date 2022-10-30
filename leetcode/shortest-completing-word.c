/*

Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate.
Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times.
For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does. 



Note:

licensePlate will be a string with length in range [1, 7].
licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
words will have a length in the range [10, 1000].
Every words[i] will consist of lowercase letters, and have length in range [1, 15].

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
shcw(const char *l, const char **w, size_t n)
{
	size_t h1[256], h2[256];
	size_t i, j, k, l1, l2;

	memset(h1, 0, sizeof(h1));
	for (i = 0; l[i]; i++) {
		if (isalpha(l[i]))
			h1[tolower(l[i]) & 0xff]++;
	}

	k = SIZE_MAX;
	l2 = SIZE_MAX;
	for (i = 0; i < n; i++) {
		memset(h2, 0, sizeof(h2));
		for (j = 0; w[i][j]; j++)
			h2[tolower(w[i][j]) & 0xff]++;

		l1 = j;
		if (l1 >= l2)
			continue;

		for (j = 0; j < nelem(h2); j++)
			h2[j] &= h1[j];

		if (memcmp(h1, h2, sizeof(h1)) == 0) {
			l2 = l1;
			k = i;
		}
	}

	if (k == SIZE_MAX)
		return "";
	return w[k];
}

int
main(void)
{
	const char *s1[] = {"step", "steps", "stripe", "stepple"};
	const char *s2[] = {"looks", "pest", "stew", "show"};
	const char *s3[] = {"pair", "supper"};

	printf("%s\n", shcw("1s3 PSt", s1, nelem(s1)));
	printf("%s\n", shcw("1s3 456", s2, nelem(s2)));
	printf("%s\n", shcw("1Z3 456", s2, nelem(s2)));
	printf("%s\n", shcw("130", s2, nelem(s2)));
	printf("%s\n", shcw("130", s2, nelem(s2)));
	printf("%s\n", shcw("20304 PP", s3, nelem(s3)));

	return 0;
}

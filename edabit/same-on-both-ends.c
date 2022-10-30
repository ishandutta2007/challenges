/*

Given a sentence, return the number of words which have the same first and last letter.

Examples

countSameEnds("Pop! goes the balloon") ➞ 1

countSameEnds("And the crowd goes wild!") ➞ 0

countSameEnds("No I am not in a gang.") ➞ 1

Notes

    Don't count single character words (such as "I" and "A" in example #3).
    The function should not be case sensitive, meaning a capital "P" should match with a lowercase one.
    Mind the punctuation!
    Bonus points indeed for using regex!

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

size_t
sameends(const char *s)
{
	size_t i, j, k, r;

	for (i = r = 0; s[i];) {
		while (s[i] && !isalpha(s[i]))
			i++;

		j = k = i;
		while (s[i] && !isspace(s[i])) {
			if (isalpha(s[i]))
				k = i;
			i++;
		}

		if (j == k || !isalpha(s[j]) || !isalpha(s[k]))
			continue;

		r += (tolower(s[j]) == tolower(s[k]));
	}
	return r;
}

int
main(void)
{
	assert(sameends("Pop! the balloon!") == 1);
	assert(sameends("My mom is not a nun.") == 2);
	assert(sameends("A fine morning") == 0);
	assert(sameends("And the crowd goes wild!") == 0);
	assert(sameends("No I am not in a gang.") == 1);
	assert(sameends("Taste the difference") == 0);

	return 0;
}

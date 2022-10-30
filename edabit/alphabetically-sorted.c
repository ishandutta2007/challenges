/*

A word is alphabetically sorted if all of the letters in it are in consecutive alphabetical order.
Some examples of alphabetically sorted words: abhors (a is before b, b is before h, h is before o, etc.), ghost, accent, hoop.

Create a function that takes in a sentence as input and returns true if there is at least one alphabetically sorted word inside that has a minimum length of 3.
Examples

isAlphabeticallySorted("Paula has a French accent.") ➞ true
// "accent" is alphabetically sorted.

isAlphabeticallySorted("The biopsy returned negative results.") ➞ true
// "biopsy" is alphabetically sorted.

isAlphabeticallySorted("She sells sea shells by the sea shore.") ➞ false
// Although "by" is alphabetically sorted, it is only 2 letters long.

Notes

    Do not count words with 2 or fewer characters.
    Ignore punctuation (periods, commas, etc).

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
issorted(const char *s, size_t i, size_t j)
{
	size_t k;

	for (;;) {
		while (i < j && ispunct(s[i]))
			i++;

		k = i + 1;
		while (k < j && ispunct(s[k]))
			k++;

		if (i >= j || k >= j)
			break;

		if (tolower(s[i]) > tolower(s[k]))
			return 0;

		i = k;
	}

	return 1;
}

int
alphasorted(const char *s)
{
	size_t i, j;

	i = 0;
	for (;;) {
		while (isspace(s[i]))
			i++;

		if (s[i] == '\0')
			break;

		j = i + 1;
		while (!isspace(s[j]) && s[j] != '\0')
			j++;

		if (j - i >= 3 && issorted(s, i, j))
			return 1;
		i = j;
	}

	return 0;
}

int
main(void)
{
	assert(alphasorted("Paula has a French accent.") == 1);
	assert(alphasorted("The biopsy returned negative results.") == 1);
	assert(alphasorted("She sells sea shells by the sea shore.") == 0);
	assert(alphasorted("She almost reached the top of Mt. Everest.") == 1);
	assert(alphasorted("She was happy with how her earring hoops looked.") == 1);
	assert(alphasorted("Beth dislikes eating starfruit but enjoys cherries.") == 0);
	assert(alphasorted("Elinor is inside on a rainy day sipping hot chocolate.") == 1);
	assert(alphasorted("Mara took a photograph.") == 0);
	return 0;
}

/*

Given a sentence, create a function which shifts the first letter of each word to the next word in the sentence (shifting right).

Examples

shiftSentence("create a function") ➞ "freate c aunction"

shiftSentence("it should shift the sentence") ➞ "st ihould shift she tentence"

shiftSentence("the output is not very legible") ➞ "lhe tutput os iot nery vegible"

shiftSentence("edabit") ➞ "edabit"

Notes

    The last word shifts its first letter to the first word in the sentence.
    All sentences will be given in lowercase.
    Note how single words remain untouched (example #4).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
copy(const char *s, char *b, size_t *i, size_t *j)
{
	for (; isspace(s[*i]); *i += 1)
		b[*i] = s[*i];

	for (*j = *i; s[*i] && !isspace(s[*i]); *i += 1)
		b[*i] = s[*i];

	for (; isspace(s[*i]); *i += 1)
		b[*i] = s[*i];
}

char *
shiftsentence(const char *s, char *b)
{
	size_t i, j, k, l;

	i = 0;
	copy(s, b, &i, &j);
	for (l = j; s[i]; j = k) {
		copy(s, b, &i, &k);
		b[k] = s[j];
		if (!s[i])
			b[l] = s[k];
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	shiftsentence(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("create a function", "freate c aunction");
	test("it should shift the sentence", "st ihould shift she tentence");
	test("the output is not very legible", "lhe tutput os iot nery vegible");
	test("where is the butter", "bhere ws ihe tutter");
	test("she sells sea shells", "she sells sea shells");
	test("one plus one equals two", "tne olus pne oquals ewo");
	test("tey ghis uot hnscrambled", "hey this got unscrambled");
	test("i love to eat scrambled eggs and ham", "h iove lo tat ecrambled sggs end aam");
	test("mitochondria is the powerhouse of the cell", "citochondria ms ihe towerhouse pf ohe tell");
	test("sarah the key is under the door mat", "marah she tey ks inder uhe toor dat");
	test("elephants dance about bravely in thailand", "tlephants eance dbout aravely bn ihailand");
	test("untouched", "untouched");
	test("edabit", "edabit");
	test("abc def", "dbc aef");

	return 0;
}

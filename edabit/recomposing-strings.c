/*

In this challenge, the goal is recomposing scrambled strings made of two or more words.

Every string has to be reversed not in its totality, but by vowels or consonants clusters in the order they are found;
after splitting the string in groups, and reversing every group with more than a letter, you'll obtain the correct sequence:

String = "KiKdaola"

Separation vowels/consonants = K  i  Kd  ao  l  a

Reversing the groups = K  i  dK  oa  l  a

New string = KidKoala

Now, you have to insert a space between the words. A word starts with a capital letter:

String = "KidKoala"

Result = "Kid Koala"

Given a string, implement a function that returns, in turn, a new correct string, following the above instructions.
Examples

recompose("KiKdaola") ➞ "Kid Koala"

recompose("BaosdrOCfanada") ➞ "Boards Of Canada"
// B  ao  sdr  O  Cf  a  n  a  d  a
// B  oa  rds  O  fC  a  n  a  d  a

recompose("hCemicarBlohtesr") ➞ "Chemical Brothers"
// hC  e  m  i  c  a  rBl  o  ht  e  sr
// Ch  e  m  i  c  a  lBr  o  th  e  rs

Notes

    Every given string will be valid, containing only letters and at least two words (identified by the capital letters).
    Remember to reverse the clusters of letters and not the entire string.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

void
swapc(char *x, char *y)
{
	char t;

	t = *y;
	*y = *x;
	*x = t;
}

void
rev(char *s, size_t i, size_t j)
{
	while (i < j)
		swapc(&s[i++], &s[--j]);
}

char *
recompose(const char *s, char *b)
{
	size_t i, j, n;

	n = 0;
	while (s[n]) {
		for (i = n; s[n] && isvowel(s[n]); n++)
			b[n] = s[n];
		rev(b, i, n);

		for (i = n; s[n] && !isvowel(s[n]); n++)
			b[n] = s[n];
		rev(b, i, n);
	}

	j = n;
	for (i = 0; i < n; i++) {
		if (i && isupper(b[i]))
			b[j++] = ' ';
		b[j++] = b[i];
	}
	b[j] = '\0';

	memmove(b, b + n, j - n + 1);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	recompose(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("KiKdaola", "Kid Koala");
	test("BaosdrOCfanada", "Boards Of Canada");
	test("hCemicarBlohtesr", "Chemical Brothers");
	test("MuosOeMnasr", "Mouse On Mars");
	test("AhpewTxin", "Aphex Twin");
	test("MassivAettakc", "Massive Attack");
	test("DeosItOffeYdnuoYaeh", "Does It Offend You Yeah");
	test("", "");

	return 0;
}

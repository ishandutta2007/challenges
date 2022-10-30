/*

Create a function that takes two strings. The first string contains a sentence containing the letters of the second string in a consecutive sequence but in a different order.
The hidden anagram must contain all the letters, including duplicates, from the second string in any order and must not contain any other alphabetic characters.

Write a function to find the anagram of the second string embedded somewhere in the first string.
You should ignore character case, any spaces, and punctuation marks and return the anagram as a lower case string with no spaces or punctuation marks.

Examples

hiddenAnagram("An old west action hero actor", "Clint Eastwood") ➞ "noldwestactio"
// The sequence "n old west actio" is a perfect anagram of "Clint Eastwood".

hiddenAnagram("Mr. Mojo Rising could be a song title", "Jim Morrison") ➞ "mrmojorisin"
// The sequence "Mr. Mojo Risin" ignoring the full stop, is a perfect
// anagram of "Jim Morrison".

hiddenAnagram("Banana? margaritas", "ANAGRAM") ➞ "anamarg"
// The sequence "ana? marg" ignoring "?" is a perfect anagram of "Anagram".

hiddenAnagram("D  e b90it->?$ (c)a r...d,,#~", "bad credit") ➞ "debitcard"
// When all spaces, numbers and puntuation marks are removed
// from the whole phrase, the remaining characters form the sequence
// "Debitcard" which is a perfect anagram of "bad credit".

hiddenAnagram("Bright is the moon", "Bongo mirth") ➞ "noutfond"
// The words "Bright moon" are an anagram of "bongo mirth" but they are
// not a continuous alphabetical sequence because the words "is the" are in
// between. Hence the negative result, "noutfond" is returned.

Notes

    A perfect anagram contains all the letters of the original, in any order, no more, no less.
    If there is no hidden anagram in the sentence, return "noutfond".
    As in the above examples, the hidden anagram may start or finish part way through a word and/or span multiple words and may contain punctuation marks and other non-alpha characters.
    Ignore character case and any embedded non-alpha characters.
    If there is more than 1 result in a sentence, return the nearest to the beginning.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t
histogram(const char *s, size_t h[256])
{
	size_t i, l;
	int c;

	for (i = 0; i < 256; i++)
		h[i] = 0;
	for (i = l = 0; s[i]; i++) {
		if (!isalpha(s[i]))
			continue;
		c = tolower(s[i]) & 0xff;

		h[c]++;
		l++;
	}

	return l;
}

size_t
slide(char *b, size_t n, int c, size_t h[256])
{
	size_t i;

	for (i = 0; i < n; i++) {
		h[b[i] & 0xff]++;
		if (b[i] == c)
			break;
	}
	return i + 1;
}

char *
anagram(const char *s, const char *t, char *b)
{
	size_t h[256], hp[256];
	size_t i, j, k, l, m, n;
	int c;

	l = histogram(t, h);
	memcpy(hp, h, sizeof(h));
	for (i = j = k = n = 0; s[i]; i++) {
		if (!isalpha(s[i]))
			continue;
		c = tolower(s[i]) & 0xff;

		if (!hp[c]) {
			if (n) {
				memcpy(h, hp, sizeof(hp));
				j = k = n = 0;
			}
			continue;
		}

		if (!h[c]) {
			m = slide(b + j, k - j, c, h);
			j += m;
			n -= m;
		}

		h[c]--;
		b[k++] = c;
		if (++n >= l)
			break;
	}

	if (n < l)
		sprintf(b, "noutfond");
	else {
		memmove(b, b + k - l, l);
		b[l] = '\0';
	}

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	anagram(s, t, b);
	printf("%s\n%s\n\n", b, r);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("An old west action hero actor", "Clint Eastwood", "noldwestactio");
	test("Mr. Mojo Rising could be a song title", "Jim Morrison", "mrmojorisin");
	test("Banana? margaritas", "ANAGRAM", "anamarg");
	test("D  e b90it->?$ (c)a r...d,,#~", "bad credit", "debitcard");
	test("Bright is the moon", "Bongo mirth", "noutfond");
	test("Sir Patrick Moore was a famous moon starer", "Astronomer", "moonstarer");
	test("A building, built to stay free of defects, is uncommon!", "Statue of Liberty", "builttostayfree");
	test("Bright is the moon", "Bongo mirth", "noutfond");
	test("Anchor man Bill, a well known TV personality, was confused about becoming president", "Abraham Lincoln", "anchormanbilla");
	test("There seem to be more and more television ads on the box these days!", "enslave idiots", "televisionads");
	test("The thing orators hate most is a throat infection", "A sore throat", "oratorshate");
	test("I thought I heard a high cornet note of great beuaty", "One Cornetto", "cornetnoteo");
	test("D  e b90it->?$ (c)a r...d,,#~", "bad credit", "debitcard");
	test("You won't find any anagram here!", "aerogramhenna", "noutfond");
	test("", "", "");
	test("ab", "ba", "ab");

	return 0;
}

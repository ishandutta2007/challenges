/*

Each letter in a sentence is worth its position in the alphabet (i.e. a = 1, b = 2, c = 3, etc...). However, if a word is all in UPPERCASE, the value of that word is doubled.

Create a function which returns the value of a sentence.

getSentenceValue("abc ABC Abc") ➞ 24
// a = 1, b = 2, c = 3

// abc = 1 + 2 + 3 = 6
// ABC = (1+2+3) * 2 = 12 (ALL letters are in uppercase)
// Abc = 1 + 2 + 3 = 6 (NOT ALL letters are in uppercase)

// 6 + 12 + 6 = 24

Examples

getSentenceValue("HELLO world") ➞ 176

getSentenceValue("Edabit is LEGENDARY") ➞ 251

getSentenceValue("Her seaside sea-shelling business is really booming!") ➞ 488

Notes

    Ignore spaces and punctuation.
    Remember that the value of a word isn't doubled unless all the letters in it are uppercase.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

unsigned
sentencevalue(const char *s)
{
	size_t i, j, k;
	unsigned v;

	v = 0;
	for (i = j = k = 0; s[i]; i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			j += s[i] - 'a' + 1;
			k = 1;
		} else if ('A' <= s[i] && s[i] <= 'Z')
			j += s[i] - 'A' + 1;
		else if (isspace(s[i])) {
			v += j * (k ? 1 : 2);
			j = k = 0;
		}
	}
	v += j * (k ? 1 : 2);

	return v;
}

int
main(void)
{

	assert(sentencevalue("abc ABC Abc") == 24);
	assert(sentencevalue("HELLO world") == 176);
	assert(sentencevalue("Edabit is Legendary") == 160);
	assert(sentencevalue("Her seaside sea-shelling business is really booming!") == 488);
	assert(sentencevalue("edabit Edabit EDABIT") == 164);
	assert(sentencevalue("expensive words") == 198);
	assert(sentencevalue("FISH AND CHIPS") == 232);
	assert(sentencevalue("this sentence is like a piece of hay in a needle stack") == 423);
	assert(sentencevalue("CAN YOU STOP SHOUTING?! I CAN'T HEAR MYSELF THINK!!!") == 966);
	assert(sentencevalue("a whisper in the wind...") == 205);
	assert(sentencevalue("==.;[==.;][==.;[==.][==.;==.][") == 0);
	assert(sentencevalue("Isn't it funny how the word BIG is physically smaller than the word small?") == 777);
	assert(sentencevalue("this is a really pricey sentence: ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ") == 2503);
	assert(sentencevalue("                    ") == 0);
	assert(sentencevalue("") == 0);
	assert(sentencevalue("Oranges and APPLES") == 236);
	assert(sentencevalue("Edabit is LEGENDARY") == 251);

	return 0;
}

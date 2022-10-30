/*

Create a function that takes a string and replaces every letter with the letter following it in the alphabet ("c" becomes "d", "z" becomes "a", "b" becomes "c", etc).
Then capitalize every vowel (a, e, i, o, u) and return the new modified string.

Examples

mangle("Fun times!") ➞ "GvO Ujnft!"

mangle("The quick brown fox.") ➞ "UIf rvjdl cspxO gpy."

mangle("Omega") ➞ "Pnfhb"

Notes

    If a letter is already uppercase, return it as uppercase (regardless of being a vowel).
    "y" is not considered a vowel.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
mangle(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if ('a' <= s[i] && s[i] <= 'z')
			b[j++] = 'a' + (s[i] - 'a' + 1) % 26;
		else if ('A' <= s[i] && s[i] <= 'Z')
			b[j++] = 'A' + (s[i] - 'A' + 1) % 26;
		else
			b[j++] = s[i];

		if (strchr("aeiou", b[j - 1]))
			b[j - 1] = toupper(b[j - 1]);
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	mangle(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Fun times!", "GvO Ujnft!");
	test("The quick brown fox.", "UIf rvjdl cspxO gpy.");
	test("Omega", "Pnfhb");
	test("I will never be this young again. Ever. Oh damn… I just got older.", "J xjmm Ofwfs cf UIjt zpvOh bhbjO. Fwfs. PI EbnO… J kvtU hpU pmEfs.");
	test("Should we start class now, or should we wait for everyone to get here?", "TIpvmE xf tUbsU dmbtt Opx, ps tIpvmE xf xbjU gps fwfszpOf Up hfU Ifsf?");
	test("Check back tomorrow; I will see if the book has arrived.", "DIfdl cbdl Upnpsspx; J xjmm tff jg UIf cppl Ibt bssjwfE.");
	test("The lake is a long way from here.", "UIf mblf jt b mpOh xbz gspn Ifsf.");
	test("It was getting dark, and we weren’t there yet.", "JU xbt hfUUjOh Ebsl, bOE xf xfsfO’U UIfsf zfU.");
	test("The mysterious diary records the voice.", "UIf nztUfsjpvt Ejbsz sfdpsEt UIf wpjdf.");
	test("Cats are good pets, for they are clean and are not noisy.", "DbUt bsf hppE qfUt, gps UIfz bsf dmfbO bOE bsf OpU Opjtz.");
	test("abcz", "bcdA");
	test("ABCZ", "BCDA");

	return 0;
}

/*

Create a function that takes a string and returns dashes on the left and right side of every vowel (a e i o u).
Examples

dashed("Edabit") ➞ "-E-d-a-b-i-t"

dashed("Carpe Diem") ➞ "C-a-rp-e- D-i--e-m"

dashed("Fight for your right to party!") ➞ "F-i-ght f-o-r y-o--u-r r-i-ght t-o- p-a-rty!"

Notes

    A string can contain uppercase and lowercase vowels.
    Y is not considered a vowel.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isvowel(char c)
{
	return strchr("aeiou", tolower(c)) != 0;
}

char *
dashed(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (isvowel(s[i])) {
			b[j++] = '-';
			b[j++] = s[i];
			b[j++] = '-';
		} else
			b[j++] = s[i];
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *t)
{
	char b[256];

	assert(!strcmp(dashed(s, b), t));
}

int
main(void)
{
	test("Edabit", "-E-d-a-b-i-t");
	test("Carpe Diem", "C-a-rp-e- D-i--e-m");
	test("Fight for your right to party!", "F-i-ght f-o-r y-o--u-r r-i-ght t-o- p-a-rty!");
	test("Finishing off someone’s sentence is annoying, even if you have guessed correctly. Add to that rude, if they stutter.", "F-i-n-i-sh-i-ng -o-ff s-o-m-e--o-n-e-’s s-e-nt-e-nc-e- -i-s -a-nn-o-y-i-ng, -e-v-e-n -i-f y-o--u- h-a-v-e- g-u--e-ss-e-d c-o-rr-e-ctly. -A-dd t-o- th-a-t r-u-d-e-, -i-f th-e-y st-u-tt-e-r.");
	test("Fear the soldier who stammers, for he is very fast at pulling the triger.", "F-e--a-r th-e- s-o-ld-i--e-r wh-o- st-a-mm-e-rs, f-o-r h-e- -i-s v-e-ry f-a-st -a-t p-u-ll-i-ng th-e- tr-i-g-e-r.");
	test("Thank you, I said bravely, dropping the syllables cleanly, like marbles, and secretly full of the most pathetic pride imaginable.", "Th-a-nk y-o--u-, -I- s-a--i-d br-a-v-e-ly, dr-o-pp-i-ng th-e- syll-a-bl-e-s cl-e--a-nly, l-i-k-e- m-a-rbl-e-s, -a-nd s-e-cr-e-tly f-u-ll -o-f th-e- m-o-st p-a-th-e-t-i-c pr-i-d-e- -i-m-a-g-i-n-a-bl-e-.");

	return 0;
}

/*

Write a function that removes any non-letters from a string, returning a well-known film title.

Examples

lettersOnly("R!=:~0o0./c&}9k`60=y") ➞ "Rocky"

lettersOnly("^,]%4B|@56a![0{2m>b1&4i4") ➞ "Bambi"

lettersOnly("^U)6$22>8p).") ➞ "Up"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
lettersonly(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (isalpha(s[i]))
			b[j++] = s[i];
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(!strcmp(lettersonly(s, b), r));
}

int
main(void)
{
	test(",1|2))A^1<[_)?^]l[a`3+%!d@8-0_0d.*}i@&n?=", "Aladdin");
	test("^U)6$22>8p).", "Up");
	test("I5n!449+c@e*}@@1]p{2@`,~t:i0o%n<3%8", "Inception");
	test("!)P[s9)69}yc3+?1]+33>3ho", "Psycho");
	test(":~;G{o}o{+524<df~:>}e24{l8:_l]a:?@]%s7", "Goodfellas");
	test("&&S~]@8>1-0!h#r),80<_>!}|e>_k:", "Shrek");
	test(")^/|,!!09]=/1<G2?`=[l{a}d9]^i7a0|t6_o2*r", "Gladiator");
	test("]8;]V9e{=0r!.5t>i<^_g4o5~", "Vertigo");
	test("%%)??B#>/_4a#,;t8|m8675a(n", "Batman");
	test("97H^)~a8567ll*o?6%)w63e37e<n?@=", "Halloween");
	test("Weird", "Weird");
	test("97@@@@@Xup", "Xup");
	test("97^)$)*%(*!!(&%(*%(*!)", "");

	return 0;
}

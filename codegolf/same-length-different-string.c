/*

Given a non-empty string S of length L consisting entirely of printable ASCII chars, output another string of length L that consists entirely of printable ASCII chars, but is not equal to S.

For the purposes of this challenge, a printable ASCII char is one between U+0020 and U+007E, inclusive; that is, from   (space) to ~ (tilde). Newlines and tabs are not included.

For example, given "abcde", some valid outputs could be:

"11111"
"abcdf"
"edcba"
But these would be invalid:

"abcde"
"bcde"
"abcde0"
Test cases
"asdf"
"1111"
"       "
"~~~~~"
"abcba"
"1"
" "
"~"
" ~"
"~ "
"  0"
"!@#$%^&*()ABCDEFGhijklmnop1234567890"
" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

Rules
You may assume the input consists entirely of printable ASCII chars.
You may not assume that the input does not contain all 95 printable chars.
You may assume the input contains at least one character and is less than 256 chars long.
The output must also consist entirely of printable ASCII chars. You could not, for example, output the byte \x7F for input "~".
The output must be different than the input with probability 1; that is, you may generate random strings until one is different than the input, but you can't just output L random characters and hope it's different.
Newlines are disallowed in the output, but you may output one trailing newline which is not counted toward the string.

*/

#include <stdio.h>
#include <ctype.h>

char *
different(const char *s, char *b)
{
	size_t i;
	int n;

	for (i = 0; s[i]; i++) {
		for (n = 1;; n++) {
			b[i] = s[i] + n;
			if (isprint(b[i]))
				break;

			b[i] = s[i] - n;
			if (isprint(b[i]))
				break;
		}
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s)
{
	char b[128];

	different(s, b);
	printf("%s\n", b);
}

int
main(void)
{
	test("hello");
	test("~!@#$%^&*()_+");
	test("ALFJ");

	return 0;
}

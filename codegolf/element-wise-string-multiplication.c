/*

Inspired by this challenge (thanks @cairdcoinheringaahing for the title!), your task is to take two printable ASCII strings and multiply them element-wise with the following rules.

How does it work?
Given two strings (for example split and isbn) you will first, truncate the longer one such that they have equal length and then determine their ASCII codes:

split -> spli -> [115, 112, 108, 105]
isbn  -> isbn -> [105, 115,  98, 110]
The next step will be to map them to the range [0..94] by subtracting 32 of each code:

[115, 112, 108, 105] -> [83, 80, 76, 73]
[105, 115,  98, 110] -> [73, 83, 66, 78]
Now you will multiply them element-wise modulo 95 (to stay in the printable range):

[83, 80, 76, 73] ⊗ [73, 83, 66, 78] -> [74, 85, 76, 89]
Add 32 to get back to the range [32..126]:

[74, 85, 76, 89] -> [106, 117, 108, 121]
And the final step is to map them back to ASCII characters:

[106, 117, 108, 121] -> "july"
Rules
You will write a program/function that implements the described steps on two strings and either prints or returns the resulting string
The input format is flexible: you can take two strings, a tuple of strings, list of strings etc.
The input may consist of one or two empty strings
The input will be characters in the printable range ([32..126])
The output is either printed to the console or you return a string
The output is allowed to have trailing whitespaces
Test cases
"isbn", "split"                  -> "july"
"", ""                           -> ""
"", "I don't matter"             -> ""
"             ", "Me neither :(" -> "             "
"but I do!", "!!!!!!!!!"         -> "but I do!"
'quotes', '""""""'               -> 'ck_iKg'
"wood", "hungry"                 -> "yarn"
"tray", "gzip"                   -> "jazz"
"industry", "bond"               -> "drop"
"public", "toll"                 -> "fall"
"roll", "dublin"                 -> "ball"
"GX!", "GX!"                     -> "!!!"
"4 lll 4", "4 lll 4"             -> "4 lll 4"
"M>>M", "M>>M"                   -> ">MM>"
Note: The quotes are just for readability, in the 6th test case I used ' instead of ".

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
muls(const char *s, const char *t, char *b)
{
	size_t i;
	int x, y;

	for (i = 0; s[i] && t[i]; i++) {
		x = s[i] & 0xff;
		y = t[i] & 0xff;
		b[i] = (((x - 32) * (y - 32)) % 95) + 32;
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	muls(s, t, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("isbn", "split", "july");
	test("", "", "");
	test("", "I don't matter", "");
	test("             ", "Me neither :(", "             ");
	test("but I do!", "!!!!!!!!!", "but I do!");
	test("quotes", "\"\"\"\"\"\"", "ck_iKg");
	test("wood", "hungry", "yarn");
	test("tray", "gzip", "jazz");
	test("industry", "bond", "drop");
	test("public", "toll", "fall");
	test("roll", "dublin", "ball");
	test("GX!", "GX!", "!!!");
	test("4 lll 4", "4 lll 4", "4 lll 4");
	test("M>>M", "M>>M", ">MM>");

	return 0;
}

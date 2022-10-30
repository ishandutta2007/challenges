/*

Given a string as input, output a number of whitespace characters (0x0A and 0x20) equal to the length of the string.

For example, given the string Hello, World! your code would need to output exactly 13 whitespace characters and nothing else. These can be any mix of spaces and newlines.

Your code should not output any additional trailing newlines or spaces.

Testcases:
     Input      -> Amount of whitespace to output
"Hello, World!" -> 13
"Hi"            -> 2
"   Don't
Forget about
Existing
Whitespace!   " -> 45
""              -> 0
"             " -> 13
"
"               -> 1
Scoring:
This is code-golf so fewest bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
whiten(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		b[i] = s[i];
		if (b[i] != '\n')
			b[i] = ' ';
	}
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	whiten(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Hello, World!", "             ");
	test("Hi", "  ");
	test("   Don't\nForget about\nExisting\nWhitespace!   ", "        \n            \n        \n              ");
	test("", "");
	test("             ", "             ");
	test("\n", "\n");

	return 0;
}

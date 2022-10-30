/*

Create a function that takes a phrase and transforms each word using the following rules:

    Keep first and last character the same.
    Transform middle characters into a dash -.

Examples

partiallyHide("skies were pretty") ➞ "s---s w--e p----y"

partiallyHide("red is not my color") ➞ "r-d is n-t my c---r"

partiallyHide("She rolled her eyes") ➞ "S-e r----d h-r e--s"

partiallyHide("Harry went to fight the basilisk") ➞ "H---y w--t to f---t t-e b------k"

Notes

Words with two or fewer letters should not be hidden at all.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
hide(const char *s, char *b)
{
	size_t i, j;

	for (i = 0; s[i];) {
		for (; isspace(s[i]); i++)
			b[i] = s[i];

		for (j = i; s[i] && !isspace(s[i]); i++)
			b[i] = '-';
		b[j] = s[j];
		b[i - 1] = s[i - 1];
	}
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	hide(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Harry went to fight the basilisk", "H---y w--t to f---t t-e b------k");
	test("She rolled her eyes", "S-e r----d h-r e--s");
	test("skies were so beautiful", "s---s w--e so b-------l");
	test("red is not my color", "r-d is n-t my c---r");
	test("so many options", "so m--y o-----s");
	test("the orient express", "t-e o----t e-----s");
	test("went to the post office", "w--t to t-e p--t o----e");
	test("skies were pretty", "s---s w--e p----y");
	test("he sh c", "he sh c");

	return 0;
}

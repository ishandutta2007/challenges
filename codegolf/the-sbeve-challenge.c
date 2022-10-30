/*

She said s(he) be(lie)ve(d), he said sbeve.

Input

A non-empty string, s. It's guaranteed that s will have only printable ASCII characters and at least one word (defined as [A-Za-z0-9]+) in parentheses, and all parentheses will be closed respectively.
Output

A string containing all non-whitespace characters (whitespaces are defined as spaces, tabs, carriage returns, new lines, vertical tabs and form feeds characters) that are not in parentheses.
Test cases

Input -> Output
s(he) be(lie)ve(d) -> sbeve
s(h3) (1s) br(0k)3n -> sbr3n
(I) (K)now (Ill) Be
(My) Best (Self) -> nowBeBest
sho(u)lder (should)er
s(ho)u(ld)er s(h)ould(er) -> sholderersuersould
p(er)f(ection) -> pf
(hello) (world) ->
The last output is an empty string.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
sbeve(const char *s, char *b)
{
	size_t i, j, p;

	for (i = j = p = 0; s[i]; i++) {
		if (s[i] == '(')
			p++;
		else if (s[i] == ')') {
			if (p == 0) {
				strcpy(b, "error: unmatched parentheses");
				return NULL;
			}
			p--;
		} else if (p == 0 && !isspace(s[i]))
			b[j++] = s[i];
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	sbeve(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("s(he) be(lie)ve(d)", "sbeve");
	test("s(h3) (1s) br(0k)3n", "sbr3n");
	test("(I) (K)now (Ill) Be\n(My) Best (Self)", "nowBeBest");
	test("sho(u)lder (should)er\ns(ho)u(ld)er s(h)ould(er)", "sholderersuersould");
	test("p(er)f(ection)", "pf");
	test("(hello) (world)", "");

	return 0;
}

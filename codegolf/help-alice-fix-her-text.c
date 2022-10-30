/*

When Alice was touch typing on her QWERTY keyboard (Figure 1), she accidentally shifted both of her hands rightwards by one key, so q became w, w became e, etc. (p became [). Spaces were not affected because the space bar was quite big.

Your task is to help her fix her message using the shortest number of bytes, i.e. undo the shifting of her hand positions.
More precisely, you will be given a string consisting of spaces as well as characters from wertyuiop[sdfghjkl;xcvbnm, and you need to map the characters to qwertyuiopasdfghjklzxcvbnm and leave spaces untouched.

Here are some testcases for you to test your program:

input      output
----------------------
s[[;r      apple
s gom      a fin
werty      qwert
uiop[      yuiop
sdfgh      asdfg
jkl;       hjkl
xcvb       zxcv
nm,        bnm
 ;p;;o[p[   lollipop
[2 spaces] [2 spaces]

(the lollipop testcase starts with a space)

Figure 1: Alice's QWERTY keyboard

This is code-golf. Shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
fix(const char *s, char *b)
{
	static const char keyed[] = "qwertyuiopasdfghjklzxcvbnm";
	static const char typed[] = "wertyuiop[sdfghjkl;xcvbnm,";

	size_t i;
	char *p;

	for (i = 0; s[i]; i++) {
		p = strchr(typed, s[i]);
		b[i] = (!p) ? s[i] : keyed[p - typed];
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	fix(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("s[[;r", "apple");
	test("s gom", "a fin");
	test("werty", "qwert");
	test("uiop[", "yuiop");
	test("sdfgh", "asdfg");
	test("jkl;", "hjkl");
	test("xcvb", "zxcv");
	test("nm,", "bnm");
	test(" ;p;;o[p[", " lollipop");
	test("  ", "  ");

	return 0;
}

/*

Write a function that takes a string, and returns a new string with any duplicate consecutive letters removed.

Examples

unstretch("ppoeemm") ➞ "poem"

unstretch("wiiiinnnnd") ➞ "wind"

unstretch("ttiiitllleeee") ➞ "title"

unstretch("cccccaaarrrbbonnnnn") ➞ "carbon"

Notes

Final strings won't include words with double letters (e.g. "passing", "lottery").

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
unstretch(const char *s, char *b)
{
	size_t i, j, k;

	for (i = k = 0; s[i]; i = j) {
		b[k++] = s[i];
		j = i + 1;
		while (s[i] == s[j])
			j++;
	}
	b[k] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	unstretch(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("llossttttt", "lost");
	test("cccccaaaaannnnne", "cane");
	test("hhoooneestttt", "honest");
	test("ppppooowwddddeeerrrr", "powder");
	test("eexxpppppeeccctt", "expect");
	test("rrrrepooooorrttt", "report");
	test("pppaaaaattteeeennnntt", "patent");
	test("mmmeeemoooryy", "memory");
	test("vvvvviiiiisssuuaaalll", "visual");
	test("eeeennnnsuuurrre", "ensure");
	test("iiinncclludddddeee", "include");
	test("ttteestiffffyyy", "testify");
	test("ggrrrrraaaaavvvvviiitttyyyy", "gravity");
	test("cccuuuultttttuuuuurreee", "culture");
	test("qquaalliiifffyy", "qualify");
	test("iiinnccoooonnnnnggggrrrrruuuuooouuuuusss", "incongruous");
	test("eeeennnnttiiiitlllleeeeemmeennnttttt", "entitlement");
	test("aaaaassstttttooniiiiissshhiiinnnnnggg", "astonishing");
	test("cccccoiinnnncccciidddenncee", "coincidence");
	test("prrrrreeeppppaaaarrrrraaattiionn", "preparation");
	test("ppoeemm", "poem");
	test("wiiiinnnnd", "wind");
	test("ttiiitllleeee", "title");
	test("cccccaaarrrbbonnnnn", "carbon");
	test("lottery", "lotery");
	test("passing", "pasing");

	return 0;
}

/*

A word has been split into a left part and a right part.
Re-form the word by adding both halves together, changing the first character to an uppercase letter.

Examples

getWord("seas", "onal") ➞ "Seasonal"

getWord("comp", "lete") ➞ "Complete"

getWord("lang", "uage") ➞ "Language"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
reform(const char *s, const char *t, char *b, size_t n)
{
	snprintf(b, n, "%s%s", s, t);
	if (isalpha(b[0]))
		b[0] = toupper(b[0]);
	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	reform(s, t, b, sizeof(b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("seas", "onal", "Seasonal");
	test("comp", "lete", "Complete");
	test("lang", "uage", "Language");
	test("maga", "zine", "Magazine");
	test("reli", "able", "Reliable");
	test("impl", "icit", "Implicit");
	test("docu", "ment", "Document");
	test("oppo", "site", "Opposite");
	test("offi", "cial", "Official");
	test("disa", "gree", "Disagree");
	test("acci", "dent", "Accident");
	test("omis", "sion", "Omission");
	test("vigo", "rous", "Vigorous");
	test("pred", "ator", "Predator");
	test("inva", "sion", "Invasion");
	test("fare", "well", "Farewell");
	test("majo", "rity", "Majority");
	test("pers", "onal", "Personal");
	test("sequ", "ence", "Sequence");
	test("gove", "rnor", "Governor");
	test("igno", "rant", "Ignorant");
	test("fini", "shed", "Finished");

	return 0;
}

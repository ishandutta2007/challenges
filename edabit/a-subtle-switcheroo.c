/*

Create a function which replaces all instances of "nts" with "nce" and vice versa if they are at the end of a word.

Examples

switcheroo("The elephants in France were chased by ants!") ➞ "The elephance in Frants were chased by ance!"

switcheroo("While he rants, I fall into a trance...") ➞ "While he rance, I fall into a trants..."

switcheroo("Bounced over the fence!") ➞ "Bounced over the fents!"

Notes

    Empty strings should return just an empty string (see example #2).
    Ignore punctuation and any instances where "nts" or "nce" are not at the end of a word (see example #3).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
fixup(char *b, size_t i)
{
	while (i && (isspace(b[i]) || ispunct(b[i])))
		i--;

	if (i < 2)
		return;

	if (!strncmp(b + i - 2, "nce", 3))
		memcpy(b + i - 2, "nts", 3);
	else if (!strncmp(b + i - 2, "nts", 3))
		memcpy(b + i - 2, "nce", 3);
}

char *
switcheroo(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		b[i] = s[i];
		if (isspace(s[i]) || !s[i + 1])
			fixup(b, i);
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	switcheroo(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("While he rants, I fall into a trance...", "While he rance, I fall into a trants...");
	test("The elephants in France were chased by ants!", "The elephance in Frants were chased by ance!");
	test("Bounced over the fence!", "Bounced over the fents!");
	test("Face", "Face");
	test("Fats", "Fats");
	test("", "");
	test("nce", "nts");
	test("nts", "nce");

	return 0;
}

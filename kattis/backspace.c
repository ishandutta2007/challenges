/*

Shortly before the programming contest started, Bjarki decided to update his computer. He didn’t notice anything strange until he started coding in his favorite editor, Bim (Bjarki IMproved).
Usually when he’s writing in an editor and presses the backspace key a single character is erased to the left. But after the update pressing that key outputs the character <.
He’s tested all the editors on his machine, Bmacs, Neobim, bjedit, NoteBjad++ and Subjark Text, but they all seem to have the same problem.
He doesn’t have time to search the web for a solution, and instead decides to temporarily circumvent the issue with a simple program.

Help Bjarki write a program that takes as input the string that was written in the text editor, and outputs the string as Bjarki intended to write it.
You can assume that Bjarki never intended to write the character <, and that Bjarki never pressed the backspace key in an empty line.

Input

One line containing the string that was written in the text editor. The length of the string is at most 106, and it will only contain lowercase letters from the English alphabet as well as the character <.

Output

One line containing the string as Bjarki intended to write it.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
type(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (s[i] == '<')
			j -= (j > 0);
		else
			b[j++] = s[i];
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	type(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("a<bc<", "b");
	test("foss<<rritun", "forritun");
	test("a<a<a<aa<<", "");

	return 0;
}

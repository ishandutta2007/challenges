/*

Super simple challenge today, or is it?

I feel like we've heard a fair bit about double speak recently, well let's define it in a codable way...

Double speak is when each and every character in a string of text is immediately repeated. For example:

"DDoouubbllee  ssppeeaakk!!"

The Rules

    Write code which accepts one argument, a string.
    It will modify this string, duplicating every character.
    Then it will return the double speak version of the string.
    It's code golf, try to achieve this in the smallest number of bytes.
    Please include a link to an online interpreter for your code.
    Input strings will only contain characters in the printable ASCII range. Reference: http://www.asciitable.com/mobile/

Leaderboards

Here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language.

Show code snippet

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

# Language Name, [Other information] N bytes

where N is the size of your submission. Other information may include flags set and if you've improved your score (usually a struck out number like <s>M</s>).
N should be the right-most number in this heading, and everything before the first , is the name of the language you've used. The language name and the word bytes may be links.

For example:

# [><>](http://esolangs.org/wiki/Fish), <s>162</s> 121 [bytes](https://esolangs.org/


*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
doublespeak(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		b[j++] = s[i];
		b[j++] = s[i];
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	doublespeak(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Double speak!", "DDoouubbllee  ssppeeaakk!!");

	return 0;
}

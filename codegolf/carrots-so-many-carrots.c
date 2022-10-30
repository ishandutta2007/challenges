/*

The Task
You must create a program, that, in as many languages as possible, replaces every instance of ^ with a markdown formatted link
(meaning that if I was to post it in an answer, it would automatically read it as an image and place the image instead of the words) of this upward facing carrot.

How to Use Said Formatting:
First, anywhere in the file, put in the link like so (this is what I did for this question):

[1]: http://i.stack.imgur.com/mecHl.png
And then, wherever you want it:

[![][1]][1]
Rules
Standard Loopholes apply.
Input will be through STDIN or equivalent.
Output will be through STDOUT or equivalent.
Your code must be a fully operating program in all languages that you use.
The URL that you use for your carrot does not have to be the one in this answer. This was just an example. You may use any URL, provided that SE's Markdown shows this specific carrot with it.
This is a polyglot challenge, so the answer with the greatest amount of carrots languages wins!
In the case of a tie, the shortest code size of the entries with the largest number of languages wins.
EDIT:

Also, do NOT use trivial derivatives of languages! This means using a substitution language (Brainfuck vs. ShadyAsFuck) and different language versions (Python 2 vs. Python 3).
There's a lot trivial esolangs to fit... (including 9001 BF variants)

Don't be that guy.

Note: Yes, this program will be slightly trivial in languages with regex support. However, the competition is to see how many languages the competitors can use.

*/

#include <stdio.h>

char *
carrotize(const char *s, char *b)
{
	size_t i, l;

	l = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '^')
			l += sprintf(b + l, "[![][1]][1]");
		else
			b[l++] = s[i];
	}
	sprintf(b + l, "\n[1]: http://i.stack.imgur.com/mecHl.png\n");
	return b;
}

void
test(const char *s)
{
	char b[128];

	carrotize(s, b);
	printf("%s\n", b);
}

int
main(void)
{
	test("^^^");

	return 0;
}

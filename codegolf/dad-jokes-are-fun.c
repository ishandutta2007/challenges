/*

We all know the classic dad joke that goes something like this:

    Somebody says a sentence to describe their self (e.g. I'm tired or I'm confused).

    A dad-joke enthusiast comes along and replies Hi <adjective>, I'm Dad!, because introductions follow the same format (I'm Peter follows the same format as I'm hungry).

Your job is to take in an input in the form of a self-descriptor, and output the appropriate dad-joke form, but instead of using the word "Dad", you'll use the name of the programming language you're programming in.

Test cases (assume that they are being parsed by Python):

I'm amazing                  Hi amazing, I'm Python!
I'm tired                    Hi tired, I'm Python!
I'm hungry                   Hi hungry, I'm Python!
I'm fat                      Hi fat, I'm Python!

Now assume that these test cases are being parsed by Golfscript:

I'm a programmer             Hi a programmer, I'm Golfscript!
I'm a question-writer        Hi a question-writer, I'm Golfscript!
I'm a Stack-Overflow-er      Hi a Stack-Overflow-er, I'm Golfscript!

The exact challenge:

    Take in a string in the self-descriptor format (I'm <adjective> or I'm a(n) <noun>) using standard input or through a function.

        Assume there is no ending punctuation.

        Assume the word I'm is used and not I am.

    Convert it to a dad-joke format - see the above examples for exactly how that should look.

Other stuff:

    This is code-golf, so shortest byte count wins.

    Follow the standard loophole rules - none of those, please.

    Have fun!

Leaderboard

You can view the leaderboard for this post by expanding the widget/snippet below. In order for your post to be included in the rankings, you need a header (# header text) with the following info:

    The name of the language (end it with a comma , or dash -), followed by...

    The byte count, as the last number to appear in your header.

For example, JavaScript (ES6), 72 bytes is valid, but Fortran, 143 bytes (8-bit) is invalid because the byte count is not the last number in the header (your answer will be recognized as 8 bytes - don't take advantage of this).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
dadjoke(const char *s, char *b)
{
	if (!strncmp(s, "I'm ", 4))
		s += 4;
	sprintf(b, "Hi %s, I'm C!", s);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	dadjoke(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("I'm amazing", "Hi amazing, I'm C!");
	test("I'm tired", "Hi tired, I'm C!");
	test("I'm hungry", "Hi hungry, I'm C!");
	test("I'm fat", "Hi fat, I'm C!");
	test("I'm a programmer", "Hi a programmer, I'm C!");
	test("I'm a question-writer", "Hi a question-writer, I'm C!");
	test("I'm a Stack-Overflow-er", "Hi a Stack-Overflow-er, I'm C!");

	return 0;
}

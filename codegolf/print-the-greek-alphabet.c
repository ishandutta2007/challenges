/*

Fairly obviously, you have to print the Greek alphabet. But I thought I'd make it slightly more interesting, so there's a twist: when your program is ran with an argument (anything), it should output the Greek alphabet in lowercase.

Information

    Greek alphabet (Capitals): ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ
    Greek alphabet (Lowercase): αβγδεζηθικλμνξοπρστυφχψω

Rules/Requirements

    Each submission must be a full program.
    Builtins to print the Greek alphabet are not permitted
    Standard loopholes apply
    You must print exactly what is shown.

Scoring

Programs are scored according to bytes. If you are using a character set different to UTF-8 please specify. Try to get the least bytes out of everyone, this is code-golf!
Test cases

./program
==> ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ

./program 1
==> αβγδεζηθικλμνξοπρστυφχψω

./program 'lower'
==> αβγδεζηθικλμνξοπρστυφχψω

./program 123897883421
==> αβγδεζηθικλμνξοπρστυφχψω

./program ""
==> αβγδεζηθικλμνξοπρστυφχψω

greek();
==> ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ

greek("blah");
==> αβγδεζηθικλμνξοπρστυφχψω

greek(123);
==> αβγδεζηθικλμνξοπρστυφχψω

Submissions

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

# Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

# Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

# Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the leaderboard snippet:

# [><>](http://esolangs.org/wiki/Fish), 121 bytes

Leaderboard

Here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language.

*/

#include <stdio.h>

void
greek(int n)
{
	static const char *upper = u8"ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ";
	static const char *lower = u8"αβγδεζηθικλμνξοπρστυφχψω";
	printf("%s\n", (n) ? lower : upper);
}

int
main(int argc, char *argv[])
{
	greek(argc >= 2);
	(void)argv;
	return 0;
}

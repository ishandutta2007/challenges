/*

At 1998, Brian Kernighan, while working on the book "The Practice of Programming", wanted to demonstrate realisation of regular expression engine. But struggled to find small engine, that could could fit in the book.

So Brian Kernighan asked Rob Pike to write one for him, and Rob did it gracefully. Here is original source:

    // match: search for regexp anywhere in text
    int match(char *regexp, char *text)
    {
        if (regexp[0] == '^')
            return matchhere(regexp+1, text);
        do {    // must look even if string is empty
            if (matchhere(regexp, text))
                return 1;
        } while (*text++ != '\0');
        return 0;
    }

    // matchhere: search for regexp at beginning of text
    int matchhere(char *regexp, char *text)
    {
        if (regexp[0] == '\0')
            return 1;
        if (regexp[1] == '*')
            return matchstar(regexp[0], regexp+2, text);
        if (regexp[0] == '$' && regexp[1] == '\0')
            return *text == '\0';
        if (*text!='\0' && (regexp[0]=='.' || regexp[0]==*text))
            return matchhere(regexp+1, text+1);
        return 0;
    }

    // matchstar: search for c*regexp at beginning of text
    int matchstar(int c, char *regexp, char *text)
    {
        do {    // a * matches zero or more instances
            if (matchhere(regexp, text))
                return 1;
        } while (*text != '\0' && (*text++ == c || c == '.'));
        return 0;
    }

Rules

Write regex engine that supports the same operations, as Rob's:
Any char (as symbol)
. to match any char
^ to match start of the string
$ to match end of the string
* to match any count of char from zero
Auxiliary code do not count (to accept input, for example)
Make the shortest solution and beat Rob Pike!

Input
Two strings: one for regex, one for match.

Output
True (in your language), if regex matches string
False (in your language), if regex do not match string

*/

#include <assert.h>
#include <stdio.h>
#include <regex.h>

int
match(const char *regexp, const char *text)
{
	regex_t re;
	int r;

	r = regcomp(&re, regexp, REG_EXTENDED | REG_NOSUB);
	if (r != 0)
		return -1;

	r = regexec(&re, text, 0, NULL, 0);
	regfree(&re);

	return r == 0;
}

int
main(void)
{
	assert(match("....", "tex") == 0);
	assert(match("....", "text") == 1);
	assert(match("c*a", "ccccca") == 1);

	return 0;
}

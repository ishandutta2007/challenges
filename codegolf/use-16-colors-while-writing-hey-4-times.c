/*

i.e each byte appears in a different ANSI shell colour.

Rules

    Resetting the color of the shell after output is not required
    Must be output in STDOUT or the primary colour text output of your language.
    Must be done programmatically (iterating through each color and letter of the string induvidually) instead of just writing a fixed string to shell like the reference command.
    Must output the same as the reference command: echo -e '\e[30mH\e[31me\e[32my\e[33m!\e[34mH\e[35me\e[36my\e[37m!\e[90mH\e[91me\e[92my\e[93m!\e[94mH\e[95me\e[96my\e[97m!' on a recent version of bash (I am using 4.3 installed via Homebrew on OS X) i.e like this: Reference output Obviously colours will vary based on terminal colour scheme.

Scoring

This is code-golf, so lowest bytes wins.

*/

#include <stdio.h>

int
main(void)
{
	static const char *txt = "\x1b[30mH\x1b[31me\x1b[32my\x1b[33m!\x1b[34mH\x1b[35me\x1b[36my\x1b[37m!\x1b[90mH\x1b[91me\x1b[92my\x1b[93m!\x1b[94mH\x1b[95me\x1b[96my\x1b[97m!";

	printf("%s\n", txt);
	return 0;
}

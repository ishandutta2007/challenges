/*

Using your language of choice, golf a quine.

    A quine is a non-empty computer program which takes no input and produces a copy of its own source code as its only output.

No cheating -- that means that you can't just read the source file and print it. Also, in many languages, an empty file is also a quine: that isn't considered a legit quine either.

No error quines -- there is already a separate challenge for error quines.

Points for:

    Smallest code (in bytes)
    Most obfuscated/obscure solution
    Using esoteric/obscure languages
    Successfully using languages that are difficult to golf in

The following Stack Snippet can be used to get a quick view of the current score in each language, and thus to know which languages have existing answers and what sort of target you have to beat:

*/

#include <stdio.h>

int
main(void)
{
	const char *s = "#include <stdio.h> int main(void) { const char *s=%c%s%c; printf(s,34,s,34); return 0; }";
	printf(s, 34, s, 34);
	return 0;
}

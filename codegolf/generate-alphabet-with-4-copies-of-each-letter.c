/*

Note that this is not the same as Print the alphabet four times.

This task is to write a program to generate four copies of each letter of the English alphabet, one letter per line, on standard output:

A
A
A
A
B
B
B
B

etc.

The output should include newlines after each letter.

Uppercase letters with no extra output are preferred; however, lowercase letters and/or extra whitespace are acceptable if capitalizing/stripping would lengthen your solution.

EDITED TO ADD: The solution must be complete enough to execute. I should be able to invoke an implementation of the language, paste the code from the answer, and get results, without typing any additional code.

The above question of completeness came up in the context of a C solution. Surely there must be a standing rule or convention about this on a code golfing site? If so, I'll gladly yield to the community guidelines. But this is my take:

    With regard to C specifically, you need to include (and count) the main(){...} around the code, since it won't compile otherwise. Warnings because there's no #include <stdio.h> are fine as long as the code still compiles. In general, a compiled language requires a compilable unit.

    A bare expression that yields the desired results is acceptable if there's a way to execute the expression directly; for instance, if the language has a REPL. So you can submit Haskell without a main= as long as it actually works as written at e.g. the ghci prompt. But since that means putting let on your declarations, it may be a net win to stick with the runhaskell format.

    Similarly, awk scripts should be in BEGIN (or END, with the assumption that stdin is attached to /dev/null) blocks since we're not processing any input.

*/

#include <stdio.h>

void
gen(void)
{
	int i, j;

	for (i = 'A'; i <= 'Z'; i++) {
		for (j = 0; j < 4; j++)
			printf("%c\n", i);
	}
}

int
main(void)
{
	gen();
	return 0;
}

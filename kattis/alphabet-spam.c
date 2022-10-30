/*

About 90 percent of the 300 billion emails sent every day are spam. Thus, a fast spam detection mechanism is crucial for large email providers. Lots of spammers try to circumvent spam detection by rewriting words like “M0n3y”, “Ca$h”, or “Lo||ery”.

A very simple and fast spam detection mechanism is based on the ratios between whitespace characters, lowercase letters, uppercase letters, and symbols.
Symbols are defined as characters that do not fall in one of the first three groups.

Input

The input consists of:

    one line with a string consisting of at least 1 and at most 100000 characters.

A preprocessing step has already transformed all whitespace characters to underscores (_), and the line will consist solely of characters with ASCII codes between 33 and 126 (inclusive).

Output

Output four lines, containing the ratios of whitespace characters, lowercase letters, uppercase letters, and symbols (in that order). Your answer should have an absolute or relative error of at most 10^-6.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
classify(const char *s)
{
	size_t i, l, h[4];

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++) {
		if (s[i] == '_')
			h[0]++;
		else if ('a' <= s[i] && s[i] <= 'z')
			h[1]++;
		else if ('A' <= s[i] && s[i] <= 'Z')
			h[2]++;
		else
			h[3]++;
	}
	l = i;

	for (i = 0; i < nelem(h); i++)
		printf("%.6f\n", h[i] * 1.0 / l);
}

int
main(void)
{
	classify("Welcome_NWERC_participants!");
	return 0;
}

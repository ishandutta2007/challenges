/*

Have the function LongestWord(sen) take the sen parameter being passed and return the largest word in the string.
If there are two or more words that are the same length, return the first word from the string with that length. Ignore punctuation and assume sen will not be empty. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *
longestword(const char *s)
{
	size_t i, j, k, l;
	char *p;

	p = strdup(s);
	if (p == NULL)
		return NULL;

	for (i = j = k = l = 0;; i++) {
		if ((isspace(s[i]) || s[i] == '\0') && l < k) {
			memmove(p, &s[i - j], j);
			p[j] = '\0';
			l = k;
			j = 0;
			k = 0;
		} else if (!isspace(s[i])) {
			j++;
			if (!ispunct(s[i]))
				k++;
		}

		if (s[i] == '\0')
			break;
	}

	return p;
}

void
test(const char *s)
{
	char *p;

	p = longestword(s);
	printf("%s\n", p);
	free(p);
}

int
main(void)
{
	test("fun&!! time");
	test("I love dogs");
	test("supercalifragilisticexpeialidocious");
	test("ice cream souffle");
	test("");
	test("reallylong\tword");
	test("NONE WDX!!!!ABCDE");
	return 0;
}

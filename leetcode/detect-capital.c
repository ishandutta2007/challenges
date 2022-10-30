/*

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

*/

#include <stdio.h>
#include <ctype.h>

int
detectcapital(const char *s)
{
	size_t i, l, u;

	l = u = 0;
	for (i = 0; s[i]; i++) {
		if (islower(s[i]))
			l++;
		else
			u++;
	}

	return l == i || u == i || (isupper(s[0]) && u == 1);
}

int
main(void)
{
	printf("%d\n", detectcapital("USA"));
	printf("%d\n", detectcapital("leetcode"));
	printf("%d\n", detectcapital("Google"));
	printf("%d\n", detectcapital("FlaG"));
	return 0;
}

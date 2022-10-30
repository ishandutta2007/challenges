/*

In this challenge, you will be given a string. You must remove characters until the string is made up of any two alternating characters.
When you choose a character to remove, all instances of that character must be removed.
Your goal is to create the longest string possible that contains just two alternating letters.

As an example, consider the string abaacdabd. If you delete the character a, you will be left with the string bcdbd.
Now, removing the character c leaves you with a valid string bdbd having a length of 4.
Removing either b or d at any point would not result in a valid string.

Given a string s, convert it to the longest possible string t made up only of alternating characters.
Print the length of string t on a new line. If no string t can be formed, print 0 instead.

1 <= s <= 1000
s[i] only contains a-z characters

*/

#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

size_t
alt(const char *s)
{
	size_t i, j, k, l, m;
	char a, b, c;

	m = 0;
	for (i = 0; i < 26; i++) {
		for (j = i + 1; j < 26; j++) {
			a = 'a' + i;
			b = 'a' + j;
			c = 0;
			l = 0;

			for (k = 0; s[k]; k++) {
				if (s[k] == a || s[k] == b) {
					if (s[k] == c)
						goto next;
					l++;
					c = s[k];
				}
			}

			m = max(m, l);
		}
	next:;
	}

	return m;
}

int
main(void)
{
	printf("%zu\n", alt("abaacdabd"));
	printf("%zu\n", alt("beabeefeab"));
	printf("%zu\n", alt("asdcbsdcagfsdbgdfanfghbsfdab"));
	printf("%zu\n", alt("asvkugfiugsalddlasguifgukvsa"));
	printf("%zu\n", alt("aaaaaaaaaaaaaaa"));
	printf("%zu\n", alt("abababababababababababab"));
	return 0;
}

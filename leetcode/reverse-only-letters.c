/*

Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

Note:

    S.length <= 100
    33 <= S[i].ASCIIcode <= 122
    S doesn't contain \ or "


*/

#include <stdio.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
revlet(char *s, size_t n)
{
	size_t i, j;
	char c;

	if (n == 0)
		return s;

	i = 0;
	j = n - 1;
	while (i < j) {
		if (!isalpha(s[i]))
			i++;
		else if (!isalpha(s[j]))
			j--;
		else {
			c = s[i];
			s[i] = s[j];
			s[j] = c;
			i++;
			j--;
		}
	}
	return s;
}

int
main(void)
{
	char a[] = "ab-cd";
	printf("%s\n", revlet(a, nelem(a) - 1));

	char b[] = "a-bC-dEf-ghIj";
	printf("%s\n", revlet(b, nelem(b) - 1));

	char c[] = "Test1ng-Leet=code-Q!";
	printf("%s\n", revlet(c, nelem(c) - 1));

	char d[] = "x-";
	printf("%s\n", revlet(d, nelem(d) - 1));

	return 0;
}

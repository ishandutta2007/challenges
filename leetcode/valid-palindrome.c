/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
ispalindrome(const char *s)
{
	size_t i, j, n;

	n = strlen(s);
	if (n == 0)
		return 1;

	i = 0;
	j = n - 1;
	while (i < j) {
		while (i < j && !isalpha(s[i]))
			i++;
		while (j > i && !isalpha(s[j]))
			j--;
		if (j < i || tolower(s[i]) != tolower(s[j]))
			return 0;
		i++;
		j--;
	}
	return 1;
}

int
main(void)
{
	printf("%d\n", ispalindrome(""));
	printf("%d\n", ispalindrome("A man, a plan, a canal: Panama"));
	printf("%d\n", ispalindrome("race a car"));
	printf("%d\n", ispalindrome("race aecar"));
	printf("%d\n", ispalindrome("AAbb`aa"));
	printf("%d\n", ispalindrome("a"));
	printf("%d\n", ispalindrome("aA`"));
	printf("%d\n", ispalindrome("`aA`b"));
	printf("%d\n", ispalindrome("\taxc   \b\t\fcxa"));
	return 0;
}

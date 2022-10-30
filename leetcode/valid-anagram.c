/*

Given two strings s and t , write a function to determine if t is an anagram of s.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

#include <stdio.h>
#include <string.h>

int
anagram(const char *s, const char *t)
{
	size_t a[256], b[256], i;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (i = 0;; i++) {
		if (!s[i] && !t[i])
			break;
		if ((!s[i] && t[i]) || (s[i] && !t[i]))
			return 0;
		a[s[i] & 0xff]++;
		b[t[i] & 0xff]++;
	}
	return memcmp(a, b, sizeof(a)) == 0;
}

int
main(void)
{
	printf("%d\n", anagram("anagram", "nagaram"));
	printf("%d\n", anagram("rat", "car"));
	return 0;
}

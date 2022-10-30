/*

Have the function MinWindowSubstring(strArr) take the array of strings stored in strArr, which will contain only two strings,
the first parameter being the string N and the second parameter being a string K of some characters,
and your goal is to determine the smallest substring of N that contains all the characters in K.

For example: if strArr is ["aaabaaddae", "aed"] then the smallest substring of N that contains the characters a, e, and d is "dae" located at the end of the string.
So for this example your program should return the string dae.

Another example: if strArr is ["aabdccdbcacd", "aad"] then the smallest substring of N that contains all of the characters in K is "aabd" which is located at the beginning of the string.
Both parameters will be strings ranging in length from 1 to 50 characters and all of K's characters will exist somewhere in the string N.
Both strings will only contains lowercase alphabetic characters.

Examples
Input: ["ahffaksfajeeubsne", "jefaa"]
Output: aksfaje
Input: ["aaffhkksemckelloe", "fhea"]
Output: affhkkse

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
mws(const char *s, const char *t, char *b)
{
	size_t h[256], hp[256];
	size_t l, lp;
	size_t i, j, m, n;
	int c;

	memset(h, 0, sizeof(h));
	for (l = 0; t[l]; l++)
		h[t[l] & 0xff]++;

	memcpy(hp, h, sizeof(h));
	lp = l;

	b[0] = '\0';
	n = 0;
	for (i = 0; s[i]; i++) {
		for (j = i; s[j]; j++) {
			c = s[j] & 0xff;
			if (!h[c])
				continue;
			h[c]--;

			if (--l)
				continue;

			m = j - i + 1;
			if (!n || m < n) {
				memcpy(b, s + i, m);
				b[m] = '\0';
				n = m;
			}
			break;
		}

		if (n <= lp)
			break;

		memcpy(h, hp, sizeof(hp));
		l = lp;
	}

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	mws(s, t, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("aaabaaddae", "aed", "dae");
	test("aabdccdbcacd", "aad", "aabd");
	test("ahffaksfajeeubsne", "jefaa", "aksfaje");
	test("aaffhkksemckelloe", "fhea", "affhkkse");
	test("xyyz yxz", "xyz", "yxz");
	test("xyyzx", "xyz", "yzx");
	test("fdfa", "fa", "fa");
	test("", "", "");
	test("A", "A", "A");
	test("BA", "CAB", "");
	test("X", "", "");

	return 0;
}

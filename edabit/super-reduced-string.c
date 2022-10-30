/*

Steve has a string of lowercase characters in range ascii[["a".."z"]].
He wants to reduce the string to its shortest length by doing a series of operations.
In each operation, he selects a pair of adjacent lowercase letters that match, and he deletes them. For instance, the string aab could be shortened to b in one operation.

Steve’s task is to delete as many characters as possible using this method and print the resulting string. If the final string is empty, return "Empty String".

Case

superReducedString("aaabccddd") ➞ "abd"

Explanation:

"aaabccddd" -> "abccddd" -> "abddd" -> "abd"

Examples

superReducedString("cccxllyyy") ➞ "cxy"

superReducedString("aa") ➞ "Empty String"

superReducedString("baab") ➞ "Empty String"

superReducedString("fghiiijkllmnnno") ➞ "fghijkmno"

superReducedString("chklssstt") ➞ "chkls"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
reduce(const char *s, char *b)
{
	size_t i, j, k;

	for (i = j = 0; s[i]; i = k) {
		k = i;
		while (s[i] == s[k])
			k++;

		if ((k - i) & 1)
			b[j++] = s[i];

		while (j > 1 && b[j - 1] == b[j - 2])
			j -= 2;
	}
	b[j] = '\0';

	if (b[0] == '\0')
		sprintf(b, "Empty String");

	return b;
}

void
test(const char *s, const char *t)
{
	char b[128];

	reduce(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, t));
}

int
main(void)
{
	test("aaabccddd", "abd");
	test("cccxllyyy", "cxy");
	test("aa", "Empty String");
	test("baab", "Empty String");
	test("fghiiijkllmnnno", "fghijkmno");
	test("chklssstt", "chkls");
	test("zzzhhnnttti", "zti");
	test("nnncqwerhhhou", "ncqwerhou");
	test("abbccddfghiaklmno", "afghiaklmno");
	test("bccddb", "Empty String");
	test("", "Empty String");
	test("qqq", "q");
	test("rthiioouusss", "rths");
	test("acdqglrfkqyuqfjkxyqvnrtysfrzrmzlygfveulqfpdbhlqdqrrqdqlhbdpfqluevfgylzmrzrfsytrnvqyxkjfquyqkfrlacdqj", "acdqgacdqj");

	return 0;
}

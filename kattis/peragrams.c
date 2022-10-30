/*

Per recently learned about palindromes. Now he wants to tell us about it and also has more awesome scientific news to share with us.

“A palindrome is a word that is the same no matter whether you read it backward or forward”, Per recently said in an interview.
He continued: “For example, add is not a palindrome, because reading it backwards gives dda and it’s actually not the same thing, you see.
However, if we reorder the letters of the word, we can actually get a palindrome. Hence, we say that add is a Peragram, because it is an anagram of a palindrome”.

Per gives us a more formal definition of Peragrams: “Like I said, if a word is an anagram of at least one palindrome, we call it a Peragram.
And recall that an anagram of a word w contains exactly the same letters as w, possibly in a different order.”

Task

Given a string, find the minimum number of letters you have to remove from it, so that the string becomes a Peragram.

Input

Input consists of a string on a single line. The string will contain at least 1 and at most 1000 characters. The string will only contain lowercase letters a-z.

Output

Output should consist of a single integer on a single line, the minimum number of characters that have to be removed from the string to make it a Peragram.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
peragram(const char *s)
{
	size_t h[256];
	size_t i;
	int r;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;

	r = 0;
	for (i = 0; i < nelem(h); i++)
		r += (h[i] & 1);
	return max(r - 1, 0);
}

int
main(void)
{
	assert(peragram("abc") == 2);
	assert(peragram("aab") == 0);

	return 0;
}

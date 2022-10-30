/*

You have a string of lowercase English alphabetic letters. You can perform two types of operations on the string:

   1. Append a lowercase English alphabetic letter to the end of the string.
   2. Delete the last character in the string. Performing this operation on an empty string results in an empty string.

Given an integer, k, and two strings, s and t, determine whether or not you can convert to by performing exactly of the above operations on s.
If it's possible, print Yes. Otherwise, print No.

For example, strings s="abc" and t="def". Our number of moves, k=6.
To convert s to t, we first delete all of the characters in moves. Next we add each of the characters of in order.
On the move, you will have the matching string. If there had been more moves available, they could have been eliminated by performing multiple deletions on an empty string.
If there were fewer than 6 moves, we would not have succeeded in creating the new string.

*/

#include <stdio.h>
#include <string.h>

const char *
convertable(const char *a, const char *b, size_t k)
{
	size_t i, l, m, n;

	m = strlen(a);
	n = strlen(b);

	// if string a can be deleted entirely and string b
	// can be appended in less than k operations, it is
	// obviously doable
	if (m + n <= k)
		return "Yes";

	// otherwise, we need to find the longest prefix
	// of string a and b, that part of the string
	// will not need to be modified
	for (i = 0; i < m && i < n; i++) {
		if (a[i] != b[i])
			break;
	}

	// subtract longest prefix and see if it is in divisible
	// by 2 since every operation that makes the letters match
	// needs an append and delete
	l = (m - i) + (n - i);
	if (k >= l && ((k - l) & 1) == 0)
		return "Yes";

	return "No";
}

int
main(void)
{
	printf("%s\n", convertable("hackerhappy", "hackerrank", 9));
	printf("%s\n", convertable("aba", "aba", 7));
	printf("%s\n", convertable("ashley", "ash", 2));
	printf("%s\n", convertable("abc", "def", 6));
	printf("%s\n", convertable("abc", "def", 5));
	return 0;
}

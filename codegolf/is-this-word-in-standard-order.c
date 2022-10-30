/*

Let A represent the alphabet, such that A[1]=a and A[26]= z.

Let's define that a word W=w1w2...wn (where wc∈A) is in standard order if and only if:

w[1]=A[1], and for 2≤i≤n, if w[i]=A[x] then w[j]=A[x−1] for some j<i and some x.
In other words, the word must start with a and each other letter can only appear in a word if the preceding letter in the alphabet has already appeared.
Equivalently, if we take only the first appearance of each unique letter in the word, the resulting word is a prefix of the alphabet.

For example, ac is not in standard order, because there is no b before the c.

The following relationships exist between the property of standard order and some others (this list is mainly here for searchability):

A word is a valid rhyme scheme if and only if it is in standard order (related challenge)
A word in standard order is the lexicographically earliest among all its isomorphs
The number of words of length n which are in standard order is the nth Bell number (related challenge)
Task
Given a string of letters, determine if it is in standard order according to the Latin alphabet.

Test cases
Truthy:

a
aaa
abab
aabcc
abacabadabacaba
abcdefghijklmnopqrstuvwxyzh
Falsey:

b
ac
bac
abbdc
bcdefghijklmnopqrstuvwxyza
abracadabra

Rules
You should represent true and false outputs using any two distinct values of your choice
You may assume the input is non-empty and only contains lowercase ASCII letters
Alternatively, you may accept input as a list of integers representing alphabet indices (in either [0,25] or [1,26], at your option)
You may use any standard I/O method
Standard loopholes are forbidden
This is code-golf, so the shortest code in bytes wins

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

typedef unsigned long ulong;

bool
standard(const char *s)
{
	ulong b, m, x;
	size_t i;
	int c;

	x = 0;
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]);
		if (!('a' <= c && c <= 'z'))
			return false;

		b = 1UL << (c - 'a');
		m = b - 1;
		if ((x & m) != m)
			return false;
		x |= b;
	}
	return true;
}

int
main(void)
{
	assert(standard("a") == true);
	assert(standard("aaa") == true);
	assert(standard("abab") == true);
	assert(standard("aabcc") == true);
	assert(standard("abacabadabacaba") == true);
	assert(standard("abcdefghijklmnopqrstuvwxyzh") == true);

	assert(standard("b") == false);
	assert(standard("ac") == false);
	assert(standard("bac") == false);
	assert(standard("abbdc") == false);
	assert(standard("bcdefghijklmnopqrstuvwxyza") == false);
	assert(standard("abracadabra") == false);

	return 0;
}

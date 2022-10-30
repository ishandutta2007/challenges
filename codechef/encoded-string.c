/*

An encoder encodes the first 16 lowercase English letters using 4 bits each.
The first bit (from the left) of the code is 0 if the letter lies among the first 8 letters, else it is 1, signifying that it lies among the last 8 letters.
The second bit of the code is 0 if the letter lies among the first 4 letters of those 8 letters found in the previous step, else it's 1, signifying that it lies among the last 4 letters of those 8 letters.
Similarly, the third and the fourth bit each signify the half in which the letter lies.

For example, the letter j would be encoded as :

Among (a,b,c,d,e,f,g,h | i,j,k,l,m,n,o,p), j appears in the second half. So the first bit of its encoding is 1.
Now, among (i,j,k,l | m,n,o,p), j appears in the first half. So the second bit of its encoding is 0.
Now, among (i,j | k,l), j appears in the first half. So the third bit of its encoding is 0.
Now, among (i | j), j appears in the second half. So the fourth and last bit of its encoding is 1.
So j's encoding is 1001,

Given a binary encoded string S, of length at most 105, decode the string.
That is, the first 4 bits are the encoding of the first letter of the secret message, the next 4 bits encode the second letter, and so on.
It is guaranteed that the string's length is a multiple of 4.

Input:

The first line of the input contains an integer T, denoting the number of test cases.
The first line of each test case contains an integer N, the length of the encoded string.
The second line of each test case contains the encoded string S.

Output:

For each test case, print the decoded string, in a separate line.

Constraints
1≤T≤10
4≤N≤10^5
The length of the encoded string is a multiple of 4.
0≤Si≤1

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
unpack(const char *s, char *b, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (s[i] == '\0')
			return 0;
		b[i] = s[i];
	}
	b[i] = '\0';

	return 1;
}

char *
encode(const char *s, char *b)
{
	size_t i, j;
	char p[8];

	for (i = j = 0; unpack(s + i, p, 4); i += 4)
		b[j++] = 'a' + strtoul(p, NULL, 2);
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[8];

	encode(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("0000", "a");
	test("00001111", "ap");
	test("1001", "j");

	return 0;
}

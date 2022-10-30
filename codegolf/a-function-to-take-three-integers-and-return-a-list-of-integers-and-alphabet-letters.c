/*

Challenge
We take three positive integers a, b, and c as input. Using these integers, first create a sequence in the range [0, c] (inclusive on both ends), in steps of b. For example, for a=4, b=2, c=100, the sequence would be [0,2,4,...,96,98,100].

For every number in this sequence which is divisible by a, replace it with the next letter in the lowercase alphabet, starting with the letter 'a' and wrapping back around to 'a' after you reach 'z'.

Example:
Input: a=4, b=2, c=100
Output: a2b6c10d14e18f22g26h30i34j38k42l46m50n54o58p62q66r70s74t78u82v86w90x94y98z

Challenge rules:
You can assume that a, b, and c are positive integers only, where b ≤ a ≤ c.
You can assume a is a multiple of b.
You can assume c is divisible by b.
The preferred output is a single concatenated string as above, but a list/array is acceptable as well.
Test cases:
Input: a=4, b=2, c=100
Output:
a2b6c10d14e18f22g26h30i34j38k42l46m50n54o58p62q66r70s74t78u82v86w90x94y98z

Input: a=9, b=3, c=174
Output:
a36b1215c2124d3033e3942f4851g5760h6669i7578j8487k9396l102105m111114n120123o129132p138141q147150r156159s165168t174

Input: a=10, b=2, c=50
Output:
a2468b12141618c22242628d32343638e42444648f

Input: a=25, b=1, c=25
Output:
a123456789101112131415161718192021222324b

Input: a=6, b=6, c=48
Output:
abcdefghi

Input: a=6, b=3, c=48
Output: a3b9c15d21e27f33g39h45i

Input: a=2, b=1, c=100
Output: a1b3c5d7e9f11g13h15i17j19k21l23m25n27o29p31q33r35s37t39u41v43w45x47y49z51a53b55c57d59e61f63g65h67i69j71k73l75m77n79o81p83q85r87s89t91u93v95w97x99y
I'd really like to see an answer in PHP, but this challenge is open to any language. This is codegolf, so the answer should be as short as possible. Standard rules apply for functions/programs and default loopholes are forbidden.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
step(int a, int b, int c, char *s)
{
	size_t l;
	int ch;
	int i;

	ch = 0;
	l = 0;
	for (i = 0; i <= c; i += b) {
		if (!(i % a)) {
			l += sprintf(s + l, "%c", ch + 'a');
			ch = (ch + 1) % 26;
		} else
			l += sprintf(s + l, "%d", i);
	}
	return s;
}

void
test(int a, int b, int c, const char *r)
{
	char s[256];

	step(a, b, c, s);
	printf("%s\n", s);
	assert(!strcmp(s, r));
}

int
main(void)
{
	test(4, 2, 100, "a2b6c10d14e18f22g26h30i34j38k42l46m50n54o58p62q66r70s74t78u82v86w90x94y98z");
	test(9, 3, 174, "a36b1215c2124d3033e3942f4851g5760h6669i7578j8487k9396l102105m111114n120123o129132p138141q147150r156159s165168t174");
	test(10, 2, 50, "a2468b12141618c22242628d32343638e42444648f");
	test(25, 1, 25, "a123456789101112131415161718192021222324b");
	test(6, 6, 48, "abcdefghi");
	test(6, 3, 48, "a3b9c15d21e27f33g39h45i");
	test(2, 1, 100, "a1b3c5d7e9f11g13h15i17j19k21l23m25n27o29p31q33r35s37t39u41v43w45x47y49z51a53b55c57d59e61f63g65h67i69j71k73l75m77n79o81p83q85r87s89t91u93v95w97x99y");

	return 0;
}

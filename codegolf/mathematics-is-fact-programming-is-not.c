/*

In mathematics an exclamation mark ! often means factorial and it comes after the argument.

In programming an exclamation mark ! often means negation and it comes before the argument.

For this challenge we'll only apply these operations to zero and one.

Factorial
0! = 1
1! = 1

Negation
!0 = 1
!1 = 0

Take a string of zero or more !'s, followed by 0 or 1, followed by zero or more !'s (!*[01]!*).
For example, the input may be !!!0!!!! or !!!1 or !0!! or 0! or 1.

The !'s before the 0 or 1 are negations and the !'s after are factorials.

Factorial has higher precedence than negation so factorials are always applied first.
For example, !!!0!!!! truly means !!!(0!!!!), or better yet !(!(!((((0!)!)!)!))).

Output the resultant application of all the factorials and negations. The output will always be 0 or 1.
Test Cases

0 -> 0
1 -> 1
0! -> 1
1! -> 1
!0 -> 1
!1 -> 0
!0! -> 0
!1! -> 0
0!! -> 1
1!! -> 1
!!0 -> 0
!!1 -> 1
!0!! -> 0
!!!1 -> 0
!!!0!!!! -> 0
!!!1!!!! -> 0

The shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>

int
fnp(const char *s)
{
	size_t i;
	int n, r;

	n = 0;
	for (i = 0; s[i] == '!'; i++)
		n = !n;

	if (s[i] == '0')
		r = 0;
	else if (s[i] == '1')
		r = 1;
	else
		return -1;

	for (i++; s[i] == '!'; i++)
		r = 1;

	if (s[i] != '\0')
		return -1;

	return (n) ? !r : r;
}

int
main(void)
{
	assert(fnp("0") == 0);
	assert(fnp("1") == 1);
	assert(fnp("0!") == 1);
	assert(fnp("1!") == 1);
	assert(fnp("!0") == 1);
	assert(fnp("!1") == 0);
	assert(fnp("!0!") == 0);
	assert(fnp("!1!") == 0);
	assert(fnp("0!!") == 1);
	assert(fnp("1!!") == 1);
	assert(fnp("!!0") == 0);
	assert(fnp("!!1") == 1);
	assert(fnp("!!0") == 0);
	assert(fnp("!!1") == 1);
	assert(fnp("!0!!") == 0);
	assert(fnp("!!!1") == 0);
	assert(fnp("!!!0!!!!") == 0);
	assert(fnp("!!!1!!!!") == 0);

	return 0;
}

/*

Chef is a really nice and respectful person, in sharp contrast to his little brother, who is a very nasty and disrespectful person.
Chef always sends messages to his friends in all small letters, whereas the little brother sends messages in all capital letters.

You just received a message given by a string s. You don't know whether this message is sent by Chef or his brother.
Also, the communication channel through which you received the message is erroneous and hence can flip a letter from uppercase to lowercase or vice versa.
However, you know that this channel can make at most K such flips.

Determine whether the message could have been sent only by Chef, only by the little brother, by both or by none.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K denoting the length of the string s and the maximum number of flips that the erroneous channel can make.
The second line contains a single string s denoting the message you received.

Output

For each test case, output a single line containing one string — "chef", "brother", "both" or "none".

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 100
0 ≤ K ≤ N
s consists only of (lowercase and uppercase) English letters

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
who(const char *s, size_t k)
{
	size_t x, y;
	size_t i;
	int f;

	x = y = 0;
	for (i = 0; s[i]; i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			x++;
		else
			y++;
	}

	f = 0;
	if (x <= k)
		f |= 1;
	if (y <= k)
		f |= 2;

	switch (f) {
	case 3:
		return "both";
	case 2:
		return "brother";
	case 1:
		return "chef";
	}
	return "none";
}

void
test(const char *s, size_t k, const char *r)
{
	const char *p;

	p = who(s, k);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("frauD", 1, "chef");
	test("FRAUD", 1, "brother");
	test("Life", 4, "both");
	test("sTRAWBerry", 4, "none");

	return 0;
}

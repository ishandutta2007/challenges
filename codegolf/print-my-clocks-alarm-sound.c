/*

Write the shortest program that prints the sound my alarm clock makes, and stops after an inputted number of beeps.

For reference, here is the sound my alarm makes:

beep beep beep beep beep beepbeep beepbeep beepbeep beepbeep beepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeep
Basically beep, beepbeep, beepbeepbeep, and beepbeepbeepbeep repeated 5 times each with spaces in between, followed by a beepbeep...beep which is 25 beeps long with no spaces in between (does beep still sound like a word to you?).

Your program should take a number as input (assume it's between 0 and 75), and stop printing after that many beeps.

Note: Your program should stop after that many beeps, not after that many groups of beeps. For example, 7 will return beep beep beep beep beep beepbeep.

Whitespace in between beeps must follow the exact pattern above, although any trailing whitespace or unsuppressable output from your compiler or interpreter is allowed.

Test cases:

3   beep beep beep
0
1   beep
7   beep beep beep beep beep beepbeep
8   beep beep beep beep beep beepbeep beep
55  beep beep beep beep beep beepbeep beepbeep beepbeep beepbeep beepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeepbeep
67  beep beep beep beep beep beepbeep beepbeep beepbeep beepbeep beepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeep
This is code golf, so the shortest answer in bytes, per language, wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
clamp(int x, int a, int b)
{
	if (x < a)
		return a;
	if (x > b)
		return b;
	return x;
}

char *
beep(int n, char *b)
{
	int i, j, k, l;
	char *p;

	n = clamp(n, 0, 75);
	p = b;
	j = 0;
	k = 1;
	l = 0;
	for (i = 0; i < n; i++) {
		p += sprintf(p, "beep");
		if (i + 1 < n && ++j >= k) {
			p += sprintf(p, " ");
			j = 0;
		}
		if (++l >= 5 * k) {
			k = (k != 4) ? k + 1 : 25;
			l = 0;
		}
	}
	*p = '\0';
	return b;
}

void
test(int n, const char *r)
{
	char b[1024];

	beep(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(3, "beep beep beep");
	test(0, "");
	test(1, "beep");
	test(7, "beep beep beep beep beep beepbeep");
	test(8, "beep beep beep beep beep beepbeep beep");
	test(55, "beep beep beep beep beep beepbeep beepbeep beepbeep beepbeep beepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeepbeep");
	test(67, "beep beep beep beep beep beepbeep beepbeep beepbeep beepbeep beepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeep");
	test(75, "beep beep beep beep beep beepbeep beepbeep beepbeep beepbeep beepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeep beepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeepbeep");

	return 0;
}

/*

When determining the age of a bull moose, the number of tines (sharp points), extending from the main antlers, can be used.
An older bull moose tends to have more tines than a younger moose.
However, just counting the number of tines can be misleading, as a moose can break off the tines, for example when fighting with other moose.
Therefore, a point system is used when describing the antlers of a bull moose.

The point system works like this: If the number of tines on the left side and the right side match, the moose is said to have the even sum of the number of points.
So, “an even 6-point moose”, would have three tines on each side.
If the moose has a different number of tines on the left and right side, the moose is said to have twice the highest number of tines, but it is odd.
So “an odd 10-point moose” would have 5 tines on one side, and 4 or less tines on the other side.

Can you figure out how many points a moose has, given the number of tines on the left and right side?

Input

The input contains a single line with two integers  and r, where 0≤ℓ≤20 is the number of tines on the left, and 0≤r≤20 is the number of tines on the right.

Output

Output a single line describing the moose. For even pointed moose, output “Even x” where x is the points of the moose.
For odd pointed moose, output “Odd x” where x is the points of the moose. If the moose has no tines, output “Not a moose”

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

char *
judge(int l, int r, char *b)
{
	int v;

	v = 2 * max(l, r);
	if (l == 0 && r == 0)
		sprintf(b, "Not a moose");
	else if (l == r)
		sprintf(b, "Even %d", v);
	else
		sprintf(b, "Odd %d", v);
	return b;
}

void
test(int l, int r, const char *p)
{
	char b[128];

	judge(l, r, b);
	printf("%s\n", b);
	assert(!strcmp(b, p));
}

int
main(void)
{
	test(2, 3, "Odd 6");
	test(3, 3, "Even 6");
	test(0, 0, "Not a moose");

	return 0;
}

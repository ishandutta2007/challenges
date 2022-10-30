/*

Chef has taken his first dose of vaccine D days ago. He may take the second dose no less than L days and no more than R days since his first dose.

Determine if Chef is too early, too late, or in the correct range for taking his second dose.

Input Format

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, three integers D,L,R.

Output Format

For each test case, print a single line containing one string -
"Too Early" (without quotes) if it's too early to take the vaccine,
"Too Late" (without quotes) if it's too late to take the vaccine,
"Take second dose now" (without quotes) if it's the correct time to take the vaccine.

Constraints
1≤T≤10^5
1≤D≤10^9
1≤L≤R≤10^9

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
timing(int d, int l, int r)
{
	if (d < l)
		return "Too Early";
	if (l <= d && d <= r)
		return "Take second dose now";
	return "Too Late";
}

void
test(int d, int l, int r, const char *s)
{
	const char *p;

	p = timing(d, l, r);
	printf("%s\n", p);
	assert(!strcmp(p, s));
}

int
main(void)
{
	test(10, 8, 12, "Take second dose now");
	test(14, 2, 10, "Too Late");
	test(4444, 5555, 6666, "Too Early");
	test(8, 8, 12, "Take second dose now");

	return 0;
}

/*

Chef prepared a problem. The admin has rated this problem for x points.

A problem is called :

1) Easy if 1≤x<100

2) Medium if 100≤x<200

3) Hard if 200≤x≤300

Find the category to which Chef’s problem belongs.

Input Format

The first line contains T denoting the number of test cases. Then the test cases follow.
The first and only line of each test case contains a single integer x.

Output Format

For each test case, output in a single line the category of Chef's problem, i.e whether it is an Easy, Medium or Hard problem. The output is case sensitive.

Constraints
1≤T≤50
1≤x≤300

*/

#include <assert.h>
#include <string.h>

const char *
hardness(int x)
{
	if (1 <= x && x < 100)
		return "Easy";
	if (100 <= x && x < 200)
		return "Medium";
	if (200 <= x && x <= 300)
		return "Hard";
	return "Invalid";
}

int
main(void)
{
	assert(!strcmp(hardness(50), "Easy"));
	assert(!strcmp(hardness(172), "Medium"));
	assert(!strcmp(hardness(201), "Hard"));

	return 0;
}

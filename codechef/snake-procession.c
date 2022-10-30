/*

The annual snake festival is upon us, and all the snakes of the kingdom have gathered to participate in the procession.
Chef has been tasked with reporting on the procession, and for this he decides to first keep track of all the snakes.
When he sees a snake first, it'll be its Head, and hence he will mark a 'H'. The snakes are long, and when he sees the snake finally slither away, he'll mark a 'T' to denote its tail.
In the time in between, when the snake is moving past him, or the time between one snake and the next snake, he marks with '.'s.

Because the snakes come in a procession, and one by one, a valid report would be something like "..H..T…HTH….T.", or "…", or "HT", whereas "T…H..H.T", "H..T..H", "H..H..T..T" would be invalid reports (See explanations at the bottom).

Formally, a snake is represented by a 'H' followed by some (possibly zero) '.'s, and then a 'T'.
A valid report is one such that it begins with a (possibly zero length) string of '.'s, and then some (possibly zero) snakes between which there can be some '.'s, and then finally ends with some (possibly zero) '.'s.

Chef had binged on the festival food and had been very drowsy. So his report might be invalid. You need to help him find out if his report is valid or not.

Input

The first line contains a single integer, R, which denotes the number of reports to be checked. The description of each report follows after this.
The first line of each report contains a single integer, L, the length of that report.
The second line of each report contains a string of length L. The string contains only the characters '.', 'H', and 'T'.

Output

For each report, output the string Valid or Invalid in a new line, depending on whether it was a valid report or not.

Constraints
1≤R≤500
1≤L≤500

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
valid(const char *s)
{
	size_t i;
	int h;

	h = 1;
	for (i = 0; s[i]; i++) {
		if (s[i] == '.')
			continue;
		if (h == 1 && s[i] == 'T')
			return false;
		if (h == 0 && s[i] == 'H')
			return false;
		h = !h;
	}
	return h != 0;
}

int
main(void)
{
	assert(valid("..H..T...HTH....T.") == true);
	assert(valid("...") == true);
	assert(valid("H..H..T..T") == false);
	assert(valid("HT") == true);
	assert(valid(".T...H..H.T") == false);
	assert(valid("H..T..H") == false);

	return 0;
}

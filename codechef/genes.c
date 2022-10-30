/*

People in Chefland have three different eye colors, namely brown, blue, and green. green is the rarest of the eye colors whereas brown is most common.

The eye color of the child of two people is most likely to be the most common eye color between them.

You are given two characters denoting the eye colors of two people in Chefland. The character R denotes bRown color, B denotes Blue color, and G denotes Green color.

Determine the most likely eye color of their child. (Print R, B or G denoting bRown, Blue or Green respectively).

Please see the sample test cases below for explained examples.

Input Format

The first (and only) line of input contains two space-separated characters, the eye colors of the parents.

Output Format

Print a single character denoting the most likely eye color of the child. (Print R, B or G denoting brown, blue or green respectively).

Constraints

The input contains two space-separated characters
Each character in the input is one among {R, B, G}.

*/

#include <assert.h>
#include <stdio.h>

int
eyecolor(int a, int b)
{
	if (a == 'R' || b == 'R')
		return 'R';
	if (a == 'B' || b == 'B')
		return 'B';
	return 'G';
}

int
main(void)
{
	assert(eyecolor('R', 'B') == 'R');
	assert(eyecolor('B', 'B') == 'B');
	assert(eyecolor('G', 'B') == 'B');
	assert(eyecolor('G', 'G') == 'G');

	return 0;
}

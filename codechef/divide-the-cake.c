/*

Problem description
Chef loves circular cakes. He divides them into smaller pieces and sells them. You are to help him in this work.

Today Chef has cooked the brand new circular cake. To split the cake Chef can make several (possibly, zero) cuts. Each cut should be a straight line going from the center of the cake to its border.
Also, the angle between any two cuts should have positive integer value (Chef measure all the angles in degrees). Chef consider two pieces of cake equal if the appropriate angles are equal.

The picture contains two distinct pieces, and two cuts. Red part on the image shows one piece. The appropriate angle is AOB.

Chef gives to you an integer N, denoting the number of pieces Chef wants to make. You need to answer the following questions:

Is it possible to make exactly N equal pieces from the whole cake?
Is it possible to make exactly N pieces from the whole cake?
Is it possible to make exactly N pieces from the whole cake, in such a way that no two of them are equal?

Input

First line contains a single integer T denoting the number of test cases.
Each of the following T lines contain a single integer N denoting the number of pieces Chef wants to make.

Output

For each test case, output one line containing 3 space separated characters.
Above, we defined the 3 questions that Chef will ask.
Output 'y' for yes or 'n' for no (quotes for clarity) for each of those questions.
Answers for 3 questions (in the order above) must be space separated on the same line.

Constraints
1 ≤ T ≤ 10000
1 ≤ N ≤ 10000

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
divisible(int n, char b[3])
{
	b[0] = (n && (360 % n) == 0) ? 'y' : 'n';
	b[1] = (n <= 360) ? 'y' : 'n';
	b[2] = (n <= 26) ? 'y' : 'n';
}

void
test(int n, char r[3])
{
	char b[3];

	divisible(n, b);
	printf("%c %c %c\n", b[0], b[1], b[2]);
	assert(!memcmp(r, b, sizeof(b)));
}

int
main(void)
{
	char r1[] = "yyy";
	char r2[] = "nyy";

	test(4, r1);
	test(7, r2);

	return 0;
}

/*

Mike is a famous traveler. He visits about 100 countries a year and buys the flag of each country he has been to.

Mike knows, that there are some flags, that correspond to one pattern, but colored in different ways. E.g. the flag of Ireland(link) and the flag of Belgium(link). In this problem we consider only five 2,2cm✕1,1cm patterns of flags:

e0a288110c029176f586f6eac23b4546.jpg

There are N different colors available to paint the flags and the colors are denoted by integers from 1 to N.
Mike wants you to count the number of different well-painted flags. We call a flag well-painted if it's made according to the following algorithm:

Pick up one of the flag patterns considered above;
Paint each one-colored polygon on the pattern in a color encoded by an integer from 1 to N.
Different colors are encoded with different integers. If two different one-colored polygons share a common side(not corner), than they must be painted in different colors.
In any other case they can be painted in both equal and different colors.
Two flags are different, if they look different(have at least one pixel painted with different color).

Help Mike!

Text version of the pictures:
Picture 1

112233

112233

112233

111111

222222

333333

112222

112222

113333

122223

111333

144443

111222

333222

333444

Picture 2

112211

112211

112211

221122

221122

221122

111111

222222

111111

222222

111111

222222

Input
The first line of the input contains integer T, denoting the number of testcases. The description of T testcases follows.
The only line of each test case contains integer N, denoting the number of different colors, that can be used while painting a flag pattern.

Output
For each testcase, output a single line containing an integer - the answer for the corresponding query.

Constraints
1 ≤ T ≤ 10 000;
1 ≤ N ≤ 10 000 for each testcase.

*/

#include <assert.h>

int
flags(int n)
{
	int n1, n2;
	int v;

	n1 = n - 1;
	n2 = n - 2;
	v = n * n1 * n1;
	v += n * n1 * n1;
	v += n * n1 * n2;
	v += n * n1 * n2 * n2;
	v += n * n1 * n2 * n2;
	return v;
}

int
main(void)
{
	assert(flags(1) == 0);
	assert(flags(2) == 4);
	assert(flags(3) == 42);

	return 0;
}

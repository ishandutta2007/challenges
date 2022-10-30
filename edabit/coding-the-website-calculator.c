/*

Imagine you run a website that presents users with different coding challenges in levels Easy, Medium, and Hard, where users get points for completing challenges. An Easy challenge is worth 5 points, a Medium challenge is worth 10 points, and a Hard challenge is worth 20 points.

Create a function that takes in the number of each challenge level a user has played and calculates the user's total number of points. Keep in mind that a user cannot complete negative challenges, so the function should return the string "invalid" if any of the passed parameters are negative.
Examples

scoreCalculator(1, 2, 3) ➞ 85

scoreCalculator(1, 0, 10) ➞ 205

scoreCalculator(5, 2, -6) ➞ "invalid"

*/

#include <assert.h>

int
score(int e, int m, int h)
{
	if (e < 0 || m < 0 || h < 0)
		return -1;

	return 5 * e + 10 * m + 20 * h;
}

int
main(void)
{
	assert(score(4, 2, 7) == 180);
	assert(score(3, 12, 0) == 135);
	assert(score(5, -5, 2) == -1);
	assert(score(20, 7, 3) == 230);
	assert(score(0, 0, 0) == 0);
	assert(score(1, 2, 3) == 85);

	return 0;
}

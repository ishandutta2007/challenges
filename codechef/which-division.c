/*

Given the rating R of a person, tell which division he belongs to. The rating range for each division are given below:

Division 1: 2000≤ Rating.
Division 2: 1600≤ Rating <2000.
Division 3: Rating <1600.

Input Format

The first line of the input contains T - the number of test cases. Then the test cases follow.
Each testcase contains a single line of input, which contains a single integer R.

Output Format

For each test case, output on a single line the answer: 1 if the person belongs to Division 1, 2 if the person belongs to Division 2, and 3 if the person belongs to Division 3.

Constraints
1≤T≤1000
1000≤R≤4500

*/

#include <assert.h>

int
division(int r)
{
	if (r < 1600)
		return 3;
	if (r < 2000)
		return 2;
	return 1;
}

int
main(void)
{
	assert(division(1500) == 3);
	assert(division(4000) == 1);
	assert(division(1900) == 2);

	return 0;
}

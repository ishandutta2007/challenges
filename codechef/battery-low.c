/*

Chef's phone shows a Battery Low notification if the battery level is 15% or less.

Given that the battery level of Chef's phone is X%, determine whether it would show a Battery low notification.

Input Format

First line will contain T, number of test cases. Then the test cases follow.
Each test case contains a single line of input, an integer X, denoting the battery level of the phone.

Output Format

For each test case, output in a single line Yes, if the battery level is 15% or below. Otherwise, print No.

You may print each character of Yes and No in uppercase or lowercase (for example, YeS, YES, yes will be considered identical).

Constraints
1≤T≤100
1≤X≤100
Subtasks
Subtask #1 (100 points): original constraints

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
low(unsigned l)
{
	return l <= 15;
}

int
main(void)
{
	assert(low(15) == true);
	assert(low(3) == true);
	assert(low(65) == false);

	return 0;
}

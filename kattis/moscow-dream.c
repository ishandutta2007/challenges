/*

For many students, getting a ticket to The ICPC World Finals is a huge achievement, and The 2019 ICPC Asia Danang Regional Contest is a chance to make their dream come true.
For some others, they just like to stretch their brains and solve interesting problems.

We – the scientific committee understand that, and we tried our best to set up a problemset that is interesting and diverse in both topics and difficulty.
For a few months, we called for problem proposals from many people and received a easy problems, b medium problems and c hard problems. Using these proposals, we want to create a problemset which:

    Consists of exactly n problems,

    Has at least 1 easy problem,

    Has at least 1 medium problem,

    Has at least 1 hard problem.

Your task is to check whether it is possible to create such a problemset using the available problems.

Input

The input contains 4 integers a, b, c and n (0≤a,b,c≤10,1≤n≤20).

Output

Print ‘YES’ if it is possible to create a problemset satisfying above requirements, and ‘NO’ otherwise.

Explanation of sample data


In the first sample, the committee do not have any easy problem. Thus, they cannot create a problemset with at least 1 easy problem.
In the second sample, the committee can use 3 easy problems, 7 medium problems and 3 hard problems to create a problemset with exactly 13 problems.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
dreamable(int a, int b, int c, int n)
{
	if (a <= 0 || b <= 0 || c <= 0 || (a + b + c) < n)
		return "NO";
	return "YES";
}

int
main(void)
{
	assert(!strcmp(dreamable(0, 3, 3, 5), "NO"));
	assert(!strcmp(dreamable(4, 10, 6, 13), "YES"));
	return 0;
}

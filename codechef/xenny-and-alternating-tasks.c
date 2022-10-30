/*

Xenny and Yana were very keen to celebrate Valentine's Day at their home. To make preparations for the celebration, they listed down N tasks that they had to complete.

To complete the ith task, Xenny takes Xi seconds and Yana takes Yi seconds. In order to minimize the disparity in tasks performed, they decide to do the tasks alternatingly.
If Xenny did the 1st task, then Yana would just wait and watch him until he completes the task. After that, Yana would start the 2nd task, and while she does her task, Xenny would just watch her.
He would start the 3rd task only after her completion, and they would keep doing tasks alternatingly uptil the Nth task. They could also do tasks in the other order - that is, Yana could do the 1st task, after that Xenny could do the 2nd task, and so on.
Their eventual goal was to minimize the total time taken by them to complete all N tasks.

Please help them find the minimum total time they would take to complete all N tasks.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each testcase contains a positive integer N - the number of tasks to be completed.

The second line contains N space-separated positive integers representing the time taken in seconds by Xenny to complete the ith task.

The third line contains N space-separated positive integers representing the time taken in seconds by Yana to complete the ith task.

Output

For each testcase, print a single line containing the minimum total time in seconds Xenny and Yana would take to complete the tasks.

Constraints

Subtask 1: 40 points

1 ≤ T ≤ 10
1 ≤ N ≤ 3
1 ≤ Xi, Yi ≤ 10^5
Subtask 2: 60 points

1 ≤ T ≤ 10
1 ≤ N ≤ 2*10^4
1 ≤ Xi, Yi ≤ 10^5

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
mintime(int *a, int *b, size_t n)
{
	int x[2], y[2];
	size_t i;

	x[0] = x[1] = 0;
	y[0] = y[1] = 0;
	for (i = 0; i < n; i++) {
		x[i & 1] += a[i];
		y[i & 1] += b[i];
	}
	return min(x[1] + y[0], x[0] + y[1]);
}

int
main(void)
{
	int a1[] = {2, 1, 2};
	int b1[] = {3, 2, 1};

	assert(mintime(a1, b1, nelem(a1)) == 5);

	return 0;
}

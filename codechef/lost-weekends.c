/*

Chef recently started working at ABC corporation. Let's number weekdays (Monday through Friday) by integers 1 through 5.
For each valid i, the number of hours Chef spent working at the office on weekday i was Ai.

Unfortunately, due to the COVID-19 pandemic, Chef started working from home and his productivity decreased by a considerable amount.
As per Chef's analysis, 1 hour of work done at the office is equivalent to P hours of work done at home.

Now, in order to complete his work properly, Chef has to spend more hours working from home, possibly at the cost of other things like sleep.
However, he does not have to do the same work on each day as he would have in the office ― for each weekday, he can start the work for this day on an earlier day and/or complete it on a later day.
The only requirement is that his work does not pile up indefinitely, i.e. he can complete his work for each week during the same week. One day has 24 hours.

If Chef is unable to complete his work for a week during those five weekdays, then he has to work during the weekend too.
Chef wishes to know whether he has to work on weekends or if he can complete his work by working only on weekdays.
Help him answer that question. (It is possible that Chef would be unable to finish his work even if he worked all the time, but he does not want to know about that.)

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains six space-separated integers A1, A2, A3, A4, A5 and P.

Output

For each test case, print a single line containing the string "Yes" if Chef has to work on weekends or "No" otherwise (without quotes).

Constraints
1≤T≤1,000
0≤Ai≤24 for each valid i
1≤P≤24

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
weekends(int a[6])
{
	size_t i;
	int c, p;

	p = a[5];
	c = 0;
	for (i = 0; i < 5; i++)
		c += a[i];
	c *= p;

	return c > 120;
}

int
main(void)
{
	int a1[] = {14, 10, 12, 6, 18, 2};
	int a2[] = {10, 10, 10, 10, 10, 3};

	assert(weekends(a1) == false);
	assert(weekends(a2) == true);

	return 0;
}

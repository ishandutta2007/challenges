/*

Professor Zac is trying to finish a collection of tasks during the first week at the start of the term. He knows precisely how long each task will take, down to the millisecond.
Unfortunately, it is also Frosh Week. Zac’s office window has a clear view of the stage where loud music is played. He cannot focus on any task when music is blaring.

The event organizers are also very precise. They supply Zac with intervals of time when music will not be playing. These intervals are specified by their start and end times down to the millisecond.

Each task that Zac completes must be completed in one quiet interval. He cannot pause working on a task when music plays (he loses his train of thought).
Interestingly, the lengths of the tasks and quiet intervals are such that it is impossible to finish more than one task per quiet interval!

Given a list of times ti (in milliseconds) that each task will take and a list of times ℓj (in milliseconds) specifying the lengths of the intervals when no music is being played, what is the maximum number of tasks that Zac can complete?

Input

The first line of input contains a pair of integers n and m, where n is the number of tasks and m is the number of time intervals when no music is played.
The second line consists of a list of integers t1,t2,…,tn indicating the length of time of each task. The final line consists of a list of times ℓ1,ℓ2,…,ℓm indicating the length of time of each quiet interval when Zac is at work this week.

You may assume that 1≤n,m≤200000 and 100000≤ti,ℓj≤199999 for each task i and each quiet interval j.

Output

Output consists of a single line containing a single integer indicating the number of tasks that Zac can accomplish from his list during this first week.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	long x, y;

	x = *(long *)a;
	y = *(long *)b;
	if (x > y)
		return -1;
	if (x < y)
		return 1;
	return 0;
}

size_t
tasks(long *t, long *l, size_t n, size_t m)
{
	size_t i, j;

	qsort(t, n, sizeof(*t), cmp);
	qsort(l, m, sizeof(*l), cmp);
	for (i = j = 0; i < n && j < m; i++) {
		if (t[i] <= l[j])
			j++;
	}
	return j;
}

int
main(void)
{
	long t1[] = {150000L, 100000L, 160000L, 100000L, 180000L};
	long l1[] = {190000L, 170000L, 140000L, 160000L};

	long t2[] = {180000L, 185000L, 199999L, 100000L};
	long l2[] = {199999L, 180000L, 170000L, 120000L};

	long t3[] = {199999L, 180000L, 170001L};
	long l3[] = {199999L, 170000L, 180000L};

	assert(tasks(t1, l1, nelem(t1), nelem(l1)) == 4);
	assert(tasks(t2, l2, nelem(t2), nelem(l2)) == 3);
	assert(tasks(t3, l3, nelem(t3), nelem(l3)) == 2);

	return 0;
}

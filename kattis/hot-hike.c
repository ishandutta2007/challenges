/*

In order to pass time during your vacation, you decided to go on a hike to visit a scenic lake up in the mountains.
Hiking to the lake will take you a full day, then you will stay there for a day to rest and enjoy the scenery, and then spend another day hiking home, for a total of three days.
However, the accursed weather this summer is ridiculously warm and sunny, and since severe dehydration is not at the top of your priority list you want to schedule the three-day trip during some days where the two hiking days are the least warm.
In particular you want to minimize the maximum temperature during the two hiking days.

Given the current forecast of daily maximum temperatures during your vacation, what are the best days for your trip?

Input

The first line of input contains an integer n (3≤n≤50), the length of your vacation in days.
Then follows a line containing n integers t1,t2,…,tn (−20≤ti≤40), where ti is the temperature forecast for the i’th day of your vacation.

Output

Output two integers d and t, where d is the best day to start your trip, and t is the resulting maximum temperature during the two hiking days.
If there are many choices of d that minimize the value of t, then output the smallest such d.


*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
best(int *a, size_t n, size_t *d, int *t)
{
	size_t i;
	int v;

	*d = 0;
	*t = INT_MAX;
	for (i = 2; i < n; i++) {
		v = max(a[i], a[i - 2]);
		if (*t > v) {
			*t = v;
			*d = i - 1;
		}
	}
}

void
test(int *a, size_t n, size_t rd, int rt)
{
	size_t d;
	int t;

	best(a, n, &d, &t);
	printf("%zu %d\n", d, t);
	assert(d == rd);
	assert(t == rt);
}

int
main(void)
{
	int a1[] = {23, 27, 31, 28, 30};
	int a2[] = {30, 20, 20, 30};

	test(a1, nelem(a1), 2, 28);
	test(a2, nelem(a2), 1, 30);

	return 0;
}

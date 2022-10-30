/*

Pero has negotiated a Very Good data plan with his internet provider. The provider will let Pero use up X megabytes to surf the internet per month.
Each megabyte that he doesn’t spend in that month gets transferred to the next month and can still be spent. Of course, Pero can only spend the megabytes he actually has.

If we know how much megabytes Pero has spent in each of the first N
months of using the plan, determine how many megabytes Pero will have available in the N+1 month of using the plan.

Input

The first line of input contains the integer X (1≤X≤100).
The second line of input contains the integer N (1≤N≤100).
Each of the following N lines contains an integer Pi (0≤Pi≤10000), the number of megabytes spent in each of the first N months of using the plan.
Numbers Pi will be such that Pero will never use more megabytes than he actually has.

Output

The first and only line of output must contain the required value from the task.
Sample Input 1 	Sample Output 1

10
3
4
6
2

28

Sample Input 2 	Sample Output 2

10
3
10
2
12

16

Sample Input 3 	Sample Output 3

15
3
15
10
20

15

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
leftover(int x, int *p, size_t n)
{
	size_t i;
	int t;

	t = x * (n + 1);
	for (i = 0; i < n; i++)
		t -= p[i];
	return t;
}

int
main(void)
{
	int p1[] = {4, 6, 2};
	int p2[] = {10, 2, 12};
	int p3[] = {15, 10, 20};

	assert(leftover(10, p1, nelem(p1)) == 28);
	assert(leftover(10, p2, nelem(p2)) == 16);
	assert(leftover(15, p3, nelem(p3)) == 15);

	return 0;
}

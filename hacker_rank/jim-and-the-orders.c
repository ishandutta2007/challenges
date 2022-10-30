/*

Jim's Burgers has a line of hungry customers. Orders vary in the time it takes to prepare them.
Determine the order the customers receive their orders. Start by numbering each of the customers from 1 to n,
front of the line to the back. You will then be given an order number and a preparation time for each customer.

The time of delivery is calculated as the sum of the order number and the preparation time.
If two orders are delivered at the same time, assume they are delivered in ascending customer number order.

For example, there are n=5 customers in line. They each receive an order number order[i] and a preparation time prep[i]


Customer	1	2	3	4	5
Order #		8	5	6	2	4
Prep time	3	6	2	3	3
Calculate:
Serve time	11	11	8	5	7
We see that the orders are delivered to customers in the following order:

Order by:
Serve time	5	7	8	11	11
Customer	4	5	3	1	2

Print a single line of  space-separated customer numbers (recall that customers are numbered from 1 to n)
that describes the sequence in which the customers receive their burgers.
If two or more customers receive their burgers at the same time, print their numbers in ascending order.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const int *x, *y;

	x = a;
	y = b;
	if (x[1] < y[1])
		return -1;
	if (x[1] == y[1] && x[0] < y[0])
		return -1;
	return 1;
}

int *
orders(int a[][2], size_t n)
{
	size_t i;
	int *p;

	p = calloc(n, sizeof(int) * 2);
	if (p == NULL)
		return NULL;

	for (i = 0; i < n; i++) {
		p[i * 2] = i + 1;
		p[i * 2 + 1] = a[i][0] + a[i][1];
	}
	qsort(p, n, sizeof(int) * 2, cmp);

	for (i = 0; i < n; i++) {
		p[i] = p[i * 2];
		printf("%d\n", p[i]);
	}
	printf("\n");

	return p;
}

int
main(void)
{
	int a[][2] = {
	    {8, 3},
	    {5, 6},
	    {6, 2},
	    {2, 3},
	    {4, 3},
	};
	free(orders(a, nelem(a)));

	int b[][2] = {
	    {1, 3},
	    {2, 3},
	    {3, 3},
	};
	free(orders(b, nelem(b)));

	int c[][2] = {
	    {8, 1},
	    {4, 2},
	    {5, 6},
	    {3, 1},
	    {4, 3},
	};
	free(orders(c, nelem(c)));

	int d[][2] = {
	    {3, 50},
	};
	free(orders(d, nelem(d)));

	return 0;
}

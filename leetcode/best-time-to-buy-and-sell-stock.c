/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

*/
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxprofit(int *a, size_t n)
{
	size_t i;
	int m, v;

	m = 0;
	v = INT_MAX;
	for (i = 0; i < n; i++) {
		v = min(v, a[i]);
		if (a[i] > v)
			m = max(m, a[i] - v);
	}
	return m;
}

int
main(void)
{
	int a[] = {7, 1, 5, 3, 6, 4};
	printf("%d\n", maxprofit(a, nelem(a)));

	int b[] = {7, 6, 4, 3, 1};
	printf("%d\n", maxprofit(b, nelem(b)));

	return 0;
}

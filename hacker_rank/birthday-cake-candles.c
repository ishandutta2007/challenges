/*

You are in charge of the cake for your niece's birthday and have decided
the cake will have one candle for each year of her total age.
When she blows out the candles, she’ll only be able to blow out the tallest ones.
Your task is to find out how many candles she can successfully blow out.

For example, if your niece is turning 4 years old, and the cake will have  candles of height 4, 4, 3, 1, 3
she will be able to blow out  candles successfully, since the tallest candles are of height 4 and there are 2 such candles.

*/

#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
candles(int *a, size_t n)
{
	size_t c;
	int i, m;

	m = INT_MIN;
	c = 0;
	for (i = 0; i < n; i++) {
		if (m < a[i]) {
			m = a[i];
			c = 1;
		} else if (m == a[i])
			c++;
	}

	return c;
}

int
main(void)
{
	int a1[] = {4, 4, 1, 3};
	printf("%zu\n", candles(a1, nelem(a1)));

	int a2[] = {3, 2, 1, 3};
	printf("%zu\n", candles(a2, nelem(a2)));

	int a3[] = {11, 9, 9, 9, 9, 9, 11, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	printf("%zu\n", candles(a3, nelem(a3)));

	return 0;
}

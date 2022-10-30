/*

Your program will be given an integer X. Find the smallest number larger than X consisting of the same digits as X.

Input

The first line of input contains the integer X (1≤X≤999999). The first digit in X will not be a zero.

Output

Output the result on a single line. If there is no such number, output 0.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void
swap(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

unsigned long
nln(unsigned long x)
{
	char b[sizeof(x) * CHAR_BIT];
	int i, j, k, n;

	n = snprintf(b, sizeof(b), "%lu", x);

	i = n - 1;
	while (i > 0 && b[i - 1] >= b[i])
		i--;
	if (i <= 0)
		return 0;

	j = n - 1;
	while (b[j] <= b[i - 1])
		j--;
	swap(b + i - 1, b + j);

	for (k = n - 1; i < k; i++, k--)
		swap(b + i, b + k);

	return strtoul(b, NULL, 10);
}

int
main(void)
{
	assert(nln(156) == 165);
	assert(nln(330) == 0);
	assert(nln(27711ul) == 71127ul);
	assert(nln(1111) == 0);

	return 0;
}

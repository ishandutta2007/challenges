/*

I have a habit of asking for discounts when I'm buying something. Before you rush to call me a miser,
let me tell you that I only ask for discounts if I have to pay at least 10 Rs,
since asking for a discount on something that can be paid with just a few coins is really rude.

One day, I was supposed to pay N Rs, but the shopkeeper gave me an unusual offer - he told me that I can remove one of the digits in the decimal representation of N and pay only the resulting price.
I am trying to figure out the minimum price I have to pay if I choose the digit to remove optimally. Would you help me, please?

Note that the resulting number after removing digit is allowed to have leading zeros. But while outputting the answer, there should be no leading zeros.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output

For each test case, print a single line containing one integer - the minimum price I have to pay.

Constraints
1≤T≤10^5
10≤N≤10^9

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned
price(unsigned v)
{
	char a[256], b[256];
	size_t i, j, k, n;

	n = snprintf(a, sizeof(a), "%u", v);
	if (n == 0)
		return 0;

	for (i = k = 0; i < n - 1; i++, k++) {
		if (a[i] > a[i + 1])
			break;
		b[k] = a[i];
	}

	for (j = i + 1; j < n; j++, k++)
		b[k] = a[j];

	return strtoul(b, NULL, 10);
}

int
main(void)
{
	assert(price(21) == 1);
	assert(price(132) == 12);
	assert(price(104) == 4);

	return 0;
}

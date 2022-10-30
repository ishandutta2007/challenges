/*

Anna and Brian are sharing a meal at a restuarant and they agree to split the bill equally. Brian wants to order something that Anna is allergic to though, and they agree that Anna won't pay for that item. Brian gets the check and calculates Anna's portion. You must determine if his calculation is correct.

For example, assume the bill has the following prices:
bill=[2, 4, 6]. Anna declines to eat item which costs k=bill[2]. If Brian calculates the bill correctly, Anna will pay (2+4)/2 = 3. If he includes the cost of bill[2] he will calculate (2+4+6)/2=6. In the second case, he should refund 3 to Anna.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
bill(int *a, size_t n, size_t k, int b)
{
	size_t i;
	int t;

	if (k >= n || b <= 0 || n < 2)
		return;

	t = 0;
	for (i = 0; i < n; i++) {
		if (i != k)
			t += a[i];
	}
	t /= 2;
	if (t == b)
		printf("Bon Appetit\n");
	else
		printf("%d\n", b - t);
}

int
main(void)
{
	int a[] = {2, 4, 6};
	bill(a, nelem(a), 2, 3);
	bill(a, nelem(a), 2, 6);

	int b[] = {3, 10, 2, 9};
	bill(b, nelem(b), 1, 12);
	bill(b, nelem(b), 1, 7);
	return 0;
}

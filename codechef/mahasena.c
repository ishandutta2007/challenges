/*

Kattapa, as you all know was one of the greatest warriors of his time.
The kingdom of Maahishmati had never lost a battle under him (as army-chief), and the reason for that was their really powerful army, also called as Mahasena.

Kattapa was known to be a very superstitious person. He believed that a soldier is "lucky" if the soldier is holding an even number of weapons, and "unlucky" otherwise.
He considered the army as "READY FOR BATTLE" if the count of "lucky" soldiers is strictly greater than the count of "unlucky" soldiers, and "NOT READY" otherwise.

Given the number of weapons each soldier is holding, your task is to determine whether the army formed by all these soldiers is "READY FOR BATTLE" or "NOT READY".

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
readiness(int *a, size_t n)
{
	size_t i, l, nl;

	l = nl = 0;
	for (i = 0; i < n; i++) {
		if (!(a[i] & 1))
			l++;
		else
			nl++;
	}
	return (l > nl) ? "READY FOR BATTLE" : "NOT READY";
}

int
main(void)
{
	int a[] = {1};
	printf("%s\n", readiness(a, nelem(a)));

	int b[] = {2};
	printf("%s\n", readiness(b, nelem(b)));

	int c[] = {11, 12, 13, 14};
	printf("%s\n", readiness(c, nelem(c)));

	int d[] = {2, 3, 4};
	printf("%s\n", readiness(d, nelem(d)));

	int e[] = {1, 2, 3, 4, 5};
	printf("%s\n", readiness(e, nelem(e)));

	return 0;
}

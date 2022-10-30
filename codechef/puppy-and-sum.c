/*

Yesterday, puppy Tuzik learned a magically efficient method to find the sum of the integers from 1 to N.
He denotes it as sum(N). But today, as a true explorer, he defined his own new function: sum(D, N),
which means the operation sum applied D times: the first time to N, and each subsequent time to the result of the previous operation.

For example, if D = 2 and N = 3, then sum(2, 3) equals to sum(sum(3)) = sum(1 + 2 + 3) = sum(6) = 21.

Tuzik wants to calculate some values of the sum(D, N) function. Will you help him with that?

*/
#include <stdio.h>

int
sum(int d, int n)
{
	int i;

	if (d <= 0)
		return 0;

	for (i = 0; i < d; i++)
		n = n * (n + 1) / 2;
	return n;
}

int
main(void)
{
	printf("%d\n", sum(1, 4));
	printf("%d\n", sum(2, 3));
	printf("%d\n", sum(3, 4));
	printf("%d\n", sum(4, 4));
	return 0;
}

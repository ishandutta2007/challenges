/*

Take an array of integers and partition it so that all the even integers in the array precede all the odd integers in the array.
Your solution must take linear time in the size of the array and operate in-place with only a constant amount of extra space.

Your task is to write the indicated function.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

void
paritysort(int *a, size_t n)
{
	size_t i, j;

	if (n == 0)
		return;

	i = 0;
	j = n - 1;
	while (i < j) {
		while (!(a[i] & 1) && i < j)
			i++;

		while ((a[j] & 1) && i < j)
			j--;

		if (i < j)
			swap(&a[i], &a[j]);
	}
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
test(int *a, size_t n)
{
	paritysort(a, n);
	print(a, n);
}

int
main(void)
{
	int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a2[] = {3, 5, 7, 9, 2};

	test(a1, nelem(a1));
	test(a2, nelem(a2));

	return 0;
}

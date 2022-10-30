// reverse array
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
reverse(int *a, size_t n)
{
	size_t i, j;
	int t;

	for (i = 0; i < n / 2; i++) {
		j = n - 1 - i;
		t = a[j];
		a[j] = a[i];
		a[i] = t;
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
	size_t i;

	print(a, n);
	for (i = 0; i < 2; i++) {
		reverse(a, n);
		print(a, n);
	}
	printf("\n");
}

int
main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	test(a, nelem(a));

	int b[] = {1};
	test(b, nelem(b));

	int c[] = {4, 536, 32, 13, 4535, 467, 353, 2, 243546, 1};
	test(c, nelem(c));

	return 0;
}

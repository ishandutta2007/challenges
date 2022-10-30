#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
bubblesort(int *a, size_t n)
{
	size_t i, m;
	int t;

	while (n > 1) {
		m = 0;
		for (i = 1; i <= n - 1; i++) {
			if (a[i - 1] > a[i]) {
				t = a[i];
				a[i] = a[i - 1];
				a[i - 1] = t;
				m = i;
			}
		}
		n = m;
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

int
main(void)
{
	int a[] = {10, 3, 4, 1, 5, 8, 100};
	bubblesort(a, nelem(a));
	print(a, nelem(a));

	int b[] = {-1, -2, -3, -4, -5, -6, -7};
	bubblesort(b, nelem(b));
	print(b, nelem(b));

	int c[] = {1};
	bubblesort(c, nelem(c));
	print(c, nelem(c));

	return 0;
}

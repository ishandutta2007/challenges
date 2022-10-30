// implement insertion sort and print out array at every step
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
insertion(int *a, size_t n, void (*step)(int *, size_t))
{
	size_t i, j;
	int t;

	for (i = 1; i < n; i++) {
		for (j = i; j > 0 && a[j - 1] > a[j]; j--) {
			t = a[j - 1];
			a[j - 1] = a[j];
			a[j] = t;
		}
		if (step)
			step(a, n);
	}
}

int
main(void)
{
	int a[] = {1, 4, 3, 5, 6, 2};
	insertion(a, nelem(a), print);
	return 0;
}

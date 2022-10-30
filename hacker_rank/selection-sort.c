// https://en.wikipedia.org/wiki/Selection_sort
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
selection(int *a, size_t n)
{
	size_t i, j, k;
	int t;

	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (a[k] > a[j])
				k = j;
		}

		if (k != i) {
			t = a[k];
			a[k] = a[i];
			a[i] = t;
		}
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
	int a[] = {94, 536, 46, 72, 14, 3546, 4657, 5753, 2424};
	selection(a, nelem(a));
	print(a, nelem(a));
	return 0;
}

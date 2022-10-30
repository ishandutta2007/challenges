#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
permute(size_t n, int a[n])
{
	size_t i, j;
	int t;

	if (n == 0)
		return;

	for (i = 0; i < n; i++)
		a[i] = i;

	for (i = n - 1; i >= 1; i--) {
		j = rand() % i;
		t = a[j];
		a[j] = a[i];
		a[i] = t;
	}
}

void
countsort(size_t n, int a[n], int b[n])
{
	int c[n], o, t;
	size_t i;

	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++)
		c[a[i]]++;

	t = 0;
	for (i = 0; i < n; i++) {
		o = c[i];
		c[i] = t;
		t += o;
	}

	for (i = 0; i < n; i++) {
		b[c[a[i]]] = a[i];
		c[a[i]]++;
	}
}

void
test(size_t n)
{
	int a[n], b[n];
	size_t i;

	permute(n, a);
	countsort(n, a, b);
	for (i = 0; i < n; i++)
		printf("%d %d\n", a[i], b[i]);
	printf("\n");
}

int
main(void)
{
	srand(time(NULL));

	test(10);
	test(32);
	return 0;
}

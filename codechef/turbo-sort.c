// sort number in ascending order
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
sort(int *a, size_t n)
{
	size_t i;
	qsort(a, n, sizeof(*a), cmp);
	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);
}

int *
randv(size_t n)
{
	size_t i;
	int *p;

	p = malloc(sizeof(*p) * n);
	if (p == NULL)
		return NULL;
	for (i = 0; i < n; i++)
		p[i] = rand();
	return p;
}

int
main(void)
{
	srand(time(NULL));

	int a[] = {5, 3, 6, 7, 1};
	sort(a, nelem(a));

	size_t n = 1000000;
	int *b = randv(n);
	sort(b, n);

	return 0;
}

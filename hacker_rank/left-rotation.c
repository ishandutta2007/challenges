// left rotation shifts array element 1 unit to the left
// given an array of n integers, perform d rotations on the array
// then print it out
#include <stdio.h>
#include <string.h>

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
lrt_slow(int *a, size_t n, size_t d)
{
	size_t i;
	int t;

	if (n == 0)
		return;

	d %= n;
	for (i = 0; i < d; i++) {
		t = a[0];
		memmove(a, a + 1, sizeof(int) * (n - 1));
		a[n - 1] = t;
	}
}

void
rev(int *a, size_t s, size_t e)
{
	size_t i, m;
	int t;

	m = (s + e) / 2;
	for (i = s; i <= m; i++) {
		t = a[i];
		a[i] = a[e - i + s];
		a[e - i + s] = t;
	}
}

void
lrt(int *a, size_t n, size_t d)
{
	size_t i;

	if (n == 0)
		return;

	d %= n;
	if (d == 0)
		return;

	i = n - 1 - d;
	rev(a, 0, n - 1);
	rev(a, 0, i);
	rev(a, i + 1, n - 1);
}

void
test(int *a, size_t n, size_t d)
{
	int b[n];

	memmove(b, a, sizeof(b));
	lrt_slow(b, n, d);
	print(b, nelem(b));

	memmove(b, a, sizeof(b));
	lrt(b, n, d);
	print(b, nelem(b));

	printf("\n");
}

int
main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	test(a, nelem(a), 2);
	test(a, nelem(a), 4);
	test(a, nelem(a), 1337);
	test(a, nelem(a), 1335);
	test(a, 1, 1000);
	test(a, 0, 2000);
	return 0;
}

/*

John Watson knows of an operation called a right circular rotation on an array of integers.
One rotation operation moves the last array element to the first position and shifts all remaining elements right one.
To test Sherlock's abilities, Watson provides Sherlock with an array of integers.
Sherlock is to perform the rotation operation a number of times then determine the value of the element at a given position.

*/

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
rrt_slow(int *a, size_t n, size_t d)
{
	size_t i;
	int t;

	if (n == 0)
		return;

	d %= n;
	for (i = 0; i < d; i++) {
		t = a[n - 1];
		memmove(a + 1, a, sizeof(*a) * (n - 1));
		a[0] = t;
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
rrt(int *a, size_t n, size_t d)
{
	size_t i;

	if (n == 0)
		return;

	d %= n;
	if (d == 0)
		return;

	rev(a, 0, n - 1);
	rev(a, 0, d - 1);
	rev(a, d, n - 1);
}

void
test(int *a, size_t n, size_t d)
{
	int b[n];

	memmove(b, a, sizeof(b));
	rrt_slow(b, n, d);
	print(b, nelem(b));

	memmove(b, a, sizeof(b));
	rrt(b, n, d);
	print(b, nelem(b));

	printf("\n");
}

int
main(void)
{
	int a[] = {1, 2, 3};
	size_t i;
	for (i = 0; i <= 100; i++)
		test(a, nelem(a), i);

	int b[] = {3, 4, 5};
	test(b, nelem(b), 2);

	return 0;
}

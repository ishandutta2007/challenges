/*

Consider a function f: X -> X where X is any set, and f is a bijection

Now, if f = f^-1, then f is called an involution.
In other words, a function is an involution if f(f(x)) = x

In this task, you're given a permutation f: {1, 2, 3, ..., n} -> {1, 2, 3, ..., n}

Determine whether f is an involution or not

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
involution(int *a, size_t n)
{
	size_t i;
	for (i = 0; i < n; i++) {
		if (!(1 <= a[i] && a[i] <= n))
			return "NO";
		if (a[a[i] - 1] != i + 1)
			return "NO";
	}
	return "YES";
}

int
main(void)
{
	int a[] = {2, 1};
	printf("%s\n", involution(a, nelem(a)));
	return 0;
}

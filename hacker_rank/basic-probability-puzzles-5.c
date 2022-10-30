/*
Objective
In this challenge, we practice calculating probability.

Task
There are 10 people about to sit down around a round table.
Find the probability that 2 particular people will sit next to one another.
*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *a, int *b)
{
	int t;
	t = *b;
	*b = *a;
	*a = t;
}

void
perm(int *s, size_t n, size_t l, int *p, int *q)
{
	size_t i, j, k;

	(*q)++;
	for (i = 0; i < n; i++) {
		if (s[i] == 0) {
			j = (i == 0) ? n - 1 : i - 1;
			k = (i == n - 1) ? 0 : i + 1;
			if (s[j] == 1 || s[k] == 1) {
				(*p)++;
				break;
			}
		}
	}

	for (i = l; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			swap(&s[i], &s[j]);
			perm(s, n, i + 1, p, q);
			swap(&s[i], &s[j]);
		}
	}
}

void
seat(void)
{
	int s[10], p, q;
	size_t i;

	for (i = 0; i < nelem(s); i++)
		s[i] = i;

	p = q = 0;
	perm(s, nelem(s), 0, &p, &q);
	printf("%d/%d\n", p, q);
}

int
main(void)
{
	seat();
	return 0;
}

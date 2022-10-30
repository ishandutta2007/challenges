/*

Students are asked to stand in non-decreasing order of heights for an annual photo.

Return the minimum number of students not standing in the right positions. 
(This is the number of students that must move in order for all students to be standing in non-decreasing order of height.)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

size_t
heightcheck(int *a, size_t n)
{
	size_t i, m;
	int *t;

	m = 0;
	t = malloc(sizeof(*a) * n);
	if (!t)
		return SIZE_MAX;

	memcpy(t, a, sizeof(*a) * n);
	qsort(t, n, sizeof(*t), cmp);
	for (i = 0; i < n; i++) {
		if (t[i] != a[i])
			m++;
	}

	free(t);
	return m;
}

int
main(void)
{
	int a[] = {1, 1, 4, 2, 1, 3};
	printf("%zu\n", heightcheck(a, nelem(a)));
	return 0;
}

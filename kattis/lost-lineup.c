/*

Jimmy and his friends were all standing in a lineup for ice cream when a huge gust blew them all around.
The friends want to keep things fair and make sure everyone gets their ice cream in the order they started with.
The friends do not remember the order, but each of them remember exactly how many people were between them and Jimmy.
Jimmy is always the first person in line. Can you help him and his friends remember the order?

Input

The first line contains a single integer n (1≤n≤100), the number of people in the line.

The second line contains n−1 space separated integers, where di (0≤di≤n−2) is the number of people between the (i+1)th person and Jimmy.

Jimmy is always first in the lineup.

Output

Print a single line with n integers, the people in the order of the original lineup. It is guaranteed that there is always a unique solution.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
lineup(size_t *a, size_t n, size_t *p)
{
	size_t i;

	p[0] = 1;
	for (i = 0; i < n; i++)
		p[a[i] + 1] = i + 2;
}

void
print(size_t *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%zu ", a[i]);
	printf("\n");
}

void
test(size_t *a, size_t n, size_t *r)
{
	size_t p[128];

	lineup(a, n, p);
	print(p, n + 1);
	assert(!memcmp(p, r, (n + 1) * sizeof(*r)));
}

int
main(void)
{
	size_t a1[] = {0};
	size_t r1[] = {1, 2};

	size_t a2[] = {1, 2, 0};
	size_t r2[] = {1, 4, 2, 3};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);

	return 0;
}

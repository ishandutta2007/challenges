/*

Winter has finally come to Chefland, so Chef bought a glove for herself. Chef has a hand with N fingers (for the sake of simplicity, let us consider the thumb a finger too) numbered 1 through N and the glove has N sheaths numbered 1 through N.
Exactly one finger has to be inserted into each sheath. You are given the lengths of Chef's fingers, as seen from left to right. You are also given the lengths of the sheaths of the glove, from left to right, as seen from the front.

Chef can wear the glove normally (the front side of the glove matching the front of Chef's hand), or she can flip the glove and then insert her hand in it.
In the first case, the first finger will go into the first sheath, the second finger into the second one, and so on.
However, when she flips the glove, her first finger will go into the N-th sheath, the second finger into the (N-1)-th and so on — the i-th finger will go into the N+1-i-th sheath for each valid i.
Of course, for her to wear the glove comfortably, each finger's length should be less than or equal to the length of the sheath it goes into.

Find out whether Chef can wear the glove by keeping its front side facing her, or if she can wear it by flipping it over and facing its back side.
If she can only wear the glove in the former way, output "front"; if she can wear it only in the latter way, output "back".
If both front and back orientations can be used, output "both", and if she can't wear it either way, output "none".

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the number of Chef's fingers.

The second line contains N space-separated integers L1, L2, ..., LN denoting the lengths of Chef's fingers.

The third line contains N space-separated integers G1, G2, ..., GN, denoting the lengths of sheaths of the glove.

Output

For each test case, print a single line containing one of the strings "front", "back", "both", or "none".

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
1 ≤ Li ≤ 10^9 for each valid i
1 ≤ Gi ≤ 10^9 for each valid i

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
side(int *a, int *b, size_t n, bool r)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		j = (r) ? n - i - 1 : i;
		if (a[j] < b[i])
			return 0;
	}
	return 1;
}

const char *
orientation(int *l, int *g, size_t n)
{
	int b, f;

	f = side(g, l, n, false);
	b = side(g, l, n, true);
	if (f && b)
		return "both";
	if (f)
		return "front";
	if (b)
		return "back";
	return "none";
}

void
test(int *l, int *g, size_t n, const char *r)
{
	const char *p;

	p = orientation(l, g, n);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	int l1[] = {1, 2, 3};
	int g1[] = {2, 3, 4};

	int l2[] = {1, 2, 1};
	int g2[] = {1, 2, 1};

	int l3[] = {3, 2, 1};
	int g3[] = {1, 2, 3};

	int l4[] = {1, 3, 2, 4};
	int g4[] = {1, 2, 3, 5};

	test(l1, g1, nelem(l1), "front");
	test(l2, g2, nelem(l2), "both");
	test(l3, g3, nelem(l3), "back");
	test(l4, g4, nelem(l4), "none");

	return 0;
}

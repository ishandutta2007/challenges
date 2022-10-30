/*

For NWERC 2018, the organisers have done something rather special with the balloons.
Instead of buying balloons of equal size, they bought one balloon of every integer size from 1 up to n.
A balloon of size s has a capacity of s decilitres.

To avoid inflating the balloons by hand, the organisers also bought n helium gas canisters.
Each canister can only be used to inflate one balloon, and must be emptied completely into that balloon (it is not possible to disconnect a canister from a balloon before the canister has been fully used).

Unfortunately the gas canisters were bought at a garage sale, and may contain differing amounts of helium. Some may even be empty!
To make the best of this challenging situation, the canisters will have to be paired with the balloons smartly.

The organisers want to assign all of the gas canisters to separate balloons, such that the balloon that is inflated the least (relative to its capacity) still contains the maximum possible fraction of helium inside.
What is the maximum such (minimum) fraction that is possible?

Balloons filled beyond their capacity will explode. Explosions are upsetting and must be avoided.

Input

The input consists of:

    One line with the integer n (1≤n≤2⋅105), the number of balloons and gas canisters.

One line with n integers c1,…,cn (0≤ci≤n for each i), the amounts of helium in the gas canisters, in decilitres.

Output

If it is possible to fill all the balloons without any exploding, output the maximum fraction f such that every balloon can be filled to at least f of its capacity. Otherwise, output “impossible”.

Your answer should have an absolute or relative error of at most 10^-6.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
cmp(const void *a, const void *b)
{
	unsigned x, y;

	x = *(unsigned *)a;
	y = *(unsigned *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

double
inflation(unsigned *a, size_t n)
{
	size_t i;
	double m;

	qsort(a, n, sizeof(*a), cmp);

	m = 1;
	for (i = 0; i < n; i++) {
		if (i + 1 < a[i])
			return -1;

		m = min(m, a[i] * 1.0 / (i + 1));
	}
	return m;
}

void
test(unsigned *a, size_t n, double r)
{
	double p;

	p = inflation(a, n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-6);
}

int
main(void)
{
	unsigned a1[] = {6, 1, 3, 2, 2, 3};
	unsigned a2[] = {2, 2};
	unsigned a3[] = {4, 0, 2, 1, 2};

	test(a1, nelem(a1), 0.6);
	test(a2, nelem(a2), -1);
	test(a3, nelem(a3), 0);

	return 0;
}

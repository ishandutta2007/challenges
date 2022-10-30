/*

Taken from: OEIS-A071816
Your task, given an upper bound of n, is to find the number of solutions that satisfy the equation:

a+b+c = x+y+z, where 0 <= a,b,c,x,y,z < n
The sequence starts out as described on the OEIS page, and as below (1-indexed):

1, 20, 141, 580, 1751, 4332, 9331, 18152, 32661, 55252, 88913, 137292, 204763, 296492, 418503, 577744, 782153, 1040724, 1363573, 1762004, 2248575, 2837164, 3543035, 4382904, 5375005, 6539156, 7896825, 9471196, 11287235, 13371756
For n = 1, there's only one solution: (0,0,0,0,0,0)

For n = 2, there are 20 ordered solutions (a,b,c,x,y,z) to a+b+c = x+y+z:

(0,0,0,0,0,0), (0,0,1,0,0,1), (0,0,1,0,1,0), (0,0,1,1,0,0), (0,1,0,0,0,1),
(0,1,0,0,1,0), (0,1,0,1,0,0), (0,1,1,0,1,1), (0,1,1,1,0,1), (0,1,1,1,1,0),
(1,0,0,0,0,1), (1,0,0,0,1,0), (1,0,0,1,0,0), (1,0,1,0,1,1), (1,0,1,1,0,1),
(1,0,1,1,1,0), (1,1,0,0,1,1), (1,1,0,1,0,1), (1,1,0,1,1,0), (1,1,1,1,1,1).
I & O
Input is a single integer denoting n.
Output is a single integer/string denoting f(n), where f(...) is the function above.
The indexing is exactly as described, no other indexing is acceptable.
This is code-golf, lowest byte-count wins.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// http://oeis.org/A071816
uvlong
seq(uvlong n)
{
	uvlong n2, n4;

	n2 = n * n;
	n4 = n2 * n2;
	return n * (11 * n4 + 5 * n2 + 4) / 20;
}

int
main(void)
{
	static const uvlong tab[] = {1ULL, 20ULL, 141ULL, 580ULL, 1751ULL, 4332ULL, 9331ULL, 18152ULL, 32661ULL, 55252ULL, 88913ULL, 137292ULL, 204763ULL, 296492ULL, 418503ULL, 577744ULL, 782153ULL, 1040724ULL, 1363573ULL, 1762004ULL, 2248575ULL, 2837164ULL, 3543035ULL, 4382904ULL, 5375005ULL, 6539156ULL, 7896825ULL, 9471196ULL, 11287235ULL, 13371756};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(seq(i + 1) == tab[i]);

	return 0;
}

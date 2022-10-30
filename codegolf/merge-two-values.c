/*

You have two values each of which is either 0 representing "unknown", or one of 1,2,3. Merge them into a single value as follows:

If both values are nonzero and equal, output that value:
(3,3) -> 3
If both values are nonzero but unequal, output 0 for unknown:
(1,2) -> 0
If one value is zero and the other is not, output the nonzero value:
(2,0) -> 2, (0,1) -> 1
If both values are zero, output zero:
(0,0) -> 0

Test cases:

There are 16 possible input pairs.

  | 0 1 2 3
--+--------
0 | 0 1 2 3
1 | 1 1 0 0
2 | 2 0 2 0
3 | 3 0 0 3

(0, 0) -> 0
(0, 1) -> 1
(0, 2) -> 2
(0, 3) -> 3
(1, 0) -> 1
(1, 1) -> 1
(1, 2) -> 0
(1, 3) -> 0
(2, 0) -> 2
(2, 1) -> 0
(2, 2) -> 2
(2, 3) -> 0
(3, 0) -> 3
(3, 1) -> 0
(3, 2) -> 0
(3, 3) -> 3

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
merge(int a, int b)
{
	if (a && b)
		return (a == b) ? a : 0;
	if (!a && b)
		return b;
	return a;
}

int
main(void)
{
	static const int tab[][3] = {
	    {0, 0, 0},
	    {0, 1, 1},
	    {0, 2, 2},
	    {0, 3, 3},
	    {1, 0, 1},
	    {1, 1, 1},
	    {1, 2, 0},
	    {1, 3, 0},
	    {2, 0, 2},
	    {2, 1, 0},
	    {2, 2, 2},
	    {2, 3, 0},
	    {3, 0, 3},
	    {3, 1, 0},
	    {3, 2, 0},
	    {3, 3, 3},
	};

	int a, b, c;
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		a = tab[i][0];
		b = tab[i][1];
		c = tab[i][2];
		printf("(%d, %d) -> %d\n", a, b, merge(a, b));
		assert(merge(a, b) == c);
	}

	return 0;
}

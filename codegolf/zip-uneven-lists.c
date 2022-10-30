/*

In this challenge you will take two lists as input and you will zip them. The zip can be defined with this recursive expression:

zip(a,b)= []                  a=[]
          [a0,zip(b,tail(a))] a≠[]

or this Haskell program if you would like:

zip [] _ = []
zip (x:xs) ys = x : zip ys xs
In simple terms you create a list which alternates between elements of the two input lists, starting with the first element of the first list, then the first element of the second list and so on, until one of the lists doesn't have the next element, then you stop.

For example if we zip [1,2,3,4,5] and [11,12,13] we get [1,11,2,12,3,13,4]. Every element appears in the output except 5, which is missing because the second list ran out before we reached it.

Task

As input you will take two lists of positive integers and output the result of zipping them as described above.
I use the term "first" and "second" when referring to the inputs, but you may take the two lists in the opposite order (although this choice must be consistent, you cannot e.g. swap the order of the inputs depending on what they are).

This is code-golf so the goal is to minimize your source code as scored in bytes.

Test cases
[] [] -> []
[] [1,2,3] -> []
[1,2,3] [] -> [1]
[1,2] [3] -> [1,3,2]
[1,2,3,4,5] [11, 12, 13] -> [1,11,2,12,3,13,4]
[9,9,9] [8,8,8] -> [9,8,9,8,9,8]
[1,2,3] [4,5,6,7] -> [1,4,2,5,3,6]

As a word of advice if your language has a built-in which solves the task try and solve the task without the builtin and post both solutions as a single answer.
It's more interesting to read solutions like that and it will almost certainly be more fun for you to golf.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
zip(int *a, int *b, size_t n, size_t m, int *c)
{
	size_t i, j, k, l;

	if (n == 0 || m == 0)
		return 0;

	i = j = k = 0;
	for (;;) {
		l = k & 1;
		if ((l && j >= m) || (!l && i >= n))
			break;

		c[k++] = (l) ? b[j++] : a[i++];
	}
	return k;
}

void
test(int *a, int *b, size_t n, size_t m, int *r, size_t nr)
{
	int p[128];
	size_t np;

	np = zip(a, b, n, m, p);
	assert(np == nr);
	if (nr)
		assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	int a1[] = {0};
	int b1[] = {0};

	int a2[] = {0};
	int b2[] = {1, 2, 3};

	int a3[] = {1, 2, 3};
	int b3[] = {0};

	int a4[] = {1, 2};
	int b4[] = {3};
	int r4[] = {1, 3, 2};

	int a5[] = {1, 2, 3, 4, 5};
	int b5[] = {11, 12, 13};
	int r5[] = {1, 11, 2, 12, 3, 13, 4};

	int a6[] = {9, 9, 9};
	int b6[] = {8, 8, 8};
	int r6[] = {9, 8, 9, 8, 9, 8};

	int a7[] = {1, 2, 3};
	int b7[] = {4, 5, 6, 7};
	int r7[] = {1, 4, 2, 5, 3, 6};

	test(a1, b1, 0, 0, NULL, 0);
	test(a2, b2, 0, nelem(b2), NULL, 0);
	test(a3, b3, nelem(a3), 0, NULL, 0);
	test(a4, b4, nelem(a4), nelem(b4), r4, nelem(r4));
	test(a5, b5, nelem(a5), nelem(b5), r5, nelem(r5));
	test(a6, b6, nelem(a6), nelem(b6), r6, nelem(r6));
	test(a7, b7, nelem(a7), nelem(b7), r7, nelem(r7));

	return 0;
}

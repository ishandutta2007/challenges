/*

Mr. Binary Counterman, son of Mr. Boolean Masker & Mrs. Even Oddify, follows in his parents’ footsteps and has a peculiar way of keeping track of the digits.

When given a list of booleans, he counts the 1s and 0s separately, numbering the 1s with the odds & the 0s with the evens.

For example, when he looks at 1 1 0 0 1 0 he counts: 1st odd, 2nd odd, 1st even, 2nd even, 3rd odd, 3rd even and copies it down as 1 3 2 4 5 6

Mr. Binary Counterman thinks it looks prettier to start counting odds at 1 and evens at 2. However the pattern is more symmetric if you start counting evens at 0. You may do either. So either 1 3 2 4 5 6 or 1 3 0 2 5 4 are good given the list above.

As input you may take any representation of a boolean list or binary number, the output should be the list of resulting numbers with any delimiter. (But the list elements should be separate & identifiable.)

This is code-golf, so least bytes wins.
Test Cases

1 0 1 0 1 0
1 2 3 4 5 6

1 1 1 1
1 3 5 7

0 0 0 0
2 4 6 8

0 1 1 0 0
2 1 3 4 6

0 1 1 0 0 1 0 1 1
2 1 3 4 6 5 8 7 9

0 0 1 0 0 1 1 1
2 4 1 6 8 3 5 7

0
2

1
1

1 1 1 0 0 0
1 3 5 2 4 6

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
count(int *a, size_t n, size_t *p)
{
	size_t i, j, k;

	j = 1;
	k = 2;
	for (i = 0; i < n; i++) {
		if (a[i] & 1) {
			p[i] = j;
			j += 2;
		} else {
			p[i] = k;
			k += 2;
		}
	}
}

void
print(size_t *p, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%zu ", p[i]);
	printf("\n");
}

void
test(int *a, size_t n, size_t *r)
{
	size_t p[128];

	count(a, n, p);
	print(p, n);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {1, 0, 1, 0, 1, 0};
	size_t r1[] = {1, 2, 3, 4, 5, 6};

	int a2[] = {1, 1, 1, 1};
	size_t r2[] = {1, 3, 5, 7};

	int a3[] = {0, 0, 0, 0};
	size_t r3[] = {2, 4, 6, 8};

	int a4[] = {0, 1, 1, 0, 0};
	size_t r4[] = {2, 1, 3, 4, 6};

	int a5[] = {0, 1, 1, 0, 0, 1, 0, 1, 1};
	size_t r5[] = {2, 1, 3, 4, 6, 5, 8, 7, 9};

	int a6[] = {0, 0, 1, 0, 0, 1, 1, 1};
	size_t r6[] = {2, 4, 1, 6, 8, 3, 5, 7};

	int a7[] = {0};
	size_t r7[] = {2};

	int a8[] = {1};
	size_t r8[] = {1};

	int a9[] = {1, 1, 1, 0, 0, 0};
	size_t r9[] = {1, 3, 5, 2, 4, 6};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);
	test(a6, nelem(a6), r6);
	test(a7, nelem(a7), r7);
	test(a8, nelem(a8), r8);
	test(a9, nelem(a9), r9);

	return 0;
}

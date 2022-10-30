/*

Given a list of non-negative integers, return whether or not that list is all the same number.

Rules

    Input and output can be taken/given in any reasonable and convenient format
    Truthy/Falsey values can be represented as any value of your choice as long as it's reasonable and relatively consistent (e.g. 1 for falsey and >= 2 for truthy is fine)
    There will always be at least 1 item in the input list
    The list items are guaranteed to be in the range [0, 9] (0≤n≤9

    )
    Standard loopholes apply

This is code golf, so the shortest program in each language wins. I've made a community wiki answer for trivial answers, so feel free to submit potentially longer programs.
Test Cases

[1, 1, 1, 1, 1, 1, 1] -> True
[1, 2, 3, 4] -> False
[6, 9, 6, 9, 6] -> False
[6] -> True
[7, 7] -> True
[4, 2, 0] -> False


*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
same(int *a, size_t n)
{
	size_t i;

	for (i = 1; i < n; i++) {
		if (a[i] != a[i - 1])
			return false;
	}
	return true;
}

int
main(void)
{
	int a1[] = {1, 1, 1, 1, 1, 1, 1};
	int a2[] = {1, 2, 3, 4};
	int a3[] = {6, 9, 6, 9, 6};
	int a4[] = {6};
	int a5[] = {7, 7};
	int a6[] = {4, 2, 0};

	assert(same(a1, nelem(a1)) == true);
	assert(same(a2, nelem(a2)) == false);
	assert(same(a3, nelem(a3)) == false);
	assert(same(a4, nelem(a4)) == true);
	assert(same(a5, nelem(a5)) == true);
	assert(same(a6, nelem(a6)) == false);

	return 0;
}

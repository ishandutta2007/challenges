/*

An array is special, if every even index contains an even number and every odd index contains an odd number.
Create a function that returns true if an array is special, and false otherwise.
Examples

isSpecialArray([2, 7, 4, 9, 6, 1, 6, 3]) ➞ true
// Even indices: [2, 4, 6, 6]; Odd indices: [7, 9, 1, 3]

isSpecialArray([2, 7, 9, 1, 6, 1, 6, 3]) ➞ false
// Index 2 has an odd number 9.

isSpecialArray([2, 7, 8, 8, 6, 1, 6, 3]) ➞ false
// Index 3 has an even number 8.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
isspecialarray(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (!((i & 1) == (a[i] & 1)))
			return 0;
	}
	return 1;
}

int
main(void)
{
	int a1[] = { 2, 7, 4, 9, 6, 1, 6, 3 };
	int a2[] = { 2, 7, 9, 1, 6, 1, 6, 3 };
	int a3[] = { 2, 7, 8, 8, 6, 1, 6, 3 };
	int a4[] = { 1, 1, 1, 2 };
	int a5[] = { 2, 2, 2, 2 };
	int a6[] = { 2, 1, 2, 1 };
	int a7[] = { 4, 5, 6, 7 };
	int a8[] = { 4, 5, 6, 7, 0, 5 };

	assert(isspecialarray(a1, nelem(a1)) == 1);
	assert(isspecialarray(a2, nelem(a2)) == 0);
	assert(isspecialarray(a3, nelem(a3)) == 0);
	assert(isspecialarray(a4, nelem(a4)) == 0);
	assert(isspecialarray(a5, nelem(a5)) == 0);
	assert(isspecialarray(a6, nelem(a6)) == 1);
	assert(isspecialarray(a7, nelem(a7)) == 1);
	assert(isspecialarray(a8, nelem(a8)) == 1);

	return 0;
}

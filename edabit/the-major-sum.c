/*

Create a function that takes an integer array and return the biggest between positive sum, negative sum, or 0s count.
The major is understood as the greatest absolute.

arr = [1,2,3,4,0,0,-3,-2], the function has to return 10, because:

    Positive sum = 1+2+3+4 = 10
    Negative sum = (-3)+(-2) = -5
    0s count = 2 (there are two zeros in array)

Examples

majorSum([1, 2, 3, 4, 0, 0, -3, -2]) ➞ 10

majorSum([-4, -8, -12, -3, 4, 7, 1, 3, 0, 0, 0, 0]) ➞ -27

majorSum([0, 0, 0, 0, 0, 1, 2, -3]) ➞ 5
// Because -3 < 1+2 < 0sCount = 5

Notes

    All numbers are integers.
    There aren't empty arrays.
    All tests are made to return only one value.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
majorsum(int *a, size_t n)
{
	int x, y, z, m;
	size_t i;

	x = y = z = 0;
	for (i = 0; i < n; i++) {
		if (a[i] < 0)
			x += a[i];
		else if (a[i] > 0)
			y += a[i];
		else if (a[i] == 0)
			z += 1;
	}

	m = max(y, z);
	if (-m > x)
		m = x;
	return m;
}

int
main(void)
{
	int a1[] = {1, 2, 3, 4, 0, 0, -3, -2};
	int a2[] = {-4, -8, -12, -3, 4, 7, 1, 3, 0, 0, 0, 0};
	int a3[] = {0, 0, 0, 0, 0, 1, 2, -3};
	int a4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int a5[] = {0};
	int a6[] = {1};
	int a7[] = {-1};
	int a8[] = {10, -12, 4, 0, -3, -7, -91, 45};
	int a9[] = {0, 1, 0, 1, 0, 1, 0, 1, 0};
	int a10[] = {-1, -1, -1, -1, -1, 1, 1, 1, 1, 0, 0, 0, 0};
	int a11[] = {1, 2, 3, 4, -5, -4, -3, -2, -1, 0};
	int a12[] = {0, 1, -2};
	int a13[] = {2, 0, -1};
	int a14[] = {2, 0, 0, 0, -1};
	int a15[] = {2, 0, 0, 0, 0, -1};

	assert(majorsum(a1, nelem(a1)) == 10);
	assert(majorsum(a2, nelem(a2)) == -27);
	assert(majorsum(a3, nelem(a3)) == 5);
	assert(majorsum(a4, nelem(a4)) == 11);
	assert(majorsum(a5, nelem(a5)) == 1);
	assert(majorsum(a6, nelem(a6)) == 1);
	assert(majorsum(a7, nelem(a7)) == -1);
	assert(majorsum(a8, nelem(a8)) == -113);
	assert(majorsum(a9, nelem(a9)) == 5);
	assert(majorsum(a10, nelem(a10)) == -5);
	assert(majorsum(a11, nelem(a11)) == -15);
	assert(majorsum(a12, nelem(a12)) == -2);
	assert(majorsum(a13, nelem(a13)) == 2);
	assert(majorsum(a14, nelem(a14)) == 3);
	assert(majorsum(a15, nelem(a15)) == 4);

	return 0;
}

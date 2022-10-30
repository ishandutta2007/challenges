/*

Given a list of 10 numbers, return whether or not the list is shuffled sufficiently enough.
In this case, if 3 or more numbers appear consecutively (ascending or descending), return False.

Notes

    Only steps of 1 in either direction count as consecutive
    (i.e. a sequence of odd and even numbers would count as being properly shuffled (see example #4)).
    You will get numbers from 1-10.

*/

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
isshuffledwell(int *a, size_t n)
{
	size_t i;

	if (n < 3)
		return false;

	for (i = 0; i < n - 3; i++) {
		if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2])
			return false;
		if (a[i] - 1 == a[i + 1] && a[i + 1] - 1 == a[i + 2])
			return false;
	}
	return true;
}

int
main(void)
{
	int a1[] = {1, 2, 3, 5, 8, 6, 9, 10, 7, 4};
	int a2[] = {3, 5, 1, 9, 8, 7, 6, 4, 2, 10};
	int a3[] = {1, 5, 3, 8, 10, 2, 7, 6, 4, 9};
	int a4[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	int a5[] = {5, 6, 7, 9, 1, 10, 3, 8, 2, 4};
	int a6[] = {3, 9, 7, 5, 2, 4, 10, 1, 8, 6};
	int a7[] = {6, 4, 2, 1, 3, 7, 8, 10, 5, 9};
	int a8[] = {2, 6, 10, 9, 8, 1, 4, 7, 3, 5};
	int a9[] = {6, 10, 5, 8, 4, 2, 7, 9, 3, 1};
	int a10[] = {3, 10, 5, 2, 6, 9, 8, 4, 1, 7};
	int a11[] = {10, 7, 9, 5, 4, 6, 3, 8, 2, 1};
	int a12[] = {3, 5, 9, 6, 10, 1, 4, 8, 7, 2};
	int a13[] = {10, 7, 8, 4, 3, 9, 5, 1, 2, 6};
	int a14[] = {2, 4, 8, 7, 3, 9, 1, 10, 6, 5};
	int a15[] = {9, 6, 1, 3, 10, 8, 5, 4, 7, 2};
	int a16[] = {2, 3, 9, 7, 10, 8, 4, 6, 1, 5};
	int a17[] = {3, 8, 5, 6, 2, 7, 4, 1, 10, 9};
	int a18[] = {1, 6, 4, 10, 3, 5, 7, 2, 9, 8};
	int a19[] = {1, 10, 8, 9, 2, 3, 4, 7, 5, 6};
	int a20[] = {5, 4, 3, 10, 9, 2, 7, 6, 8, 1};
	int a21[] = {4, 7, 8, 3, 5, 9, 2, 6, 1, 10};
	int a22[] = {5, 8, 6, 7, 3, 2, 4, 9, 10, 1};
	int a23[] = {3, 7, 1, 4, 8, 6, 5, 9, 10, 2};
	int a24[] = {10, 1, 9, 4, 3, 2, 7, 8, 6, 5};
	int a25[] = {3, 2, 6, 4, 1, 5, 8, 10, 9, 7};
	int a26[] = {1, 7, 8, 5, 9, 10, 4, 6, 2, 3};
	int a27[] = {2, 3, 9, 7, 5, 6, 8, 1, 10, 4};
	int a28[] = {1, 9, 3, 4, 6, 2, 10, 8, 7, 5};
	int a29[] = {1, 7, 8, 5, 10, 9, 6, 4, 2, 3};
	int a30[] = {2, 9, 10, 3, 5, 7, 6, 4, 8, 1};
	int a31[] = {6, 3, 10, 8, 5, 2, 1, 9, 7, 4};
	int a32[] = {6, 8, 7, 3, 4, 9, 5, 10, 1, 2};
	int a33[] = {8, 4, 9, 5, 6, 3, 1, 10, 7, 2};

	assert(isshuffledwell(a1, nelem(a1)) == false);
	assert(isshuffledwell(a2, nelem(a2)) == false);
	assert(isshuffledwell(a3, nelem(a3)) == true);
	assert(isshuffledwell(a4, nelem(a4)) == true);
	assert(isshuffledwell(a5, nelem(a5)) == false);
	assert(isshuffledwell(a6, nelem(a6)) == true);
	assert(isshuffledwell(a7, nelem(a7)) == true);
	assert(isshuffledwell(a8, nelem(a8)) == false);
	assert(isshuffledwell(a9, nelem(a9)) == true);
	assert(isshuffledwell(a10, nelem(a10)) == true);
	assert(isshuffledwell(a11, nelem(a11)) == true);
	assert(isshuffledwell(a12, nelem(a12)) == true);
	assert(isshuffledwell(a13, nelem(a13)) == true);
	assert(isshuffledwell(a14, nelem(a14)) == true);
	assert(isshuffledwell(a15, nelem(a15)) == true);
	assert(isshuffledwell(a16, nelem(a16)) == true);
	assert(isshuffledwell(a17, nelem(a17)) == true);
	assert(isshuffledwell(a18, nelem(a18)) == true);
	assert(isshuffledwell(a19, nelem(a19)) == false);
	assert(isshuffledwell(a20, nelem(a20)) == false);
	assert(isshuffledwell(a21, nelem(a21)) == true);
	assert(isshuffledwell(a22, nelem(a22)) == true);
	assert(isshuffledwell(a23, nelem(a23)) == true);
	assert(isshuffledwell(a24, nelem(a24)) == false);
	assert(isshuffledwell(a25, nelem(a25)) == true);
	assert(isshuffledwell(a27, nelem(a26)) == true);
	assert(isshuffledwell(a27, nelem(a27)) == true);
	assert(isshuffledwell(a28, nelem(a28)) == true);
	assert(isshuffledwell(a29, nelem(a29)) == true);
	assert(isshuffledwell(a30, nelem(a30)) == true);
	assert(isshuffledwell(a31, nelem(a31)) == true);
	assert(isshuffledwell(a32, nelem(a32)) == true);
	assert(isshuffledwell(a33, nelem(a33)) == true);

	return 0;
}

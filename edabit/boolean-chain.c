/*

Write three functions:

    boolean_and
    boolean_or
    boolean_xor

These functions should evaluate a list of True and False values, starting from the leftmost element and evaluating pairwise.

Notes

    XOR is the same as OR, except that it excludes [True, True].
    Each time you evaluate an element at 0 and at 1, you collapse it into the single result.

*/

#include <stdio.h>
#include <stdbool.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
band(bool *a, size_t n)
{
	bool v;
	size_t i;

	if (n == 0)
		return false;

	v = a[0];
	for (i = 1; i < n; i++)
		v &= a[i];
	return v;
}

bool
bor(bool *a, size_t n)
{
	bool v;
	size_t i;

	if (n == 0)
		return false;

	v = a[0];
	for (i = 1; i < n; i++)
		v |= a[i];
	return v;
}

bool
bxor(bool *a, size_t n)
{
	bool v;
	size_t i;

	if (n == 0)
		return false;

	v = a[0];
	for (i = 1; i < n; i++)
		v ^= a[i];
	return v;
}

int
main(void)
{
	bool b1[] = {true, true, false, true};
	bool b2[] = {true, true, true, true};
	bool b3[] = {false, true, true, true};
	bool b4[] = {false, false, false, false};
	bool b5[] = {false, false, true, true};

	bool b6[] = {true, true, false, false};
	bool b7[] = {true, false, false, false};
	bool b8[] = {false, false, false, true, false};
	bool b9[] = {false, true, false, true, false, true};
	bool b10[] = {false, false, false, false, false};

	bool b11[] = {true, true, false, true};
	bool b12[] = {true, true, false, false};
	bool b13[] = {true, false, false, false};
	bool b14[] = {true, false, true, false};
	bool b15[] = {true, true, true, true};
	bool b16[] = {false, false, false, false};
	bool b17[] = {false, false, false, true};
	bool b18[] = {true, false, false, true};

	printf("%d\n", band(b1, nelem(b1)));
	printf("%d\n", band(b2, nelem(b2)));
	printf("%d\n", band(b3, nelem(b3)));
	printf("%d\n", band(b4, nelem(b4)));
	printf("%d\n", band(b5, nelem(b5)));

	printf("%d\n", bor(b6, nelem(b6)));
	printf("%d\n", bor(b7, nelem(b7)));
	printf("%d\n", bor(b8, nelem(b8)));
	printf("%d\n", bor(b9, nelem(b9)));
	printf("%d\n", bor(b10, nelem(b10)));

	printf("%d\n", bxor(b11, nelem(b11)));
	printf("%d\n", bxor(b12, nelem(b12)));
	printf("%d\n", bxor(b13, nelem(b13)));
	printf("%d\n", bxor(b14, nelem(b14)));
	printf("%d\n", bxor(b15, nelem(b15)));
	printf("%d\n", bxor(b16, nelem(b16)));
	printf("%d\n", bxor(b17, nelem(b17)));
	printf("%d\n", bxor(b18, nelem(b18)));

	return 0;
}

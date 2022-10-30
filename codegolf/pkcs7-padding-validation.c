/*

In cryptography, PKCS#7 padding is a padding scheme which adds a number of bytes N ≥ 1, where the value of each added byte is equal to N.

For example, Hello, World!, which has 13 bytes, is the following in hex:

48 65 6C 6C 6F 2C 20 57 6F 72 6C 64 21
If we choose to PKCS#7 pad to length 16, then the result is:

48 65 6C 6C 6F 2C 20 57 6F 72 6C 64 21 03 03 03
And if we choose to pad to length 20, then the result is:

48 65 6C 6C 6F 2C 20 57 6F 72 6C 64 21 07 07 07 07 07 07 07
Note that in the first example we add three 03 bytes, and in the second we add seven 07 bytes.

Your task will be to validate whether a string (or integer array) has correct PKCS#7 padding. That is, if the last byte of the input string is N, then your program should check that the last N bytes of the string are equal to N.

Input
A single nonempty ASCII string containing characters between code points 1 and 127 inclusive. If you wish, you may take input as an array of integers instead.

Output
A truthy value if the input string has valid PKCS#7 padding, otherwise a falsy value.

Both functions and full programs are acceptable. This is code-golf, so the aim is to minimise the number of bytes in your code.

Test cases
The integer array version of inputs is presented here — the string version would have unprintable characters for many of the following test cases:

Truthy:

[1]
[1, 1]
[2, 1]
[2, 2]
[5, 6, 5, 3, 3, 3]
[1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2]
[95, 115, 80, 32, 71, 7, 122, 49, 13, 7, 7, 7, 7, 7, 7, 7, 7]
[27, 33, 54, 65, 97, 33, 52, 55, 60, 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]
[15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15]
Falsy:

[2]
[1, 2]
[5, 5, 5, 5]
[5, 6, 5, 4, 4, 4]
[3, 3, 3, 94, 3, 3]
[1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2]
[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 127]
[50, 39, 94, 105, 49, 29, 74, 102, 2, 106, 44, 7, 7, 7, 7, 7, 7]
[26, 27, 59, 25, 122, 110, 20, 30, 114, 6, 9, 62, 121, 42, 22, 60, 33, 12]

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
valid(unsigned *a, size_t n)
{
	unsigned i, p;

	if (n == 0)
		return true;

	p = a[n - 1];
	for (i = 0; i < p; i++) {
		if (i > n - 1 || p != a[n - i - 1])
			return false;
	}
	return true;
}

int
main(void)
{
	unsigned a1[] = {1};
	unsigned a2[] = {1, 1};
	unsigned a3[] = {2, 1};
	unsigned a4[] = {2, 2};
	unsigned a5[] = {5, 6, 5, 3, 3, 3};
	unsigned a6[] = {1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2};
	unsigned a7[] = {95, 115, 80, 32, 71, 7, 122, 49, 13, 7, 7, 7, 7, 7, 7, 7, 7};
	unsigned a8[] = {27, 33, 54, 65, 97, 33, 52, 55, 60, 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	unsigned a9[] = {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15};

	unsigned a10[] = {2};
	unsigned a11[] = {1, 2};
	unsigned a12[] = {5, 5, 5, 5};
	unsigned a13[] = {5, 6, 5, 4, 4, 4};
	unsigned a14[] = {3, 3, 3, 94, 3, 3};
	unsigned a15[] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
	unsigned a16[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 127};
	unsigned a17[] = {50, 39, 94, 105, 49, 29, 74, 102, 2, 106, 44, 7, 7, 7, 7, 7, 7};
	unsigned a18[] = {26, 27, 59, 25, 122, 110, 20, 30, 114, 6, 9, 62, 121, 42, 22, 60, 33, 12};

	assert(valid(a1, nelem(a1)) == true);
	assert(valid(a2, nelem(a2)) == true);
	assert(valid(a3, nelem(a3)) == true);
	assert(valid(a4, nelem(a4)) == true);
	assert(valid(a5, nelem(a5)) == true);
	assert(valid(a6, nelem(a6)) == true);
	assert(valid(a7, nelem(a7)) == true);
	assert(valid(a8, nelem(a8)) == true);
	assert(valid(a9, nelem(a9)) == true);

	assert(valid(a10, nelem(a10)) == false);
	assert(valid(a11, nelem(a11)) == false);
	assert(valid(a12, nelem(a12)) == false);
	assert(valid(a13, nelem(a13)) == false);
	assert(valid(a14, nelem(a14)) == false);
	assert(valid(a15, nelem(a15)) == false);
	assert(valid(a16, nelem(a16)) == false);
	assert(valid(a17, nelem(a17)) == false);
	assert(valid(a18, nelem(a18)) == false);

	return 0;
}
